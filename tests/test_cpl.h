#ifndef __TEST_CPL_H
#define __TEST_CPL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_MAX_ITER 512

#define TEST_MAX_RAND 512

#define CHECK(descr, _c) check(descr, _c)

#define TESTING(f) printf("TESTING: %s\n", f)

#define TEST_RAND(max) (rand() % max)

void check(const char *descr, bool cond);
void test_report(void);

#endif
