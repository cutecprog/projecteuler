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
#include <stdlib.h>

/* Sets the initial values for a, b, c */
# define sol(X) solution(((X) / 3), ((X) / 3), ((X) / 3 + (X) % 3), (X))

unsigned long int solution(int a, int b, int c, const int X);
unsigned long int solution_iterative(const int X);

main(int argc, char *argv[])
{
        if(argc==2) {
                printf("Euler Problem 9\n");
                printf("Answer: %lu\n", solution_iterative(atoi(argv[1])));
        }
}

/*
 * Version: 12.07.16
 * Returns a*b*c where a^2 + b^2 = c^2 and a + b + c = X and a, b, c, X are 
 * natural numbers.
 * 
 * Further assumptions:
 * a =< b < c therefore (X / 3 + 1) <= c <= (X - 2)
 *                                1 <= b <  c
 *                                1 <= a <= b
 * Example:
 * X = 1000
 * a = 333, b = 333, c = 334
 * a = 332, b = 334, c = 334 (base case)
 * a = 332, b = 333, c = 335
 * a = 331, b = 334, c = 335
 * a = 330, b = 335, c = 335 (base case)
 * a = 332, b = 332, c = 336
 *          . . .
 * a = 205, b = 370, c = 425
 * a = 204, b = 371, c = 425
 * a = 203, b = 372, c = 425
 * a = 202, b = 373, c = 425
 * a = 201, b = 374, c = 425
 * a = 200, b = 375, c = 425 (final base case)
 *
 * Note:
 * a truncates while b rounds so that a + b + c = X and a <=b
 */
unsigned long int solution(int a, int b, int c, const int X)
{
        //printf("~ a = %i, b = %i, c = %i\n", a, b, c);
        if(c == b) 
                return solution((X - c - 1) / 2,
                                (X - c - 1) / 2 + ((c % 2) ? 0 : 1),
                                c + 1, X);
        if(a * a + b * b == c * c) {
                printf("~ a = %i, b = %i, c = %i\n", a, b, c);
                return a * b * c;
        }
        return solution(a-1, b+1, c, X);
}

unsigned long int solution_iterative(const int X)
{
        int a = X / 3;
        int b = X / 3;
        int c = X / 3 + (X % 3);
        printf("~ a = %i, b = %i, c = %i\n", a, b, c);
        while(a * a + b * b != c * c)
                for(a = (X - c - 1) / 2, 
                    b = (X - c - 1) / 2 + ((c % 2) ? 0 : 1),
                    c++; c != b; a--,b++)
                        ;
        printf("~ a = %i, b = %i, c = %i\n", a, b, c);
        return a * b * c;
        
}

