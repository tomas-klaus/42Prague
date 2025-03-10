// test_test.c

#include "ft_printf.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

void	test_ft_printf(void)
{
    int	a;

    int ret1, ret2;
    // Test 1: Simple string
    ret1 = printf("Hello, World!\n");
    ret2 = ft_printf("Hello, World!\n");
    assert(ret1 == ret2);
    // Test 2: Integer
    ret1 = printf("Number: %d\n", 42);
    ret2 = ft_printf("Number: %d\n", 42);
    assert(ret1 == ret2);
    // Test 3: Character
    ret1 = printf("Character: %c\n", 'A');
    ret2 = ft_printf("Character: %c\n", 'A');
    assert(ret1 == ret2);
    // Test 4: String
    ret1 = printf("String: %s\n", "Test");
    ret2 = ft_printf("String: %s\n", "Test");
    assert(ret1 == ret2);
    // Test 5: Unsigned integer
    ret1 = printf("Unsigned: %u\n", 42);
    ret2 = ft_printf("Unsigned: %u\n", 42);
    assert(ret1 == ret2);
    // Test 6: Hexadecimal (lowercase)
    ret1 = printf("Hex: %x\n", 255);
    ret2 = ft_printf("Hex: %x\n", 255);
    assert(ret1 == ret2);
    // Test 7: Hexadecimal (uppercase)
    ret1 = printf("Hex: %X\n", 255);
    ret2 = ft_printf("Hex: %X\n", 255);
    assert(ret1 == ret2);
    // Test 8: Percent sign
    ret1 = printf("Percent: %%\n");
    ret2 = ft_printf("Percent: %%\n");
    assert(ret1 == ret2);
    // Test 9: Pointer
    a = 42;
    ret1 = printf("Pointer: %p\n", &a);
    ret2 = ft_printf("Pointer: %p\n", &a);
    assert(ret1 == ret2);
    // Test 10: Mixed
    ret1 = printf("Mixed: %d, %s, %c, %x\n", 42, "Test", 'A', 255);
    ret2 = ft_printf("Mixed: %d, %s, %c, %x\n", 42, "Test", 'A', 255);
    assert(ret1 == ret2);
    // Edge Case 1: Large integer
    ret1 = printf("Large Number: %d\n", INT_MAX);
    ret2 = ft_printf("Large Number: %d\n", INT_MAX);
    assert(ret1 == ret2);
    // Edge Case 2: Small integer
    ret1 = printf("Small Number: %d\n", INT_MIN);
    ret2 = ft_printf("Small Number: %d\n", INT_MIN);
    assert(ret1 == ret2);
    // Edge Case 3: Null string
    /* ret1 = printf("Null String: %s\n", NULL);
    ret2 = ft_printf("Null String: %s\n", NULL);
    assert(ret1 == ret2); */
    // Edge Case 4: Large unsigned integer
    ret1 = printf("Large Unsigned: %u\n", UINT_MAX);
    ret2 = ft_printf("Large Unsigned: %u\n", UINT_MAX);
    assert(ret1 == ret2);
    // Edge Case 5: Zero
    ret1 = printf("Zero: %d\n", 0);
    ret2 = ft_printf("Zero: %d\n", 0);
    assert(ret1 == ret2);
    // Edge Case 6: Negative number
    ret1 = printf("Negative: %d\n", -42);
    ret2 = ft_printf("Negative: %d\n", -42);
    assert(ret1 == ret2);
    // Edge Case 7: Empty string
    ret1 = printf("Empty String: %s\n", "");
    ret2 = ft_printf("Empty String: %s\n", "");
    assert(ret1 == ret2);
    // Edge Case 8: Long string
    char long_str[1024];
    for (int i = 0; i < 1023; i++) long_str[i] = 'a';
    long_str[1023] = '\0';
    ret1 = printf("Long String: %s\n", long_str);
    ret2 = ft_printf("Long String: %s\n", long_str);
    assert(ret1 == ret2);
    printf("All tests passed!\n");
}

int	main(void)
{
    test_ft_printf();
    return (0);
}