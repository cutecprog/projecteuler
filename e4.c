/*
Euler Problem 4:
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <stdlib.h>

void solution(int *i, int *j, const unsigned int BASE, const unsigned int DIGITS);
char isPalindromic(int n, const unsigned int BASE, const unsigned int DIGITS);
char *itoa(int n, const unsigned int BASE, char *n_str);

main()
{
        char str[64] = {0};
        printf("Test %s\n",itoa(32, 16, str));
   
        /*int a,b,i;
        for(i=1; i<=6; i++) {
                solution(&a, &b, 2, i);
                printf("%o * %o = %o\n", a, b, a*b);
        }*/
}

/* Generic Dumb Ugly
Uses isPalindromic() to find the two x-digit integers that when multiplied together make the largest possible palindrome. Where x is a whole number.

Note I could just return the palindrome and eliminate the need for pointers but I like know what those integers are.

        highbound = BASE^DIGITS-1
        lowbound  = BASE^(DIGITS-1)-1

        if(BASE==10 && DIGITS==3) {
                highbound = 999;
                lowbound = 99;
        }
*/
void solution(int *r1, int *r2, const unsigned int BASE, const unsigned int DIGITS)
{
        // 0 is the greatest palindrome that is a product of 1 or 0 digit numbers
        if(DIGITS < 2) {
                *r1=0;
                *r2=0;
                return;
        }
   
        // Variable declaration
        int i, j, lowbound=1, highbound;
        int current, largest = -1;
   
        // Calucating highbound and lowbound
        for(i=0; i<(DIGITS-1); i++)
                 lowbound*=BASE;
        highbound = lowbound*BASE-1;
        lowbound = highbound - lowbound;
        printf("High: %i\nLow: %i\n", highbound, lowbound);
   
        // Calucating both integers
        for(i=highbound; i>lowbound; i--) {
                for(j=highbound; j>lowbound; j--) {
                        current = i*j;
                        if(isPalindromic(current, BASE, DIGITS*2) && current > largest) {
                                *r1 = i;
                                *r2 = j;
                                largest = current;
                        }
                }
        }
   
        // Sanity Check (largest should be -1 if not palindromes were found)
        if(largest < 0) {
                *r1=-1;
                *r2=-1;
        }
}

/* Generic Dumb Ugly
Determines whether or not the arguement is a palindrome given a base and number of digits.
*/
char isPalindromic(int n, const unsigned int BASE, const unsigned int DIGITS)
{
        int i, j;
        char isPalin = 1; // Holds whether or not argument is a palindrome.

        int *buffer; // buffer points to a dynamic array of ints that holds n's seperate digits.
        buffer = malloc(DIGITS * sizeof(int));
   
        // Sanity check.
        if (buffer==NULL) 
                 exit(1);
   
        // Loads n's (the oprand's) digits into the array buffer.
        for(i=0; i<DIGITS; i++) {
                buffer[i] = n%BASE;
                n = n/BASE;
        }
   
        // Checks if n is palindromic. i and j start in the middle and go to either end of buffer.
        for(i=DIGITS/2 + ((DIGITS%2) ? 1 : 0), j=DIGITS/2 -1; i<DIGITS; i++,j--) {
                isPalin = isPalin && (buffer[i] == buffer[j]);
        }
   
        free(buffer);
        return isPalin;
}

/*
 * Not Complete.
 */
char *itoa(int n, const unsigned int BASE, char *n_str)
{
        int i = 0;
        int tmp;
        if(n<0) {
                n = -n;
                n_str[0] = 0;
                i++;
        }
        while(n != 0) {
                tmp = n%BASE;
                n_str[i] = (tmp > 9) ? tmp - 9 + 'A' : tmp + '0';
                n/=BASE;
                i++;
        }
                
        return n_str;
}

