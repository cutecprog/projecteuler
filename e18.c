/*
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 * 75
 * 95 64
 * 17 47 82
 * 18 35 87 10
 * 20 04 82 47 65
 * 19 01 23 75 03 34
 * 88 02 77 73 07 63 67
 * 99 65 04 28 06 16 70 92
 * 41 41 26 56 83 40 80 70 33
 * 41 48 72 33 47 32 37 16 94 29
 * 53 71 44 65 25 43 91 52 97 51 14
 * 70 11 33 28 77 73 17 78 39 68 17 57
 * 91 71 52 38 17 14 91 43 58 50 27 29 48
 * 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 * 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem
 * by trying every route. However, Problem 67, is the same challenge with a
 * triangle containing one-hundred rows; it cannot be solved by brute force,
 * and requires a clever method! ;o)
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "test_macros.h"
#include "e15_path.h"
                                                                                
long long int solution(const int GRID_SIDE_LENGTH);
double get_time();
void test_sweep(char mode);

main(int argc, char *argv[])
{
        double start_time;
        double finish_time;
        int input;
        
        printf("Euler Problem 18\n"); 
        
        if(argc > 2)
                printf("! Warning too many command line arguments.\n");
       
        if(argc == 1)
                input = 14;
        else
                input = atoi(argv[1]);
        
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

