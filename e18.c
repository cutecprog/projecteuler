/*
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 *         3
 *        7 4
 *       2 4 6
 *      8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 * http://projecteuler.net/problem=18
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "test_macros.h"
#include "e18_triangle.h"
                                                                                
int solution(struct node *triangle);
void test_sweep(char mode);

main()
{
        struct node triangle;
               
        printf("Euler Problem 18\n"); 
        
        test_sweep(0);

        printf("Running...\n");      
        printf("solution() = %i\n", solution(&triangle));
}


/*
 * Version: 12.08.12
 */
int solution(struct node *triangle)
{
        return -1;
}

/*
 * Version: 12.08.12
 * Test (e18_triangle.c):
 *      init()
 *      destruct()
 *      create_triangle()
 *      sum_of_data()
 *
 * Test (e18.c):
 *      solution()
 *
 * Modes:
 *      \0 -  normal
 *      v  -  verbose
 *      
 */
void test_sweep(char mode)
{
        int input;
        int output;
        int answer;
        int i;
        struct node *tmp;
        struct node *data;
        //struct node *stack;

        // Test for init()
        answer = 16;
        init(&tmp, 16);
        output = tmp->data;
        TEST(init(&tmp, 16), output, answer, mode == 'v',  , 0x0);
        
        answer = 0;
        output = (int)(tmp->right);
        TEST(init(&tmp, 16), output, answer, mode == 'v',  , 0x1);
        
        output = (int)(tmp->left);
        TEST(init(&tmp, 16), output, answer, mode == 'v',  , 0x2);

        // Test for destruct()
        answer = 0;
        destruct(&tmp);
        output = tmp->data;
        TEST(destruct(&tmp), output, answer, mode == 'v',  , 0x10);
        
        output = (int)(tmp->right);
        TEST(destruct(&tmp), output, answer, mode == 'v',  , 0x11);
        
        output = (int)(tmp->left);
        TEST(destruct(&tmp), output, answer, mode == 'v',  , 0x12);

        // Test for create_triangle()
        data = calloc(10, sizeof(struct node));
        
        printf("%i\n", sizeof(struct node));
        
        for(i = 0; i < 10; i++) {
                tmp = data + i;
                tmp->data = i;
        }
        
        for(i = 0; i < 10; i++) {
                tmp = data + i;
                print_node(&tmp);
        }
        
        create_triangle(&tmp, &data, 10);
        
        printf("\ncreate_triangle()\n");
        
        for(i = 0; i < 10; i++) {
                tmp = data + i;
                print_node(&tmp);
        }
        
        free(data);
}

