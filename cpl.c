#include "vec.h"

int main(void){
        cpl_vector *vec = vector(5);

        if (vector_is_empty(vec))
                printf("Empty Vector\n");

        for (int i = 0; i < 100; i++){
                vector_push_back(vec, i);
        }

        if (!vector_is_empty(vec))
                printf("Not empty vector\n");

        printf("Index 10: %d\n", vec->data[9]);
        printf("Size: %zu\n", vec->size);
        printf("Capacity: %zu\n", vec->capacity);

        vector_free(vec);
}
