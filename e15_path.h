#ifndef E15_PATH_H
#define E15_PATH_H

#include <stdbool.h>

/*
 * Version: 12.07.27
 * This struct along with it's 'methods' represent paths in a grid.
 */
struct path {
        unsigned int *data;
        int size;
};

void init(struct path *self, unsigned int size);
void destruct(struct path *self);
void print_path(const struct path *self);
bool valid(const struct path *self);
bool final_path(const struct path *self);
bool index_contiguous_to_next(const struct path *self, unsigned int index);
bool all_contiguous(const struct path *self);
void move_index_up(struct path *self, unsigned int index);
void reset_up_to_index(struct path *self, unsigned int index);

#ifdef DEBUG
unsigned long long int init_count;
unsigned long long int destruct_count;
unsigned long long int print_path_count;
unsigned long long int valid_count;
unsigned long long int final_path_count;
unsigned long long int index_contiguous_to_next_count;
unsigned long long int all_contiguous_count;
unsigned long long int move_index_up_count;
unsigned long long int reset_up_to_index_count;
#endif

#endif

