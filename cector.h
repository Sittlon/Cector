#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cector
{
    size_t count;
    size_t current_size;
    char** content;
} Cector;


void Cector_init(Cector* d)
{
    d->current_size = d->count = 0;
    d->content = (char**)malloc((d->count + 1) * sizeof(char*));
}

void Cector_pushback(Cector* d, char* item)
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

const char* Cector_at(Cector* d, int index)
{
    return d->content[index];
}

void Cector_delete(Cector* d)
{
    free(d->content);
    d->content = NULL;
    d->count = d->current_size = 0;
}

size_t Cector_size(Cector* d)
{
    return d->count;
}