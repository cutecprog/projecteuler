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
   //solution(&i, &j);
   isPalindromic(919*915);
   //printf("%i * %i = %i\n", i, j, i*j);
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
   int a[6], i;
   for(i=0; n; i++){
      a[i] = n%10;
      n = n/10;
   }
   for(i=0; i<6; i++)
      printf("%i ",a[i]);
   
}

