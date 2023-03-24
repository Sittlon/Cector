#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Cector(vec) vector vec; \
                     Cector_init(&vec)


typedef struct Cector vector;
struct Cector
{
    size_t count;
    size_t current_size;
    void** content;

    int (*size)(vector *);
    int (*resize)(vector *, int);
    int (*pushback)(vector *, void *);
    int (*set)(vector *, int, void *);
    void *(*at)(vector *, int);
    int (*remove)(vector *, int);
    int (*delete)(vector *);
};

void Cector_pushback(vector* v, void* item)
{
    size_t new_size = (v->count + 1) * sizeof(void*);
    void** newMem = realloc(v->content, new_size);

    if (newMem)
    {
        v->content = newMem;
        v->current_size = new_size;
        v->content[v->count++] = item;
    }
}

void Cector_remove(vector* v, int index)
{
    if(index <= v->count)
    {
        v->content[index] = NULL;
        v->count--;
        void** newMem = realloc(v->content, v->count * sizeof(void*));

        if(newMem)
        {
            v->content = newMem;
        }
    }
}

void* Cector_at(vector* v, int index)
{
    void* data = NULL;

    if((v->count - 1) >= index && index >= 0)
    {
        data = v->content[index];
    }
    
    return data;
}

int Cector_delete(vector* v)
{
    free(v->content);
    v->content = NULL;
    v->count = v->current_size = 0;

    return 0;
}

int Cector_size(vector* v)
{
    return v->count;
}

void Cector_init(vector* v)
{
    v->size = Cector_size;
    //v->resize = ;
    v->pushback = Cector_pushback;
    //v->set = ;
    v->at = Cector_at;
    v->remove = Cector_remove;
    v->delete = Cector_delete;

    v->current_size = v->count = 0;
    v->content = malloc((v->count + 1) * sizeof(void*));
}