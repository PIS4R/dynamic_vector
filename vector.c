
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int vector_create(struct vector_t *a, int N)
{
    if (N <= 0 || a == NULL)
        return 1;

    a->ptr = malloc(N * sizeof(int));
    if (a->ptr == NULL)
        return 2;

    a->size = 0;
    a->capacity = N;

    return 0;
}

int vector_create_struct(struct vector_t **a, int N)
{
    if (N <= 0){
        return 1;
    }
    if(*&a == NULL){
        return 1;
    }
    if(a == NULL){
        return 1;
    }
    *a = malloc(sizeof(struct vector_t));
    if (*a == NULL){
        return 2;
    }
    (*a)->ptr = malloc(N * sizeof(int));
    if ((*a)->ptr == NULL)
    {
        free(*a);
        return 2;
    }

    (*a)->size = 0;
    (*a)->capacity = N;

    return 0;
}

void vector_destroy(struct vector_t *a)
{
    if(a == NULL)return;
    free(a->ptr);
    a->ptr = NULL;
    a->size = 0;
    a->capacity = 0;
}

void vector_destroy_struct(struct vector_t **a)
{
    if(*&a == NULL){
        return;
    }
    if(*a == NULL) return;
    if(a == NULL) return;

    free((*a)->ptr);
    free(*a);
    *a = NULL;
}
int vector_push_back(struct vector_t *a, int value){
    if (a == NULL || a->size > a->capacity || a->ptr == NULL || *&a == NULL)
        return 1;
    if(a->capacity <= 0 || a->size < 0){
        return 1;
    }
    if (a->size == a->capacity){
        int *temp = realloc(a->ptr, 2 * a->capacity * sizeof(int));
        if (temp == NULL){
            return 2;
        }

        a->ptr = temp;
        a->capacity = a->capacity * 2;
    }

    *(a->ptr + a->size) = value;
    (a->size)++;

    return 0;

}
int vector_erase(struct vector_t *a, int value){
    if (a == NULL || a->ptr == NULL || a->size > a->capacity) {
        return -1;
    }
    if(a->capacity <= 0 || a->size < 0){
        return -1;
    }
    int destroyed_elems = 0;


    for (int i = 0; i < a->size; i++)
    {
        if (*(a->ptr + i) == value) {

            for (int j = i; j < a->size - 1; j++) {
                *(a->ptr + j) = *(a->ptr + j + 1);
            }
            destroyed_elems++;
            a->size--;
            i--;
        }
    }

    if(a->size < a->capacity/4){
        if(a->capacity - a->size > 1){
            int *temp = (int*)realloc(a->ptr,  a->capacity/2 * sizeof(int));
            if (temp != NULL){
                a->ptr = temp;
                a->capacity = a->capacity / 2;
            }

        } else{
            int *temp1 = (int*)realloc(a->ptr,  1 * sizeof(int));
            if (temp1 != NULL){
                a->ptr = temp1;
                a->capacity = 1;
            }

        }
    }

    return destroyed_elems;
}


void vector_display(const struct vector_t *a)
{
    if(a == NULL)return;
    if (a->ptr == NULL || a == NULL)
        return;
    if(a->size > a->capacity) return;
    if(a->size < 1) return;
    if(a->capacity < 1) return;


    for (int i = 0; i < a->size; i++)
    {
        printf("%d ", *(a->ptr+i) );
    }
    printf("\n");
}
