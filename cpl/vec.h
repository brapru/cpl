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

static inline int vector_at(cpl_vector *v, size_t index){
	return v->data[index];
}

static inline void vector_erase(cpl_vector *v, size_t index){
	if (index > v->size)
		return;

	for (size_t i = index; i < v->size; i++){
		v->data[i] = v->data[i+1];
	}	
	
	v->size--;
}

static inline void vector_push_back(cpl_vector *v, int val) {
        if (v->capacity == v->size) {
                v->capacity = (v->capacity == 0) ? 1 : v->capacity;
                
		v->capacity *= 2;
		v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
        }

        v->data[v->size++] = val;
}

static inline int vector_pop_back(cpl_vector *v){
	int pop_val = v->data[v->size - 1];
	vector_erase(v, v->size - 1);
	
	return pop_val;
}

static inline void vector_free(cpl_vector *v) {
        free(v->data);
        v->data = NULL;
        free(v);
        v = NULL;
}

static inline bool vector_empty(cpl_vector *v){
        return (v->size == 0) ? true : false;
}

static inline size_t vector_size(cpl_vector *v){
        return v->size;
}

static inline size_t vector_capacity(cpl_vector *v){
        return v->capacity;
}

static inline void vector_reserve(cpl_vector *v, size_t capacity){
        v->capacity = capacity; 
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
}

static inline void vector_resize(cpl_vector *v, size_t size){
        size = ((int)size < 0) ? 0 : size; 

        if (size > v->capacity){
                v->capacity = size;
                v->data = (int*)realloc(v->data, v->capacity * sizeof(int));  
        }
        
        v->size = size; 
}

static inline void vector_shrink_to_fit(cpl_vector *v){
	v->capacity = v->size;
	v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
}
