/*
 * Starting in the top left corner of a 2x2 grid, there are 6 routes (without 
 * backtracking) to the bottom right corner. Note: routes cannot go up or left.
 *
 * http://projecteuler.net/project/images/p_015.gif
 *
 * How many routes are there through a 20x20 grid?
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "test_macros.h"
#include "e15_path.h"
                                                                                
long long int solution(const int GRID_SIDE_LENGTH);
void test_sweep(char mode);

main(int argc, char *argv[])
{
        struct timeval tim;
        double start_time;
        double finish_time;
        int input;
        
        printf("Euler Problem 15\n"); 
        
        if(argc > 2)
                printf("! Warning too many command line arguments.\n");
       
        if(argc == 1)
                input = 14;
        else
                input = atoi(argv[1]);
        
        test_sweep('n');

        printf("Running...\n");      
        printf("solution(%i) = ", input);
        
        gettimeofday(&tim, NULL);
        start_time = tim.tv_sec + (tim.tv_usec / 1000000.0);
        
        printf("%lli and ran for ", solution(input));
        
        gettimeofday(&tim, NULL);
        finish_time = tim.tv_sec + (tim.tv_usec / 1000000.0);
        
        printf("%.6lf seconds\n", (finish_time - start_time));
}

/*
 * Version: 12.07.27 (Generic Brute Readable)
 */
long long int solution(const int GRID_SIDE_LENGTH)
{
        struct path current_path;
        init(&current_path, GRID_SIDE_LENGTH);
        int i;
        long long int path_count = 1;

        while (!final_path(&current_path)) {
                for (i = 0; i < GRID_SIDE_LENGTH; i++) {
                        if (!index_contiguous_to_next(&current_path, i)) {
                                move_index_up(&current_path, i);
                                reset_up_to_index(&current_path, i);
                                path_count++;
                                break;
                        }
                }
                // None of the if-statements executed (else statement)
                if (i == GRID_SIDE_LENGTH) {
                        path_count = -1;
                        goto exit; // Linus said I could
                }
        }

exit:
        destruct(&current_path);
        return path_count;
}

