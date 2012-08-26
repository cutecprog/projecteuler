#ifndef E15_PATH_H
#define E15_PATH_H

//#define DEBUG

/*
 * Version: 12.08.13
 */
struct node {
        unsigned int data;
        struct node *left;
        struct node *right;
};

void init(struct node **self, unsigned int data);
void destruct(struct node **self);
void print_node(struct node **self);
void create_triangle(struct node **self, struct node **data, unsigned int size);
int sum_of_triangle(struct node **self);

#endif

