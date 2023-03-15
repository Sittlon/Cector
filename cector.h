#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cector
{
    size_t count;
    size_t current_size;
    char** content;
} Cector;


void Cector_init(Cector* v)
{
    v->current_size = v->count = 0;
    v->content = (char**)malloc((v->count + 1) * sizeof(char*));
}

void Cector_pushback(Cector* v, char* item)
{
    size_t length = strlen(item);
    size_t new_size = (v->count + 1) * sizeof(char*);

    v->content = (char**)realloc(v->content, new_size);

    if (!v->content == NULL)
    {
        v->current_size = new_size;
        v->content[v->count] = (char*)malloc(length * sizeof(char));
        strcpy(v->content[v->count], item);
        v->count++;
    }
}

void Cector_erase(Cector* v, int index)
{
    if(index <= v->count)
    {
        v->content[index] = NULL;
        v->count--;
        v->content = (char**)realloc(v->content, v->count * sizeof(char*));
    }
}

const char* Cector_at(Cector* v, int index)
{
    return v->content[index];
}

void Cector_delete(Cector* v)
{
    free(v->content);
    v->content = NULL;
    v->count = v->current_size = 0;
}

size_t Cector_size(Cector* v)
{
    return v->count;
}