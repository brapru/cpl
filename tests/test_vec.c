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

void test_erase(void){
	cpl_vector *vec = vector(0);

	int loops = TEST_RAND(TEST_MAX_ITER);
	for (int loop = 0; loop < loops; loop++){
		vector_push_back(vec, TEST_RAND(TEST_MAX_RAND));
	}

	int index = TEST_RAND(vec->size);
	int b_val = vector_at(vec,index+1);
	size_t b_size = vector_size(vec);
	
	vector_erase(vec, index);
	
	CHECK("Check size after index erase",
		(vector_size(vec) == b_size-1));

	CHECK("Check values after index erase",
		(vector_at(vec, index) == b_val));
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

void test_pop_back(void){
        cpl_vector *vec = vector(0);

	int val = TEST_RAND(TEST_MAX_RAND);	
	vector_push_back(vec, val);	

	int pop_val = vector_pop_back(vec);

	CHECK("Check value of pop_back",
		(val == pop_val));
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

void test_shrink_to_fit(void){
	cpl_vector *vec = vector(100);
	
	vector_resize(vec, 50);
	vector_shrink_to_fit(vec);

	CHECK("Check capacity after shrink_to_fit",
		(vec->capacity == 50 && vec->size == vec->capacity));

	vector_resize(vec, 0);
	vector_shrink_to_fit(vec);

	CHECK("Check after resize to zero",
		(vec->capacity == 0));

        int loops = TEST_RAND(TEST_MAX_ITER);
        for (int loop = 0; loop < loops; loop++){
                vector_push_back(vec, loop);
	}
	
	vector_shrink_to_fit(vec);
	
	CHECK("Check capacity after adding elements",
		(vec->capacity == (size_t)loops));
	
}

void test_vector(void){
        TESTING(__FILE__);

	cpl_vector *vec = vector(5);

	test_base(vec);
	test_empty_before_push(vec);
        test_push_back(vec);
	test_empty_after_push(vec);

        vector_free(vec); 

	test_erase();
	test_pop_back();	
	test_at();
        test_reserve();
        test_resize();
	test_shrink_to_fit();
}
