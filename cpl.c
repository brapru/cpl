#include "vec.h"

int main(void){
        cpl_vector *vec = vector(5);

        for (int i = 0; i < 100; i++){
                vector_push_back(vec, i);
        }

        printf("Index 10: %d\n", vec->data[9]);
        printf("Size: %zu\n", vec->size);
        printf("Capacity: %zu\n", vec->capacity);

        vector_free(vec);
}
