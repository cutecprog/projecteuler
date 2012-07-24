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
char read_data(char *filename);
void test_sweep();

struct big_num {
        unsigned char *data;
        unsigned int size;
        unsigned char base;
};

main()
{
        //long long int test = 371072875339;
        //long long int *data;
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
 * Version: 12.07.22
 * Returns error code:
 * 0 - Successfully read file
 * 1-100 - Error on line
 * 101 - File not found
 * 102 - File does not have enough data
 * 103 - Data validation failure.
 */
char read_data(char *filename)
{
        return 103;
}


/*
 * Version: 12.07.22 (Limited Brute Readable)
 */
void test_sweep()
{
        // Test for read_data()
        long long int data[100];
        char code = read_data("e13.data");
        
        // Interpretting error code
        if(code >= 1 && code <= 100)
                printf("! When reading e13.data on line %i\n", code);
        else if(code == 101)
                printf("! e13.data was not found in directory\n");
        else if(code == 102)
                printf("! e13.data does not contain 100 lines of data\n");
        else if(code == 103)
                printf("! Data validation failure\n");
        else if(code != 0)
                printf("! An unknown error code was rerturned\n");
}

