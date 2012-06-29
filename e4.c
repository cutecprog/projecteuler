/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <stdlib.h>

void solution(int *i, int *j, const int BASE);
char isPalindromic(int n, const int BASE);
char palinAux(int n, const int BASE, const int DIGITS);

main()
{
   int i,j;
   printf("Is palin: %i\n", palinAux(0x325423, 16, 6));
   //solution(&i, &j, 16);
   //i=0x111111;
   //printf("%i\n", isPalindromic(i,16));
   //printf("%x * %x = %x\n", i, j, i*j);
}

/* Limited version
Uses isPalindromic() to find the two 3-digit integers that when multiplied together make the largest possible palindrome. Note I could just return the palindrome and eliminate the need for pointers but I like know what those integers are. 
*/
void solution(int *i, int *j, const int BASE)
{
   int highbound = BASE*BASE*BASE - 1;     // if BASE==10 then highbound is 999
   int lowbound = highbound - (BASE*BASE); // if BASE==10 then lowbound is 899
   
   for(*i=highbound; *i>lowbound; --*i)
      for(*j=highbound; *j>lowbound; --*j)
      if(isPalindromic(*i * *j, BASE))
         return; // *i * *j is the answer
   *i=0;
   *j=0; // Shouldn't get here.
}

/* Place holder
*/
char isPalindromic(int n, const int BASE)
{
   return 0;
}

/* Iterative, general version (incomplete)
Determines whether or not the arguement is a palindrome given a base and number of digits.
*/
char palinAux(int n, const int BASE, const int DIGITS)
{
   int i, j;
   char isPalin = 1; // Holds whether or not argument is a palindrome.

   int *buffer; // buffer points to a dynamic array of ints that holds n's seperate digits.
   buffer = malloc(DIGITS * sizeof(int));
   // Sanity check.
   if (buffer==NULL) 
      exit(1);
  
   for(i=0; i<DIGITS; i++) {
      buffer[i] = n%BASE;
      n = n/BASE;
   }
   
   // The base idea behind i and j is that they both start at a digit and one moves up as the other moves down and they make sure those digits are the same. i and j's starting points are different relative to whether DIGITS is odd or even.
   for(i=DIGITS/2 + ((DIGITS%2) ? 1 : 0), j=DIGITS/2 -1; i<DIGITS; i++,j--) {
      isPalin = isPalin && (buffer[i] == buffer[j]);
   }
   
   free(buffer);
   return isPalin;  
}

