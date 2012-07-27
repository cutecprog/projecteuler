#ifndef E15_PATH_H
#define E15_PATH_H

#include <stdbool.h>

/*
 * Version: 12.07.26 (not complete)
 * This struct along with it's function represent paths in the grid.
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

#endif

