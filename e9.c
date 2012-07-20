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

void solution(const int X);
void cleanup(long long int a, long long int b, long long int c, const int X);

main(int argc, char *argv[])
{
        if(argc==2) {
                printf("Euler Problem 9\n");
                solution(atoi(argv[1]));
        }
}

/*
 * Version: 12.07.19 (iterative)
 */
void solution(const int X)
{
        long long int a = X / 3;
        long long int b = X / 3;
        long long int c = X / 3 + (X % 3);
        
        while(a * a + b * b != c * c) {
                if(c == b) {
                        a = (X - c - 1) / 2;
                        b = (X - c - 1) / 2 + ((c % 2) ? 0 : 1);
                        c++;
                } else {
                        a--;
                        b++;
                }
        }
        cleanup(a, b, c, X);
}

/*
 * Version: 12.07.16
 * Get the raw data the algorithm puts out and makes it understandable. This
 * also serves as a test.
 */
void cleanup(long long int a, long long int b, long long int c, const int X)
{
        printf("~ a = %lli, b = %lli, c = %lli\n", a, b, c);
        
        if(a * a + b * b != c * c)
                printf("! Is not a right triangle\n");
                
        if(a < 0 || b < 0 || c < 0)
                printf("! Solution uses negative distances\n");
                
        if(a == 0)
                printf("! Couldn't find solution for: %i\n", X);
                
        if(a + b + c != X)
                printf("! Sum of a, b, c is %lli and not %i\n", (a + b + c), X);
}
/*
 * Notes:
 * Returns a*b*c where a^2 + b^2 = c^2 and a + b + c = X and a, b, c, X are 
 * natural numbers.
 * 
 * Further assumptions:
 * a =< b < c therefore (X / 3 + 1) <= c <= (X - 2)
 *                                1 <= b <  c
 *                                1 <= a <= b
 *
 * Variable a truncates while b rounds so that a + b + c = X and a <=b
 *
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
 */

