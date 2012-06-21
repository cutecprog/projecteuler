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

/* Limited version
Uses isPalindromic() to find the two 3-digit integers that when multiplied together make the largest possible palindrome. Note I could just return the palindrome and eliminate the need for pointers but I like know what those integers are. 
*/
void solution(int *i, int *j)
{
   for(*i=999; *i>900; --*i)
      for(*j=999; *j>900; --*j)
      if(isPalindromic(*i * *j))
         return; // *i * *j is the answer
   *i=0;
   *j=0;
}

/* Ugly, Limited version
Determines whether or not the arguement is a palindrome. Arguement must be 6-digits.
*/
char isPalindromic(int n)
{
   int a[6], i;
   for(i=0; n; i++){
      a[i] = n%10;
      n = n/10;
   }
   if(a[0]==a[5] && a[1]==a[4] && a[2]==a[3])
      return 1;
   return 0;
   
}

