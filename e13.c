/*
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 * 
 * 37107287533902102798797998220837590246510135740250
 * 46376937677490009712648124896970078050417018260538
 * 74324986199524741059474233309513058123726617309629
 *                      ...
 *
 * Note: Remaining numbers omitted because that would take up 100 lines.
 */

#include <stdio.h>                                                                            

#define TEST(func, i, o, a)                                                     \
                o = func(i);                                                    \
                if(o != a)                                                      \
                        printf("! " #func "(%i) returned %i but expected %i\n", \
                                        i, o, a)

int solution(const long long int *DATA);
void test_sweep();

main()
{    
        long long int *data;
        printf("Euler Problem 12\n");
        test_sweep();
        printf("Answer: %i\n", solution(data));
}

/*
 * Version:
 */
int solution(const long long int *DATA)
{      
        return -1;
}


/*
 * Version: 
 */
void test_sweep()
{
        /* I'll need to redesign my test system before I start */
}

