/*
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 *         3
 *        7 4
 *       2 4 6
 *      8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 * http://projecteuler.net/problem=18
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "test_macros.h"
#include "e15_path.h"
                                                                                
long long int solution(const struct node triangle);
void test_sweep(char mode);

main()
{
        int input;
        
        printf("Euler Problem 18\n"); 
        
        test_sweep(0);

        printf("Running...\n");      
        printf("solution() = %i\n", solution(input));
}


/*
 * Version: 12.08.12
 */
long long int solution(const int GRID_SIDE_LENGTH)
{

}

/*
 * Version: 12.08.12
 * Test (e18_triangle.c):
 *      init()
 *      destruct()
 *      sum_of_data()
 *
 * Test (e18.c):
 *      solution()
 *
 * Modes:
 *      \0 -  normal
 *      v  -  verbose
 *      
 */
void test_sweep(char mode)
{
        int input;
        int output;
        int answer;
        struct node tmp;
        

        // Test for init()
        answer = 16;
        init(&tmp, 16);
        output = (int)tmp.data;
        TEST(init(&tmp, 16), output, answer, mode == 'v', return, 0x0);
        
        answer = 0;
        output = (int)tmp.right;
        TEST(init(&tmp, 16), output, answer, mode == 'v', return, 0x1);
        
        output = (int)tmp.left;
        TEST(init(&tmp, 16), output, answer, mode == 'v', return, 0x2);

        // Test for destruct()
        answer = 0;
        destruct(&tmp);
        output = (int)tmp.data;
        TEST(destruct(&tmp), output, answer, mode == 'v', return, 0x1);
        
        output = (int)tmp.right;
        TEST(destruct(&tmp), output, answer, mode == 'v', return, 0x1);
        
        output = (int)tmp.left;
        TEST(destruct(&tmp), output, answer, mode == 'v', return, 0x1);

}

