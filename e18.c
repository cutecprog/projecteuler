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
                                                                                
long long int solution(const int GRID_SIDE_LENGTH);
void test_sweep(char mode);

main(int argc, char *argv[])
{
        int input;
        
        printf("Euler Problem 18\n"); 
        
        
        
        test_sweep(0);

        printf("Running...\n");      
        printf("solution(%i) = ", input);
        
        start_time = get_time();
        printf("%lli and ran for ", solution(input));
        finish_time = get_time();
        
        printf("%.6lf seconds\n", (finish_time - start_time));
}

/*
 * Version: 12.07.30
 */
double get_time()
{
        struct timeval tim;
        gettimeofday(&tim, NULL);
        return tim.tv_sec + (tim.tv_usec / 1000000.0);
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
        

        // Test for init()


        // Test for destruct()
        answer = 0;
        destruct(&tmp);
        output = (int)tmp.data;
        TEST(destruct(&tmp), output, answer, mode == 'v', return, 0x10);

}

