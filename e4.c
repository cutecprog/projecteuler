#include <stdio.h>

int solution(int *, int *);
char isPalindromic(int);

main()
{
   int i,j;
   printf("%i\n",solution(&i, &j));
}

int solution(int *i, int *j)
{
   for(*i=999; *i>900; --*i)
      printf("%i\n",*i);
   return 0;
}

// Test version
char isPalindromic(int n)
{
   if(n==840885) //915*919
      return 1;
   return 0;
}

