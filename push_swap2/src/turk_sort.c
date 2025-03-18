/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:41:52 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/18 14:54:35 by tomasklaus       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

/*
- push two top numbers from stack_a (pb,pb)
- calculate the cost of moves
    - take each number from stack_a and calculate how many moves
    it would take for it to be on top (by ra or rra) and store the two values
    - decide where the number needs to go in stack_b (which number to get on top of b)
        - if its going to be the biggest or the lowest number in stack_b,
        i need to rotate stack_b till the current biggest is on top
        - if its going to be somewhere in the middle,
        i need to rotate stack_b till the second lowest from the num is on top
    - calculate how many moves it will take to get the right number on top of (by ra or rra) and store the two values
    - compare the costs
        - if both distances are positive or both negative -> ft_abs(dist_a - dist_b) + min(dist_a, dist_b)
        - if they have different znaminko -> ft_abs(dist_a) + ft_abs(dist_b)
    - get the cost for each number in stack_a and choose the cheapest
    - return the number i want to push
- execute the correct moves
    - take the number
    - decide where the number needs to go in stack_b (which number to get on top of b)
        - if its going to be the biggest or the lowest number in stack_b,
        i need to rotate stack_b till the current biggest is on top
        - if its going to be somewhere in the middle,
        i need to rotate stack_b till the second lowest from the num is on top
    - calculate how many moves it will take to get the right number on top of (by ra or rra) and store the two values
    - compare the costs
        - if both distances are positive or both negative -> ft_abs(dist_a - dist_b) + (max(ft_abs(dist_a), ft_abs(dist_b))min(ft_abs(dist_a), ft_abs(dist_b)))
        - if they have different znaminko -> ft_abs(dist_a) + ft_abs(dist_b)
    - take the lower cost
    - rotate
        - if both distances are positive -> r * min(ft_abs(dist_a), ft_abs(dist_b)), ra || rb * ft_abs(dist_a - dist_b)
        - if both negative -> rr * min(ft_abs(dist_a), ft_abs(dist_b)), rra || rrb * ft_abs(dist_a - dist_b)
        - if they have different znaminko -> rotate distance(stack_a, num_a), rotate_distance(stack_b, num_b)
- push b and repeat till there are 3 nums in stack_a
- sort3 stack_a
- push back to stack_a till *stack_b != NULL
    - take the number from top of stack_b
    - find the next higher to it in stack_a
    - rotate_distance(stack_a, next_higher)
    - pa
- rotate_distance(stack_a, 0)
*/

void get_both_distances(t_list **stack, int value, int *r_dist, int *rr_dist)
{
    t_list *first;
    int dist;
    int size;

    size = ft_lstsize(first);
    dist = 0;
    first = *stack;

    while (first && (first->content != value))
    {
        first = first->next;
        dist++;
    }
    if (!first)
        return size;
    r_dist = dist;
    rr_dist = dist - size;
}

int get_min(t_list *stack)
{
    int lowest;

    if (!stack)
        return (0); // or some error value

    lowest = stack->content;
    while (stack)
    {
        if (stack->content < lowest)
            lowest = stack->content;
        stack = stack->next;
    }
    return (lowest);
}

int get_max(t_list *stack)
{
    int highest;

    if (!stack)
        return (0); // or some error value

    highest = stack->content;
    while (stack)
    {
        if (stack->content > highest)
            highest = stack->content;
        stack = stack->next;
    }
    return (highest);
}

int get_next_lowest(t_list *stack, int num)
{
    int second_lowest;
    int lowest;

    lowest = get_min(stack);
    second_lowest = get_max(stack);

    while (stack)
    {
        if (stack->content > lowest && stack->content < num && stack->content < second_lowest)
            second_lowest = stack->content;
        stack = stack->next;
    }
    return (second_lowest);
}

void b_cost(t_list **stack_b, int num_a, int *r_dist, int *rr_dist)
{
    t_list *first_b;
    int size_b;

    size_b = ft_lstsize(first_b);
    if ((num_a < get_min(first_b)) || (num_a > get_max(first_b)))
        get_both_distances(stack_b, get_max(first_b), &r_dist, &rr_dist);
    else
        get_both_distances(stack_b, get_next_lowest(first_b, num_a), &r_dist, &rr_dist);
}

int ft_min(int a, int b)
{
    return (a < b) ? a : b;
}
int cost_compute(int *i, int *j)
{
    if ((*i >= 0 && *j >= 0) || (*i < 0 && *j < 0))
        return ft_abs(*i - *j) + ft_min(ft_abs(*i), ft_abs(*j));
    else
        return ft_abs(*i) + ft_abs(*j);
}

