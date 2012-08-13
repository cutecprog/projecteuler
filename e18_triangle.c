#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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
        self->data = malloc((size_t)(sizeof(unsigned int) * size));
        
        if (self->data == NULL)
                THROW;
        
        int i;
        for (i = 0; i < self->size; i++)
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

