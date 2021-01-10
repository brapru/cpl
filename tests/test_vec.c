#include "vec.h"
#include "test_cpl.h"

void test_base(cpl_vector *vec){
	CHECK("Check base vector",
		vec != NULL);
}

void test_at(void){
	cpl_vector *vec = vector(0);
	int val = TEST_RAND(TEST_MAX_RAND);
	
	vector_push_back(vec, val);

	CHECK("Check lookup by index",
		(vector_at(vec, 0) == val));

	vector_free(vec);
}

void test_push_back(cpl_vector *vec){
        int loops = TEST_RAND(TEST_MAX_ITER);
       
        for (int loop = 0; loop < loops; loop++){
                vector_push_back(vec, loop);
        } 
        
        CHECK("Check length after push_back",
                (vector_size(vec) == (size_t)loops));

        CHECK("Check first value pushed",
                (vec->data[0] == 0));
        
        CHECK("Check last value pushed",
                (vec->data[vec->size - 1] == loops-1));
}

void test_empty_before_push(cpl_vector *vec){
	CHECK("Check empty before push_back",
		(vector_empty(vec) == true));
}

void test_empty_after_push(cpl_vector *vec){
	CHECK("Check empty after push_back",
		(vector_empty(vec) == false));
}

void test_reserve(void){
        cpl_vector *vec = vector(0);
        int reserve = TEST_RAND(TEST_MAX_RAND);

        vector_reserve(vec, reserve); 

        CHECK("Check reserve",
                (vec->capacity == (size_t)reserve));

        vector_free(vec);
}

void test_resize(void){
        cpl_vector *vec = vector(0);
  
        int increase = vec->size + TEST_RAND(TEST_MAX_RAND);
        vector_resize(vec, increase);

        CHECK("Check increase resize matches size",
                (vec->size == (size_t)increase)); 

        CHECK("Check increase resize matches capacity",
                (vec->capacity == (size_t)increase)); 
     
        int double_increase = vec->size + TEST_RAND(TEST_MAX_RAND);
        vector_resize(vec, double_increase);
        
        CHECK("Check double increase resize increases capacity",
                (vec->capacity > (size_t)increase)); 

        int decrease = vec->size - TEST_RAND(TEST_MAX_RAND);
        vector_resize(vec, decrease);

        CHECK("Check decrease resize matches size",
                (decrease > 0 ? (vec->size == (size_t)decrease) : (vec->size == 0)));

        CHECK("Check decrease resize matches same capacity",
                (vec->capacity == vec->capacity)); 

        vector_free(vec);
}

void test_vector(void){
        TESTING(__FILE__);

	cpl_vector *vec = vector(5);

	test_base(vec);
	test_empty_before_push(vec);
        test_push_back(vec);
	test_empty_after_push(vec);

	test_at();

        test_reserve();
        test_resize();

        vector_free(vec); 
}
