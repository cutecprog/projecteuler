/*
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <stdio.h>

int solution(int);

main()
{
   printf("%i\n", solution(100));
}

/*  Limited Graceful Readable
Solved with algebra and function just calculates an arithmatic expression.

Algebra Solution:
Where sigma(1,n,{i}) == n*(n+1)/2 is true for any value of n
and x^2 == x*x is true for any arithmatic expression of x.

sigma(1,n,{i})^2 - sigma(1,n,{i^2})

== (n*(n+1)/2)^2 - n*(n+1)*(2*n+1)/6

== n^2(n+1)^2/4 - n*(n+1)*(2*n+1)/6

== n*(n+1)*( n*(n+1)/4 - (2*n+1)/6 )

== n*(n+1)*( 6*n*(n+1)/24 - 4*(2n+1)/24 )

== n*(n+1)*(6*n^2-2*n-4)/24

== n*(n+1)*(3*n^2-n-2)/12

== (3*n*n-n-2)*(n+1)*n/12

So I just used that final arithmatic expression.
*/
int solution(int n)
{
   return (3*n*n-n-2)*(n+1)*n/12;
}


