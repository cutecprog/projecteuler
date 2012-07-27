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
 *      valid()
 *      final_path()
 *      index_contiguous_to_next()
 *      all_contiguous()
 *      move_index_up()
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
        METHOD_TEST(destruct(&tmp), output, answer, return, 0x10);
                                                
        answer = 0;
        output = tmp.size;
        METHOD_TEST(destruct(&tmp), output, answer, return, 0x11);
        
        // bool valid(const struct path *self);
        init(&tmp, 3);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 1;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 0x20);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = 1;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 0x21);
        
        tmp.data[0] = 3;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 0;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 0x22);
        
        tmp.data[0] = 1;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = 0;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 0x23);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 6;
        answer = 0;
        output = valid(&tmp);
        METHOD_TEST(valid(&tmp), output, answer, return, 0x24);
        
        destruct(&tmp);
        
        // Test for final_path()
        init(&tmp, 3);
        
        tmp.data[0] = 6;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = false;
        output = final_path(&tmp);
        METHOD_TEST(final_path(&tmp), output, answer, return, 0x30);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = false;
        output = final_path(&tmp);
        METHOD_TEST(final_path(&tmp), output, answer, return, 0x31);
        
        tmp.data[0] = 3;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = true;
        output = final_path(&tmp);
        METHOD_TEST(final_path(&tmp), output, answer, return, 0x32);
        
        destruct(&tmp);
        
        // Test for index_contiguous_to_next()
        init(&tmp, 3);
        
        tmp.data[0] = 0;
        tmp.data[1] = 2;
        tmp.data[2] = 4;
        answer = false;
        output = index_contiguous_to_next(&tmp, 1);
        METHOD_TEST(index_contiguous_to_next(&tmp, 1), output, answer, return, 0x40);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = true;
        output = index_contiguous_to_next(&tmp, 1);
        METHOD_TEST(index_contiguous_to_next(&tmp, 1), output, answer, return, 0x40);
        
        tmp.data[0] = 0;
        tmp.data[1] = 4;
        tmp.data[2] = 5;
        answer = true;
        output = index_contiguous_to_next(&tmp, 1);
        METHOD_TEST(index_contiguous_to_next(&tmp, 1), output, answer, return, 0x41);
        
        destruct(&tmp);
        
        // Test for all_contiguous()
        init(&tmp, 3);
        
        tmp.data[0] = 6;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = false;
        output = all_contiguous(&tmp);
        METHOD_TEST(all_contiguous(&tmp), output, answer, return, 0x50);
        
        tmp.data[0] = 5;
        tmp.data[1] = 6;
        tmp.data[2] = 7;
        answer = false;
        output = all_contiguous(&tmp);
        METHOD_TEST(all_contiguous(&tmp), output, answer, return, 0x51);
        
        tmp.data[0] = 0;
        tmp.data[1] = 2;
        tmp.data[2] = 4;
        answer = false;
        output = all_contiguous(&tmp);
        METHOD_TEST(all_contiguous(&tmp), output, answer, return, 0x52);
        
        tmp.data[0] = 0;
        tmp.data[1] = 1;
        tmp.data[2] = 2;
        answer = true;
        output = all_contiguous(&tmp);
        METHOD_TEST(all_contiguous(&tmp), output, answer, return, 0x53);
        
        tmp.data[0] = 2;
        tmp.data[1] = 3;
        tmp.data[2] = 4;
        answer = true;
        output = all_contiguous(&tmp);
        METHOD_TEST(all_contiguous(&tmp), output, answer, return, 0x54);
        
        destruct(&tmp);
        
        // void move_index_up(struct path *self, unsigned int index)
}

