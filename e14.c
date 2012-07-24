/*
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n = n/2 (n is even)
 * n = 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following 
 * sequence:
 *
 * 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) 
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), 
 * it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <stdio.h>

#define TEST(func, i, o, a)                                                     \
                o = func(i);                                                    \
                if(o != a)                                                      \
                        printf("! " #func "(%i) returned %i but expected %i\n", \
                                        i, o, a)
                                                                                

unsigned int solution(const unsigned int THRESHOLD);
int chain_length(int n);
void test_sweep();

main()
{
        printf("Euler Problem 14\n");
        test_sweep();
        //printf("Answer: %i\n", solution(500));
}

/*
 * Version: 12.07.24 (not complete)
 */
unsigned int solution(const unsigned int THRESHOLD)
{
        int i;
        int current = 0;
        for(i=1; i < THRESHOLD; i++)
                ;
                
        return current;
}

/*
 * Version: 12.07.23 (not complete)
 */
int chain_length(int n)
{
        return 0;
}

/*
 * Version: 12.07.23 (not complete)
 */
void test_sweep()
{
        int input;
        int output;
        int answer;
        
        // chain_length() test
        
}

