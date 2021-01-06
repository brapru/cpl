#include "vec.h"
#include "test_cpl.h"

void test_base(cpl_vector *vec){
	CHECK("Check base vector",
		vec != NULL);
}

void test_empty_before_push(cpl_vector *vec){
	CHECK("Check empty before push_back",
		(vector_empty(vec) == true));
}

void test_empty_after_push(cpl_vector *vec){
	CHECK("Check empty before push_back",
		(vector_empty(vec) == false));
}

void test_vector(void){
	printf("TEST: %s\n", __FILE__);
	
	cpl_vector *vec = vector(5);

	test_base(vec);
	test_empty_before_push(vec);

        for (int i = 0; i < 100; i++){
                vector_push_back(vec, i);
        }

	test_empty_after_push(vec);

	vector_free(vec);
}
