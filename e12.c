/*
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The 
 * first ten terms would be:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 *
 *  1: 1
 *  3: 1,3
 *  6: 1,2,3,6
 * 10: 1,2,5,10
 * 15: 1,3,5,15
 * 21: 1,3,7,21
 * 28: 1,2,4,7,14,28
 * We can see that 28 is the first triangle number to have over five divisors.
 *
 * What is the value of the first triangle number to have over five hundred divisors?
 */

#include <stdio.h>

#define TEST(func, i, o, a)                                                     \
                o = func(i);                                                    \
                if(o != a)                                                      \
                        printf("! " #func "(%i) got %i but expected %i\n",      \
                                        i, o, a)
                                                                                

void solution();
int divisor_count(const int X);
void test_sweep();

main()
{
        printf("Euler Problem 12\n");
        test_sweep();
}

/*
 * Version: 12.07.20
 */
void solution()
{
}

/*
 * Version: 12.07.20
 */
int divisor_count(const int X)
{
        return 4;
}

/*
 * Version: 12.07.20
 */
void test_sweep()
{
        int input;
        int output;
        int answer;
        
        // divisor_count() test
        input = 28;
        answer = 5;
        TEST(divisor_count, input, output, answer);        
}

