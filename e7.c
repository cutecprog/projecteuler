/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <stdio.h>

int solution(int);
char isPrime(int);

main()
{
   printf("%i\n", solution(100));
}

/* 
*/
int solution(int n)
{
   return (3*n*n-n-2)*(n+1)*n/12;
}

/*
Dumb force method (slightly smarter than brute force)
Given an odd inetger greater than 2, returns if prime.
*/
char isPrime(int n)
{
   for(i=3; n%i; i=2*i+1)
      if(i>=n/2)
         return 1;
   return 0
}
