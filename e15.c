/*
 * Starting in the top left corner of a 2x2 grid, there are 6 routes (without 
 * backtracking) to the bottom right corner. Note: routes cannot go up or left.6
 *
 * http://projecteuler.net/project/images/p_015.gif
 *
 * How many routes are there through a 20x20 grid?
 * 
 */

#include <stdio.h>

#define TEST(func, i, o, a)                                                     \
                o = func(i);                                                    \
                if(o != a)                                                      \
                        printf("! " #func "(%i) returned %i but expected %i\n", \
                                        i, o, a)
                                                                                

int solution(const int grid_side_length);
void test_sweep();

main()
{
        printf("Euler Problem 15\n");
        test_sweep();
        printf("Answer: %i\n", solution(500));
}

/*
 * Version: 12.07.25 (not complete)
 */
int solution(const int X)
{
        return -1;
}

/*
 * Version: 12.07.25 (not complete)
 */
void test_sweep()
{
        int input;
        int output;
        int answer;
        
        
}