/*
 * Version: 12.07.26 (not complete)
 * Test (e15_path.c):
 *      init()
 *      destruct()
 *      valid()
 *      final_path()
 *      index_contiguous_to_next()
 *      all_contiguous()
 *      move_index_up()
 *      reset_up_to_index()
 *
 * Test (e15.c):
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
        
        int i;
        struct path tmp;

        // Test for init()
        input = 3;
        TRY  {
                init(&tmp, input);
        } CATCH {
                printf("! init(&tmp, %i) returned with tmp.data pointing to "
                                                "NULL (error code: 0x0)\n", input
                                                );
                return;
        }
        if (mode == 'v')
                printf("~ Passed test 0x0\n");

        for (i = 0; i < input; i++) {
                answer = i;
                output = tmp.data[i];
                
                if (output != i) {
                        printf("! init(&tmp, %i) returned with tmp.data[%i] as"
                                                " %i but expected %i (error" 
                                                " code: 0x1)\n", input, i, 
                                                output, answer);
                        return;
                }
        }
        if (mode == 'v')
                printf("~ Passed test 0x1\n");

        // Test for destruct()
        answer = 0;
        destruct(&tmp);
        output = (int)tmp.data;
        TEST(destruct(&tmp), output, answer, mode == 'v', return, 0x10);
                                        
        answer = 0;
        output = tmp.size;
        TEST(destruct(&tmp), output, answer, mode == 'v', return, 0x11);

        // Test for valid()
        init(&tmp, 3);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 1;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, mode == 'v', return, 0x20);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = 1;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, mode == 'v', return, 0x21);
        
        tmp.data[0] = 3;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 0;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, mode == 'v', return, 0x22);
        
        tmp.data[0] = 1;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 0;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, mode == 'v', return, 0x23);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 6;
        answer = 0;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, mode == 'v', return, 0x24);
        
        destruct(&tmp);
        
        // Test for final_path()
        init(&tmp, 3);

#ifdef DEBUG
        TRY {
                tmp.data[0] = 6;
                tmp.data[1] = 1;
                tmp.data[2] = 2;
                output = final_path(&tmp);
                printf("! Given invalid data final_path(&tmp) failed to throw"
                                                " (error code: 0x30)\n");
                return;
        }
        if (mode == 'v')
                printf("~ Passed test 0x30\n");
#endif
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = false;
        output = final_path(&tmp);
        TEST(final_path(&tmp), output, answer, mode == 'v', return, 0x31);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = true;
        output = final_path(&tmp);
        TEST(final_path(&tmp), output, answer, mode == 'v', return, 0x32);
        
        destruct(&tmp);
        
        // Test for index_contiguous_to_next()
        init(&tmp, 3);
        
        tmp.data[0] = 0;
        tmp.data[1] = 2;
        tmp.data[2] = 4;
        answer = false;
        output = index_contiguous_to_next(&tmp, 1);
        TEST(index_contiguous_to_next(&tmp, 1), output, answer, mode == 'v', return, 0x40);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = true;
        output = index_contiguous_to_next(&tmp, 1);
        TEST(index_contiguous_to_next(&tmp, 1), output, answer, mode == 'v', return, 0x41);
        
        tmp.data[0] = 0;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = true;
        output = index_contiguous_to_next(&tmp, 1);
        TEST(index_contiguous_to_next(&tmp, 1), output, answer, mode == 'v', return, 0x42);
        
        destruct(&tmp);
        
        // Test for all_contiguous()
        init(&tmp, 3);

#ifdef DEBUG
        TRY {
                tmp.data[0] = 6;
                tmp.data[1] = 1;
                tmp.data[2] = 2;
                output = all_contiguous(&tmp);
                printf("! Given invalid data all_contiguous(&tmp) failed to"
                                                " throw (error code: 0x50)\n");
                return;
        }
        if (mode == 'v')
                printf("~ Passed test 0x50\n");
        
        TRY {
                tmp.data[0] = 5;
                tmp.data[1] = 6;
                tmp.data[2] = 7;
                output = all_contiguous(&tmp);
                printf("! Given invalid data all_contiguous(&tmp) failed to"
                                                " throw (error code: 0x51)\n");
                return;
        }
        if (mode == 'v')
                printf("~ Passed test 0x51\n");
#endif

        tmp.data[0] = 0;
        tmp.data[1] = 2;
        tmp.data[2] = 4;
        answer = false;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, mode == 'v', return, 0x52);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = true;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, mode == 'v', return, 0x53);
        
        tmp.data[0] = 2;
        tmp.data[1] = 3;
        tmp.data[2] = 4;
        answer = true;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, mode == 'v', return, 0x54);
        
        destruct(&tmp);
        
        // Test for move_index_up()
        init(&tmp, 3);
        
        input = 0;
        tmp.data[input] = 2;
        answer = 3;
        move_index_up(&tmp, input);
        output = tmp.data[input];
        TEST(move_index_up(&tmp, input), output, answer, mode == 'v', return, 0x60);
        
        destruct(&tmp);
        
        // Test for reset_up_to_index()
        init(&tmp, 3);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        input = 2;
        reset_up_to_index(&tmp, input);
        answer = 0;
        output = tmp.data[0];
        TEST(reset_up_to_index(&tmp, input), output, answer, mode == 'v', , 0x70);
        answer = 1;
        output = tmp.data[1];
        TEST(reset_up_to_index(&tmp, input), output, answer, mode == 'v', return, 0x70);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        input = 3;
        reset_up_to_index(&tmp, input);
        answer = 0;
        output = tmp.data[0];
        TEST(reset_up_to_index(&tmp, input), output, answer, mode == 'v', , 0x71);
        answer = 1;
        output = tmp.data[1];
        TEST(reset_up_to_index(&tmp, input), output, answer, mode == 'v', , 0x71);
        answer = 2;
        output = tmp.data[2];
        TEST(reset_up_to_index(&tmp, input), output, answer, mode == 'v', return, 0x71);
        
        destruct(&tmp);

        // Test for solution()
        input = 2;
        answer = 6;
        output = (int)solution(input);
        TEST(solution(input), output, answer, mode == 'v', return, 0x1000);
        
        input = 3;
        answer = 20;
        output = (int)solution(input);
        TEST(solution(input), output, answer, mode == 'v', return, 0x1001);

}

