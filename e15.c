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
 */
void test_sweep()
{
        int input;
        int output;
        int answer;
        int i;
        struct path tmp;
        
        // void init(struct path *self, unsigned int size);
        input = 3;
        init(&tmp, input);
        for(i = 0; i < input; i++) {
                output = tmp.data[i];
                answer = i;
                if(output != i) {
                        printf("! init(&tmp, %i) made tmp.data[%i] %i but "
                                                "expected %i\n", input, i, 
                                                output, answer);
                        break;
                }
        }
        
        // void destruct(struct path *self);
        answer = 0;
        destruct(&tmp);
        output = (int)tmp.data;
        if(output != answer)
                printf("! destruct(&tmp) returned with tmp.data as %i but "
                                                "expected %i\n", output, answer
                                                );
        answer = 0;
        output = tmp.size;
        if(output != answer)
                printf("! destruct(&tmp) returned with tmp.size as %i but "
                                                "expected %i\n", output, answer
                                                );
        
        // bool final_postion(const struct path *self);
        // bool valid(const struct path *self);
        // bool all_contiguous(const struct path *self);
        // bool index_contiguous_to_next(const struct path *self, unsigned int index);
        // void print_path(const struct path *self);
        // void move_index_up(struct path *self, unsigned int index)
}

