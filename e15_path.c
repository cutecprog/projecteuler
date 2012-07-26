#include <stdlib.h>
#include "e15_path.h"

/*
 * Version: 12.07.26 (not complete)
 * Allocates memory and sets up path struct in initial postion EG 111000 if
 * size is 3.
 */
void init(struct path *self, unsigned int size)
{
        /*self->size = size;
        self->data = (unsigned int *) malloc(sizeof(unsigned int) * size);*/
}

/*
 * Version: 12.07.26 (not complete)
 * Frees data from heap.
 */
void destruct(struct path *self)
{
        /*self->size = 0;
        free(self->data);*/
}

/*
 * Version: 12.07.26 (not complete)
 * Returns true if path.data in final position EG 000111 if size is 3.
 */
bool final_position(const struct path *self)
{
        /*int i;
        for(i = 0; i < self->size; i++)
                if(self->data[i] != self->size / 2 + i) 
                        return false;
        return true;*/
        return true;
}

/*
 * Version: 12.07.26 (not complete)
 */
bool valid(const struct path *self)
{
        return true;
}

/*
 * Version: 12.07.26 (not complete)
 */
bool all_contiguous(const struct path *self)
{
        return true;
}

/*
 * Version: 12.07.26 (not complete)
 */
bool index_contiguous_to_next(const struct path *self, unsigned int index)
{
        return true;
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

