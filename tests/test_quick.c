#include "quick.h"
#include "test_cpl.h"

void test_sort(void){
        cpl_vector *vec = vector(0);

        int loops = TEST_RAND(TEST_MAX_ITER);
        for (int loop = 0; loop < loops; loop++){
                vector_push_back(vec, TEST_RAND(TEST_MAX_RAND));
        }

        quick(vec, 0, vec->size - 1);

        bool sorted = true;
        for (size_t i = 0; i < vector_size(vec) - 1; i++){
                if (vec->data[i] > vec->data[i + 1])
                        sorted = false; 
        }

        CHECK("Check quick sort",
                (sorted == true)); 
}

void test_quick(void){
        TESTING(__FILE__);

        test_sort();
}
