/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <stdio.h>

int solution(int);
char isPrime(int);

main()
{
   //printf("%i\n", solution(10001));
   int i;
   for(i=3; i<100; i+=2)
      printf("%i: %i", i, isPrime(i));
}

int solution(int index)
{
   int i=3, count=0;
   while(count < index) {
      i+=2; // Next odd number
      if(isPrime(i)) 
         count++;
   }
   return i; // i is the prime number at index.  
}

/*
Dumb force method (slightly smarter than brute force)
Given an odd inetger greater than 2, returns if prime.
*/
char isPrime(int n)
{
   int i;
   for(i=3; n%i; i+=2)
      if(i>=n/2)
         return 1;
   return 0;
}