int compare_costs(int *ra_moves_a, int *rb_moves_b, int *rrb_moves_b, int size_a)
{
    int rra_moves_a;
    rra_moves_a = ra_moves_a - size_a;

    int cost;
    int min_cost;

    cost = size_a;

    if (cost_compute(&ra_moves_a, &rb_moves_b) < cost)
        cost = cost_compute(&ra_moves_a, &rb_moves_b);
    if (cost_compute(&ra_moves_a, &rrb_moves_b) < cost)
        cost = cost_compute(&ra_moves_a, &rrb_moves_b);
    if (cost_compute(&rra_moves_a, &rb_moves_b) < cost)
        cost = cost_compute(&rra_moves_a, &rb_moves_b);
    if (cost_compute(&rra_moves_a, &rrb_moves_b) < cost)
        cost = cost_compute(&rra_moves_a, &rrb_moves_b);

    /* if ((ra_moves_a >= 0 && rb_moves_b >= 0) || (ra_moves_a < 0 && rb_moves_b < 0))
        cost = ft_abs(ra_moves_a - rb_moves_b) + ft_min(ft_abs(ra_moves_a), ft_abs(rb_moves_b));
    else
        cost = ft_abs(ra_moves_a) + ft_abs(rb_moves_b);

    if ((ra_moves_a >= 0 && rrb_moves_b >= 0) || (ra_moves_a < 0 && rrb_moves_b < 0))
        cost = ft_min(cost, ft_abs(ra_moves_a - rrb_moves_b) + ft_min(ft_abs(ra_moves_a), ft_abs(rrb_moves_b)));
    else
        cost = ft_min(cost, ft_abs(ra_moves_a) + ft_abs(rrb_moves_b)); */

    return cost;
}

int calculate_cost(t_list **stack_a, t_list **stack_b, int size_a)
{
    int ra_moves_a;
    int rb_moves_b;
    int rrb_moves_b;
    int num;
    int cost;

    cost = size_a;
    ra_moves_a = 0;
    num = 0;

    while (*stack_a)
    {
        b_cost(stack_b, (*stack_a)->content, &rb_moves_b, &rrb_moves_b);
        if (compare_costs(ra_moves_a, rb_moves_b, rrb_moves_b, size_a) < cost)
            num = (*stack_a)->content;
        (*stack_a) = (*stack_a)->next;
        ra_moves_a++;
    }
    return num;
}
int which_case(int *ra_moves_a, int *rra_moves_a, int *rb_moves_b, int *rrb_moves_b)
{
    int cost;
    int case_which;

    case_which = 0;
    cost = INT_MAX;
    if (cost_compute(&ra_moves_a, &rb_moves_b) < cost)
    {
        cost = cost_compute(&ra_moves_a, &rb_moves_b);
        case_which = 1;
    }
    if (cost_compute(&ra_moves_a, &rrb_moves_b) < cost)
    {
        cost = cost_compute(&ra_moves_a, &rrb_moves_b);
        case_which = 2;
    }
    if (cost_compute(&rra_moves_a, &rb_moves_b) < cost)
    {
        cost = cost_compute(&rra_moves_a, &rb_moves_b);
        case_which = 3;
    }
    if (cost_compute(&rra_moves_a, &rrb_moves_b) < cost)
        case_which = 4;
    return case_which;
}
int rotate_moves(int *ra_moves_a, int *rra_moves_a, int *rb_moves_b, int *rrb_moves_b)
{
    int case_which;
    int r_times;
    case_which = which_case(ra_moves_a, rra_moves_a, rb_moves_b, rrb_moves_b);

    if (case_which == 1)
        r_times = ft_min(ft_abs(*ra_moves_a), ft_abs(*rb_moves_b));
    else if (case_which == 4)
        r_times = min(ft_abs(*rra_moves_a), ft_abs(*rrb_moves_b)) * -1;
    else
        r_times = INT_MAX;
    return r_times;
}

void rotate_final(t_list **stack_a, t_list **stack_b, int r_times)
{
    while (r_times > 0)
    {
        rr(stack_a, stack_b);
        r_times--;
    }
    while (r_times < 0)
    {
        rrr(stack_a, stack_b);
        r_times++;
    }
}
void execute_moves(t_list **stack_a, t_list **stack_b, int size_a, int num_a)
{
    int ra_moves_a;
    int rb_moves_b;
    int rrb_moves_b;
    int rra_moves_a;
    int num_b;

    int r_times;

    rra_moves_a = ra_moves_a - size_a;
    ra_moves_a = 0;
    while ((*stack_a)->content != num_a)
    {
        ra_moves_a++;
        (*stack_a) = (*stack_a)->next;
    }
    if ((num_a < get_min(*stack_b)) || (num_a > get_max(*stack_a)))
        num_b = get_max(*stack_b);
    else
        num_b = get_next_lowest(stack_b, num_a);

    b_cost(stack_b, num_a, &rb_moves_b, &rrb_moves_b);
    r_times = rotate_moves(ra_moves_a, rra_moves_a, rb_moves_b, rrb_moves_b);
    rotate_final(stack_a, stack_b, r_times)
}

void turk_sort(t_list **stack_a, t_list **stack_b, int full_size)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);

    int num;
    num = 0;

    while (stack_b)
    {
        num = calculate_cost(stack_a, stack_b, full_size);
        execute_moves(stack_a, stack_b, full_size, num);
        full_size--;
    }
}
