/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

char check(int, int);

main()
{
   int n, r;
   scanf(" %i", &n);
   scanf(" %i", &r);
   printf("%i %i\n", n, r);
   printf("%i\n", check(n,r));
}

/* Sanity Check */
char check(int n, int range)
{
   if(range == 1)
      return 1;
   return n%range==0 && check(n, range-1);
}

