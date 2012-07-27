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
 *      final_position()
 *      valid()
 *      all_contiguous()
 *      index_contiguous_to_next()
 *      print_path()
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
        int setjmp_value;       // For TRY-CATCH macro

        
        // Test for init()
        input = 3;
        init(&tmp, input);
        for(i = 0; i < input; i++) {
                answer = i;
                
                TRY (setjmp_value, {
                        output = tmp.data[i];
                }) CATCH ({
                        printf("! init(&tmp, %i) returned with tmp.data[%i] as"
                                                " ? but expected %i\n", input,
                                                i, answer);
                        return;
                })
                
                if(output != i) {
                        printf("! init(&tmp, %i) returned with tmp.data[%i] as"
                                                " %i but expected %i\n", input, 
                                                i, output, answer);
                        return;
                }
        }
        
        // Test for destruct()
        answer = 0;
        destruct(&tmp);
        output = (int)tmp.data;
        if(output != answer) {
                printf("! destruct(&tmp) returned with tmp.data as %i but "
                                                "expected %i\n", output, answer
                                                );
                return;
        }
                                                
        answer = 0;
        output = tmp.size;
        if(output != answer) {
                printf("! destruct(&tmp) returned with tmp.size as %i but "
                                                "expected %i\n", output, answer
                                                );
                return;
        }
        
        // void print_path(const struct path *self)
        
        
        // Test for final_position()
        init(&tmp, 3);
        answer = false;
        METHOD_TEST(final_position, &tmp, output, answer);
        
        for(i = 0; i < tmp.size; i++)
                tmp.data[i] = tmp.size / 2 + i;
        answer = true;
        METHOD_TEST(final_position, &tmp, output, answer);
                        
        
        
        
        // bool valid(const struct path *self);
        // bool all_contiguous(const struct path *self);
        // bool index_contiguous_to_next(const struct path *self, unsigned int index);
        // void move_index_up(struct path *self, unsigned int index)
}

