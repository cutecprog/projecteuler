#include <stdlib.h>
#include "e15_path.h"

/*
 * Version: 12.07.26
 * Sets up path struct.
 */
void init(struct path *self, unsigned int size)
{
        self->size = size;
        self->data = (unsigned int *) malloc(sizeof(unsigned int) * size);
}

/*
 * Version: 12.07.26
 * Frees data from heap.
 */
void destruct(struct path *self)
{
        self->size = 0;
        free(self->data);
}

/*
 * Version: 12.07.26 (not complete)
 */
bool final_postion(const struct path *self)
{
}

/*
 * Version: 12.07.26 (not complete)
 */
bool valid(const struct path *self)
{
}

/*
 * Version: 12.07.26 (not complete)
 */
bool all_contiguous(const struct path *self)
{
}

/*
 * Version: 12.07.26 (not complete)
 */
bool index_contiguous_to_next(const struct path *self, unsigned int index)
{
}

/*
 * Version: 12.07.26 (not complete)
 */
void print_path(const struct path *self)
{
}

/*
 * Version: 12.07.26 (not complete)
 */
void move_index_up(struct path *self, unsigned int index)
{
}

