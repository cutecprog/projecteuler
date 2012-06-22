/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

char check(int, int);
int solution(int);

main()
{
   printf("%i\n", solution(20));
}

/* Brute force method */
int solution(int range)
{
   int i;
   for(i=1; 1; i++) {
      //printf("-");
      if(check(i,range))
         return i;
   }
   return 0; // Failure to find solution
}

/* Sanity Check */
char check(int n, int range)
{
   if(range == 1)
      return 1;
   return n%range==0 && check(n, range-1);
}

