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
int chain_length_aux(int n, int count);
void test_sweep();

main()
{
        printf("Euler Problem 14\n");
        test_sweep();
        printf("Answer: %i\n", solution(100000));
}

/*
 * Version: 12.07.24 (Generic Smart Readable)
 * Uses chain_length() to find solution.
 */
unsigned int solution(const unsigned int THRESHOLD)
{
        int i;
        int largest = 0;
        int current;
        int return_value;
        for(i=1; i <= THRESHOLD; i++) {
                current = chain_length(i);
                if(current > largest) {
                        largest = current;
                        return_value = i;
                }
        }
                
        return return_value;
}

/*
 * Version: 12.07.23
 * Set up for chain_length_aux().
 */
int chain_length(int n)
{
        return chain_length_aux(n,1);
}

/*
 * Version: 12.07.23 (Generic Brute Readable)
 * Returns length of recursive chain.
 */
int chain_length_aux(int n, int count)
{
        if(n == 1)
                return count;
        if(n % 2)
                return chain_length_aux(3 * n + 1, count+1);
        return chain_length_aux(n / 2, count+1);
}

/*
 * Version: 12.07.23
 * Basic test for hand calculations.
 */
void test_sweep()
{
        int input;
        int output;
        int answer;
        
        // chain_length() test
        input = 13;
        answer = 10;
        TEST(chain_length, input, output, answer);
        input = 1;
        answer = 1;
        TEST(chain_length, input, output, answer);
        input = 2;
        answer = 2;
        TEST(chain_length, input, output, answer);
        input = 3;
        answer = 8;
        TEST(chain_length, input, output, answer);
        input = 4;
        answer = 3;
        TEST(chain_length, input, output, answer);
        input = 5;
        answer = 6;
        TEST(chain_length, input, output, answer);
        input = 6;
        answer = 9;
        TEST(chain_length, input, output, answer);
        
        // solution() test
        input = 6;
        answer = 6;
        TEST(solution, input, output, answer);
}

