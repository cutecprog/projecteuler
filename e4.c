/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>

void solution(int *, int *);
char isPalindromic(int);

main()
{
   int i,j;
   solution(&i, &j);
   printf("%i * %i = %i\n", i, j, i*j);
}

void solution(int *i, int *j)
{
   for(*i=999; *i>900; --*i)
      for(*j=999; *j>900; --*j)
      if(isPalindromic(*i * *j))
         return; // *i * *j is the answer
   *i=0;
   *j=0;
}

// Test version
char isPalindromic(int n)
{
   if(n==840885) //915*919
      return 1;
   return 0;
}

