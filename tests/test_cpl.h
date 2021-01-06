#ifndef __TEST_CPL_H
#define __TEST_CPL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(descr, _c) check(descr, _c)

void check(const char *descr, bool cond);
void test_report(void);

#endif
