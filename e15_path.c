#include <stdio.h>
#include <stdlib.h>
#include "test_macros.h"
#include "e15_path.h"

/*
 * Version: 12.07.26
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
 * Version: 12.07.26
 * Frees data from heap.
 */
void destruct(struct path *self)
{
        free(self->data);
        self->data = NULL;
        self->size = 0;
}

/*
 * Version: 12.07.27
 * Prints out path as a bit stream using printf().
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
 * Version: 12.07.27
 * Valid if:
 *      Indexes are in order IE data[i] < data[i+1]
 *      All indexes are within size IE 0 <= data[i] < (size * 2) 
 *              EG 000111 if size is 3
 */
bool valid(const struct path *self)
{
        int i;
        for(i = 0; i < self->size-1; i++)
                if(self->data[i] >= self->data[i+1])
                        return false;
        
        for(i = 0; i < self->size; i++)
                if(self->data[i] < 0 || self->data[i] >= (self->size * 2))
                        return false;
        return true;
}

/*
 * Version: 12.07.27
 * Returns true if path.data in final position EG 000111 if size is 3.
 */
bool final_path(const struct path *self)
{
        if(!valid(self))
                return false;
                
        int i;
        for(i = 0; i < self->size; i++)
                if(self->data[i] != self->size + i) 
                        return false;
        return true;
}

/*
 * Version: 12.07.27
 * Returns to if index data value is contiguous with next index data value
 * EG 2, 3
 * Does not check if valid.
 */
bool index_contiguous_to_next(const struct path *self, unsigned int index)
{
        return (self->data[index] + 1 == self->data[index+1]);
}

/*
 * Version: 12.07.27
 * Returns true if all data values are contiguous EG 2, 3, 4.
 * If not valid then returns false (even if contiguous).
 */
bool all_contiguous(const struct path *self)
{
        if(!valid(self))
                return false;
            
        int i;
        int current;
        for(i = 1, current = self->data[0]; i < self->size; 
                                        current = self->data[i], i++)
                if(current + 1 != self->data[i])
                        return false;
        return true;
}

/*
 * Version: 12.07.26 (not complete)
 */
void move_index_up(struct path *self, unsigned int index)
{
}

