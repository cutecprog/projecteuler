#ifndef E15_PATH_H
#define E15_PATH_H

#include <stdbool.h>

/*
 * Version: 12.07.26 (not complete)
 * This struct along with it's function represent paths in the grid.
 */
struct path {
        int *data;
        int size;
};

void init(struct path *self, int size);
void destruct(struct path *self);
bool final_postion(const struct path *self);
bool valid(const struct path *self);
bool all_contiguous(const struct path *self);
bool index_contiguous_to_next(const struct path *self, int index);
void print_path(const struct path *self);
void move_index_up(struct path *self);

#endif

