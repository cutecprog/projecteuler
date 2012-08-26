#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "test_macros.h"
#include "e18_triangle.h"

/*
 * Version: 12.08.14
 */
void init(struct node **self, unsigned int data)
{
        (*self) = malloc(sizeof(struct node));
        //free(self)
        (*self)->data = data;
        (*self)->left = 0;
        (*self)->right = 0;
}

/*
 * Version: 12.08.14
 */
void destruct(struct node **self)
{        
        if((*self)->left == 0) {
                (*self)->data = 0;
                free((*self));
                return;
        }
        destruct(&(*self)->left);
        destruct(&(*self)->right);
}

/*
 * Version: 12.08.14
 * Prints out data members and locations
 */
void print_node(struct node **self)
{
        printf("Data:\t&%u\t%u\nLeft:\t&%u\t%u\nRight:\t&%u\t%u\n", 
                                                (unsigned int)&((*self)->data),
                                                (unsigned int)(*self)->data,
                                                (unsigned int)&((*self)->left),
                                                (unsigned int)(*self)->left,
                                                (unsigned int)&((*self)->right),
                                                (unsigned int)(*self)->right);
}

/*
 * Version: 12.08.14
 */
void create_triangle(struct node **self, struct node **stack, unsigned int size)
{
        int i;
        //(*self) = stack[0];
        for(i = 1; i < size; i++) {
                (*stack + i)->left = *stack + i - 1;
                (*stack + i)->right = *stack + i;
        }
        (*self) = (*stack);
}

/*
 * Version: 12.08.14
 */
int sum_of_triangle(struct node **self)
{

}

