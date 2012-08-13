#ifndef E15_PATH_H
#define E15_PATH_H

//#define DEBUG

#include <stdbool.h>

/*
 * Version: 12.07.27
 * This struct along with it's 'methods' represent paths in a grid.
 */
struct node {
        unsigned int data;
        struct node *left;
        struct node *right;
};

void init(struct node *self, unsigned int size);
void destruct(struct node *self);

#endif

