/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int solution(int);
char check(int, int);

main()
{
   printf("%i\n", solution(20));
}

/* Limited Dumb Readable */
int solution(int range)
{
   int i;
   // Every i must be divisible by 20
   for(i=20; ; i+=20) {
      if(check(i,range))
         return i;
   }
   return 0; // Should never get here
}

/* Generic Brute Readable Recursive 
Checks if number is divisible by a range of integers (2 to range)
Creates the condition statement:
(n%range==0 && n%(range-1)==0 ... && n%2==0 && 1)
*/
char check(int n, int range)
{
   if(range == 1)
      return 1;
   return n%range==0 && check(n, range-1);
}

