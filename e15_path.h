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

bool final_postion(const struct path *in);
bool valid(const struct path *in);
bool all_contiguous(const struct path *in);
bool index_contiguous_to_next(const struct path *in, int index);
void print_path(const struct path *in);
void move_index_up(struct path *in);

#endif

