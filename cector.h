#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LVector
{
    size_t count;
    size_t current_size;
    char** content;
} LVector;


void LVector_init(LVector* d)
{
    d->current_size = d->count = 0;
    d->content = (char**)malloc((d->count + 1) * sizeof(char*));
}

void LVector_pushback(LVector* d, char* item)
{
    size_t length = strlen(item);
    size_t new_size = (d->count + 1) * sizeof(char*);

    d->content = (char**)realloc(d->content, new_size);

    if (!d->content == NULL)
    {
        d->current_size = new_size;
        d->content[d->count] = (char*)malloc(length * sizeof(char));
        strcpy(d->content[d->count], item);
        d->count++;
    }
}

const char* LVector_at(LVector* d, int index)
{
    return d->content[index];
}


void LVector_delete(LVector* d)
{
    free(d->content);
    d->content = NULL;
    d->count = d->current_size = 0;
}


size_t LVector_size(LVector* d)
{
    return d->count;
}