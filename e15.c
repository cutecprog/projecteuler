/*
 * Starting in the top left corner of a 2x2 grid, there are 6 routes (without 
 * backtracking) to the bottom right corner. Note: routes cannot go up or left.
 *
 * http://projecteuler.net/project/images/p_015.gif
 *
 * How many routes are there through a 20x20 grid?
 */

#include <stdio.h>
#include <time.h>
#include "test_macros.h"
#include "e15_path.h"
                                                                                
long long int solution(const int GRID_SIDE_LENGTH);
void test_sweep();

main()
{
        printf("Euler Problem 15\n");
        test_sweep();
        
#ifdef DEBUG
        long int start = time(0);
        long long sum;
#endif
        
        printf("Answer: %lli\n", solution(20));

#ifdef DEBUG
        printf("Number of init() calls:                         %llu\n", init_count);
        printf("Number of destruct() calls:                     %llu\n", destruct_count);
        printf("Number of print_path() calls:                   %llu\n", print_path_count);
        printf("Number of valid() calls:                        %llu\n", valid_count);
        printf("Number of final_path() calls:                   %llu\n", final_path_count);
        printf("Number of index_contiguous_to_next() calls:     %llu\n", index_contiguous_to_next_count);
        printf("Number of all_contiguous() calls:               %llu\n", all_contiguous_count);
        printf("Number of move_index_up() calls:                %llu\n", move_index_up_count);
        printf("Number of reset_up_to_index() calls:            %llu\n", reset_up_to_index_count);
        sum = init_count + destruct_count + print_path_count + valid_count + final_path_count + index_contiguous_to_next_count + all_contiguous_count + move_index_up_count + reset_up_to_index_count;
        printf("Number of function calls:                       %llu\n", sum);
        printf("Speed in seconds:                               %li\n", start);
        start = time(0) - start;
        printf("Average function cycles:                        %lli\n", (long long int)2200000000 * start / sum);
#endif

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
        
        TRY {
                while(!final_path(&current_path)) {
                        if(all_contiguous(&current_path)) {
                                //printf("~ ");
                                //print_path(&current_path);
                                move_index_up(&current_path, current_path.size-1);
                                reset_up_to_index(&current_path, current_path.size-1);
                                path_count++;
                        } else for(i = 0; i < GRID_SIDE_LENGTH-1; i++) {
                                if(!index_contiguous_to_next(&current_path, i)) {
                                        move_index_up(&current_path, i);
                                        reset_up_to_index(&current_path, i);
                                        path_count++;
                                        break;
                                }
                        }
                }
        } CATCH {
                printf("Data was not valid\n");
        }
        
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
 */
void test_sweep()
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
        
        for(i = 0; i < input; i++) {
                answer = i;
                output = tmp.data[i];
                
                if(output != i) {
                        printf("! init(&tmp, %i) returned with tmp.data[%i] as"
                                                " %i but expected %i (error" 
                                                " code: 0x1)\n", input, i, 
                                                output, answer);
                        return;
                }
        }
        
        // Test for destruct()
        answer = 0;
        destruct(&tmp);
        output = (int)tmp.data;
        TEST(destruct(&tmp), output, answer, return, 0x10);
                                                
        answer = 0;
        output = tmp.size;
        TEST(destruct(&tmp), output, answer, return, 0x11);
        
        // bool valid(const struct path *self);
        init(&tmp, 3);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 1;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, return, 0x20);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = 1;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, return, 0x21);
        
        tmp.data[0] = 3;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 0;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, return, 0x22);
        
        tmp.data[0] = 1;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 0;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, return, 0x23);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 6;
        answer = 0;
        output = valid(&tmp);
        TEST(valid(&tmp), output, answer, return, 0x24);
        
        destruct(&tmp);
        
        // Test for final_path()
        init(&tmp, 3);
        
        /*tmp.data[0] = 6;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = false;
        output = final_path(&tmp);
        TEST(final_path(&tmp), output, answer, return, 0x30);*/
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = false;
        output = final_path(&tmp);
        TEST(final_path(&tmp), output, answer, return, 0x31);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = true;
        output = final_path(&tmp);
        TEST(final_path(&tmp), output, answer, return, 0x32);
        
        destruct(&tmp);
        
        // Test for index_contiguous_to_next()
        init(&tmp, 3);
        
        tmp.data[0] = 0;
        tmp.data[1] = 2;
        tmp.data[2] = 4;
        answer = false;
        output = index_contiguous_to_next(&tmp, 1);
        TEST(index_contiguous_to_next(&tmp, 1), output, answer, return, 0x40);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = true;
        output = index_contiguous_to_next(&tmp, 1);
        TEST(index_contiguous_to_next(&tmp, 1), output, answer, return, 0x40);
        
        tmp.data[0] = 0;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = true;
        output = index_contiguous_to_next(&tmp, 1);
        TEST(index_contiguous_to_next(&tmp, 1), output, answer, return, 0x41);
        
        destruct(&tmp);
        
        // Test for all_contiguous()
        init(&tmp, 3);
        
        /*tmp.data[0] = 6;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = false;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, return, 0x50);*/
        
        tmp.data[0] = 5;
        tmp.data[1] = 6;
        tmp.data[2] = 7;
        answer = false;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, return, 0x51);
        
        tmp.data[0] = 0;
        tmp.data[1] = 2;
        tmp.data[2] = 4;
        answer = false;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, return, 0x52);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = true;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, return, 0x53);
        
        tmp.data[0] = 2;
        tmp.data[1] = 3;
        tmp.data[2] = 4;
        answer = true;
        output = all_contiguous(&tmp);
        TEST(all_contiguous(&tmp), output, answer, return, 0x54);
        
        destruct(&tmp);
        
        // Test for move_index_up()
        init(&tmp, 3);
        
        input = 0;
        tmp.data[input] = 2;
        answer = 3;
        move_index_up(&tmp, input);
        output = tmp.data[input];
        TEST(move_index_up(&tmp, input), output, answer, return, 0x60);
        
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
        TEST(reset_up_to_index(&tmp, input), output, answer, , 0x70);
        answer = 1;
        output = tmp.data[1];
        TEST(reset_up_to_index(&tmp, input), output, answer, return, 0x70);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        input = 3;
        reset_up_to_index(&tmp, input);
        answer = 0;
        output = tmp.data[0];
        TEST(reset_up_to_index(&tmp, input), output, answer, , 0x71);
        answer = 1;
        output = tmp.data[1];
        TEST(reset_up_to_index(&tmp, input), output, answer, , 0x71);
        answer = 2;
        output = tmp.data[2];
        TEST(reset_up_to_index(&tmp, input), output, answer, return, 0x71);
        
        destruct(&tmp);
        
        // Test for solution()
        input = 2;
        answer = 6;
        output = solution(input);
        TEST(solution(input), output, answer, return, 0x1000);
        
        input = 3;
        answer = 20;
        output = solution(input);
        TEST(solution(input), output, answer, return, 0x1001);
}

