/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>

void solution(const int X);
char isPrime(int input);

main()
{
        printf("Euler Problem 10\n");
        solution(2000000);
}

/*
 * Version: 12.07.20 (Generic Dumb Readable)
 * Print out the sum of all primes below X
 */
void solution(const int X)
{
        int i;
        long long int sum = 5; // Head start on the sum (2 + 3)
        
        for(i = 5; i < X; i+=2)
                if(isPrime(i))
                        sum += i;
        printf("~ Answer: %lli\n", sum);
}

/* 
 * Version: 12.07.20 (Generic Smart Ugly)
 * Given an odd integer greater than 3, returns if prime.
 */
char isPrime(int input)
{
        int i;
        for(i = 3; input % i; i += 2)
                if((i * i) >= input)
                        return 1; // Prime
        return 0; // Not prime
}
