#include "binsearch.h"
#include "test_cpl.h"

void test_bs(void){
        cpl_vector *vec = vector(0);

        int loops = TEST_RAND(TEST_MAX_ITER);
        for (int loop = 0; loop < loops; loop++){
                vector_push_back(vec, loop);
        }

        int key = loops == 0 ? 0 : loops - 1; 
        int index = binsearch(key, vec, 0, vector_size(vec)); 

        CHECK("Check matching key in binary search",
		(key == vec->data[index]));

        key = loops + 1;
        index = binsearch(key, vec, 0, vector_size(vec)); 

        CHECK("Check non-matching key in binary search",
                (index == NOTFOUND));
}

void test_binsearch(void){
	TESTING(__FILE__);

	test_bs();
}
