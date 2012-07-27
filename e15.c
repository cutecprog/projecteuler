/*
 * Starting in the top left corner of a 2x2 grid, there are 6 routes (without 
 * backtracking) to the bottom right corner. Note: routes cannot go up or left.
 *
 * http://projecteuler.net/project/images/p_015.gif
 *
 * How many routes are there through a 20x20 grid?
 */

#include <stdio.h>
#include "test_macros.h"
#include "e15_path.h"
                                                                                
int solution(const int grid_side_length);
void test_sweep();

main()
{
        int i;
        printf("Euler Problem 15\n");
        test_sweep();
        printf("Answer: %i\n", solution(500));
}

/*
 * Version: 12.07.26 (not complete)
 */
int solution(const int X)
{
        return -1;
}

/*
 * Version: 12.07.26 (not complete)
 * Test (e15_path.c):
 *      init()
 *      destruct()
 *      move_index_up()
 *      valid()
 *      final_position()
 *      all_contiguous()
 *      index_contiguous_to_next()
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
                                                "NULL (error code: 0)\n", input
                                                );
                return;
        }
        
        for(i = 0; i < input; i++) {
                answer = i;
                output = tmp.data[i];
                
                if(output != i) {
                        printf("! init(&tmp, %i) returned with tmp.data[%i] as"
                                                " %i but expected %i (error" 
                                                " code: 1)\n", input, i, 
                                                output, answer);
                        return;
                }
        }
        
        // Test for destruct()
        answer = 0;
        destruct(&tmp);
        output = (int)tmp.data;
        METHOD_TEST(destruct(&tmp), output, answer, return, 2);
                                                
        answer = 0;
        output = tmp.size;
        METHOD_TEST(destruct(&tmp), output, answer, return, 3);
        
        // bool valid(const struct path *self);
        init(&tmp, 3);
        answer = 1;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 4);
        
        tmp.data[0] = 3;
        answer = 0;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 5);
        
        tmp.data[0] = 1;
        answer = 0;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 6);
        
        tmp.data[0] = 0;
        tmp.data[2] = 6;
        answer = 0;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 7);
        
        destruct(&tmp);
        
        /*// Test for final_position()
        init(&tmp, 3);
        answer = false;
        METHOD_TEST(final_position, &tmp, output, answer);
        
        for(i = 0; i < tmp.size; i++)
                tmp.data[i] = tmp.size / 2 + i;
        answer = true;
        METHOD_TEST(final_position, &tmp, output, answer);
        
        destruct(&tmp);*/
                        
        
        
       
        // bool all_contiguous(const struct path *self);
        // bool index_contiguous_to_next(const struct path *self, unsigned int index);
        // void move_index_up(struct path *self, unsigned int index)
}

