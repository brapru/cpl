#include "test_cpl.h"

void test_vector();
void test_quick();

int main(void){
	srand(time(0));
  
        test_vector();
	test_quick();
        test_report();	
}

/* Test Helpers */
static int __failed_tests = 0;
static int __test_num = 0;

void check(const char *descr, bool cond){
	__test_num++;
	printf("%d - %s: ", __test_num, descr);
	if (cond)
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		__failed_tests++;
	}
}

void test_report(void){
	printf("%d tests, %d passed, %d failed\n", __test_num, \
		__test_num-__failed_tests, __failed_tests);

	if (__failed_tests) {
		printf("WARNING! There was a failed test.\n");
		exit(1);
	}
}
