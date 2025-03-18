/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomasklaus <tomasklaus@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:41:52 by tomasklaus        #+#    #+#             */
/*   Updated: 2025/03/18 16:59:31 by tomasklaus       ###   ########.fr       */
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

int get_max(t_list **stack)
{
    int highest;
    t_list *current;

    if (!*stack)
        return (0); // or some error value

    current = *stack;
    highest = current->content;
    while (current)
    {
        if (current->content > highest)
            highest = current->content;
        current = current->next;
    }
    return (highest);
}

int get_next_lowest(t_list **stack, int num)
{
    int second_lowest;
    int lowest;
    t_list *current;

    current = *stack;
    lowest = get_min(stack);
    second_lowest = get_max(stack);

    while (current)
    {
        if (current->content > lowest && current->content < num && current->content < second_lowest)
            second_lowest = current->content;
        current = current->next;
    }
    return (second_lowest);
}

int get_next_higher(t_list *stack, int num)
{
    int next_higher;
    int max;

    max = get_max(stack);
    next_higher = max;

    while (stack)
    {
        if (stack->content > num && stack->content < next_higher)
            next_higher = stack->content;
        stack = stack->next;
    }
    return (next_higher == max) ? num : next_higher;
}

void b_cost(t_list **stack_b, int num_a, int *moves)
{
    int size_b;

    size_b = ft_lstsize(stack_b);
    if ((num_a < get_min(stack_b)) || (num_a > get_max(stack_b)))
        get_both_distances(stack_b, get_max(stack_b), moves[2], moves[3]);
    else
        get_both_distances(stack_b, get_next_lowest(stack_b, num_a), moves[2], moves[3]);
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

int compare_costs(int *moves, int size_a)
{

    moves[1] = moves[0] - size_a;

    int cost;

    cost = size_a;

    if (cost_compute(moves[0], moves[2]) < cost)
        cost = cost_compute(moves[0], moves[2]);
    if (cost_compute(moves[0], moves[3]) < cost)
        cost = cost_compute(moves[0], moves[3]);
    if (cost_compute(moves[1], moves[2]) < cost)
        cost = cost_compute(moves[1], moves[2]);
    if (cost_compute(moves[1], moves[3]) < cost)
        cost = cost_compute(moves[1], moves[3]);

    return cost;
}

int calculate_cost(t_list **stack_a, t_list **stack_b, int size_a, int *moves)
{
    int num;
    int cost;

    cost = size_a;

    num = 0;

    while (*stack_a)
    {
        b_cost(stack_b, (*stack_a)->content, moves);
        if (compare_costs(moves, size_a) < cost)
            num = (*stack_a)->content;
        (*stack_a) = (*stack_a)->next;
        moves[0]++;
    }
    return num;
}
int which_case(int *moves)
{
    int cost;
    int case_which;

    case_which = 0;
    cost = INT_MAX;
    if (cost_compute(moves[0], moves[2]) < cost)
    {
        cost = cost_compute(moves[0], moves[2]);
        case_which = 1;
    }
    if (cost_compute(moves[0], moves[3]) < cost)
    {
        cost = cost_compute(moves[0], moves[3]);
        case_which = 2;
    }
    if (cost_compute(moves[1], moves[2]) < cost)
    {
        cost = cost_compute(moves[1], moves[2]);
        case_which = 3;
    }
    if (cost_compute(moves[1], moves[3]) < cost)
        case_which = 4;
    return case_which;
}

void rotate_final(t_list **stack_a, t_list **stack_b, int *moves, int r_times)
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
int rotate_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
    int case_which;
    int r_times;
    int size_a;
    int size_b;
    case_which = which_case(moves);

    size_a = ft_lstsize(stack_a);
    size_b = ft_lstsize(stack_b);

    if (case_which == 1)
    {
        r_times = ft_min(ft_abs(moves[0]), ft_abs(moves[2]));
        rotate_final(stack_a, stack_b, r_times, moves);
    }
    else if (case_which == 4)
    {
        r_times = min(ft_abs(moves[1]), ft_abs(moves[3])) * -1;
    }
    rotate_distance(stack_a, num[0], 1);
    rotate_distance(stack_b, num[1], 0);
    return r_times;
}

void execute_moves(t_list **stack_a, t_list **stack_b, int *moves, int *num)
{
    int r_times;

    moves[1] = moves[0] - ft_lstsize(stack_a);

    while ((*stack_a)->content != num[0])
    {
        moves[0]++;
        (*stack_a) = (*stack_a)->next;
    }
    if ((num[0] < get_min(*stack_b)) || (num[0] > get_max(*stack_a)))
        num[1] = get_max(*stack_b);
    else
        num[1] = get_next_lowest(stack_b, num[0]);

    b_cost(stack_b, num[0], moves);
    r_times = rotate_moves(stack_a, stack_b, moves, num);
    pb(stack_a, stack_b);
}
push_back_to_b(t_list **stack_a, t_list **stack_b)
{
    t_list *first_b;
    first_b = stack_b;

    int first;
    int num;
    while (*stack_a)
    {
        first = (*stack_b)->content;
        num = get_next_higher(stack_b, first);
        rotate_distance(stack_b, num, 1);
        pa(stack_a,stack_b);
    }
}

/*
moves[0] = ra
moves[1] = rra
moves[2] = rb
moves[3] = rrb
*/
void turk_sort(t_list **stack_a, t_list **stack_b, int full_size)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);

    int *moves[4];
    moves[0] = 0;
    moves[1] = 0;
    moves[2] = 0;
    moves[3] = 0;

    int num[2];
    num[0] = 0;
    num[1] = 0;

    while (full_size > 3)
    {
        num[0] = calculate_cost(stack_a, stack_b, full_size, moves);
        execute_moves(stack_a, stack_b, moves, num);
        full_size--;
    }
    sort3(stack_a);
    push_back_to_b(stack_a, stack_b);
    rotate_distance(stack_a, 0, 1);
}
