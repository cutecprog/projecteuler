/*
 * A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 *
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 *
 */

#include <stdio.h>


int solution(int a, int b, int c, const int X);

main()
{
        printf("Euler Problem 9\n");
        printf("Answer: %i\n", solution(332,333,334,1000));
}

/*
 * Not Complete 
 */
int solution(int a, int b, int c, const int X)
{
        printf("~ a = %i, b = %i, c = %i", a, b, c);
        if(c == b) 
                return solution((X - c + 1) / 2, 
                                (X - c + 1) / 2 + (c%2) ? 0 : 1,
                                c+1, X);
        if(a * a + b * b == c * c)
                return a * b * c;
        return solution(a-1, b+1, c, X);
}

