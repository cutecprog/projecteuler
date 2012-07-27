#include <stdio.h>
#include <stdlib.h>
#include "test_macros.h"
#include "e15_path.h"

/*
 * Version: 12.07.26 (not complete)
 * Allocates memory and sets up path struct in initial postion EG 111000 if
 * size is 3.
 */
void init(struct path *self, unsigned int size)
{
        self->data = NULL;
        self->size = size;
        self->data = malloc(sizeof(unsigned int) * size);
        
        if(self->data == NULL) {
                THROW;
                return;
        }
        
        int i;
        for(i = 0; i < self->size; i++)
                self->data[i] = i;
}

/*
 * Version: 12.07.26 (not complete)
 * Frees data from heap.
 */
void destruct(struct path *self)
{
        free(self->data);
        self->data = NULL;
        self->size = 0;
}

/*
 * Version: 12.07.26 (not complete)
 */
void print_path(const struct path *self)
{
        int i;
        int j;
        
        if(!valid(self)) {
                printf("Data not valid.\n");
        }
        
        for(i = 0, j = 0; i < (self->size * 2); i++) {
                if(self->data[j] == i) {
                        printf("1");
                        j++;
                } else {
                        printf("0");
                }
        }
        
        printf("\n");
}

/*
 * Version: 12.07.26 (not complete)
 */
void move_index_up(struct path *self, unsigned int index)
{
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


