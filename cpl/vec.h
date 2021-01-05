#include "cpl.h"

typedef struct cpl_vector {
        int *data;
        size_t size;
        size_t capacity;
} cpl_vector;

static inline cpl_vector* vector(size_t capacity) {
        cpl_vector *v = malloc(sizeof(struct cpl_vector));
        if (!v){
                printf("Error allocating memory\n");
                return NULL;
        }

        v->data = (int*)malloc(capacity * sizeof(int));
        if (!v->data){
                printf("Error allocating memory\n");
                free(v);
                return NULL;
        } 
        
        v->capacity = capacity;
        v->size = 0;

        return v;
}

static inline void vector_push_back(cpl_vector *v, int val) {
        if (v->capacity == v->size) {
                v->capacity *= 2;
                v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
        }

        v->data[v->size++] = val;
}

static inline void vector_free(cpl_vector *v) {
        free(v->data);
        v->data = NULL;
        v->size = v->capacity= 0;
}

static inline size_t vector_size(cpl_vector *v){
        return v->size;
}

static inline size_t vector_capacity(cpl_vector *v){
        return v->capacity;
}
