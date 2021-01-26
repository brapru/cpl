#include "binsearch.h"
#include "test_cpl.h"

void test_bs(void){
	CHECK("Init bsearch test",
		(1 == 1));
}

void test_binsearch(void){
	TESTING(__FILE__);

	test_bs();
}
