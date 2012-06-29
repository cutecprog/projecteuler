/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>

void solution(int *, int *, const int);
char isPalindromic(int, const int);

main()
{
   int i,j;
   solution(&i, &j, 16);
   //i=0x111111;
   //printf("%i\n", isPalindromic(i,16));
   printf("%x * %x = %x\n", i, j, i*j);
}

/* Limited version
Uses isPalindromic() to find the two 3-digit integers that when multiplied together make the largest possible palindrome. Note I could just return the palindrome and eliminate the need for pointers but I like know what those integers are. 
*/
void solution(int *i, int *j, const int BASE)
{
   int highbound = BASE*BASE*BASE - 1;     // if BASE==10 then highbound is 999
   int lowbound = highbound - (BASE*BASE); // if BASE==10 then lowbound is 899
   printf("%i %i\n", highbound, lowbound);
   
   for(*i=highbound; *i>lowbound; --*i)
      for(*j=highbound; *j>lowbound; --*j)
      if(isPalindromic(*i * *j, BASE))
         return; // *i * *j is the answer
   *i=0;
   *j=0; // Shouldn't get here.
}

/* Ugly, Limited version
Determines whether or not the arguement is a palindrome. Arguement must be 6-digits.
n is the integer that is tested for palindromity given a base.
*/
char isPalindromic(int n, const int BASE)
{
   int a[6];
   int i;
   for(i=0; n; i++){
      a[i] = n%BASE;
      n = n/BASE;
   }
   if(a[0]==a[5] && a[1]==a[4] && a[2]==a[3])
      return 1;
   return 0;
   
}

