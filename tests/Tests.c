/**
 * Author: David Brotz
 * File: Tests.c 
 */

#include "InsertSortTest.h"
#include "ShellSortTest.h"
#include "QuickSortTest.h"
#include "MergeSortTest.h"
#include "HeapSortTest.h"

#include <stdlib.h>
#include <check.h>

int main(void) {
	SRunner* _Runner = srunner_create(InsertionSortSuite());
	int _FailedCt = 0;

	srunner_add_suite(_Runner, ShellSortSuite());
	srunner_add_suite(_Runner, QuickSortSuite());
	srunner_add_suite(_Runner, MergeSortSuite());
	srunner_add_suite(_Runner, HeapSortSuite());
	srunner_set_fork_status(_Runner, CK_NOFORK);
	srunner_run_all(_Runner, CK_NORMAL);
	_FailedCt = srunner_ntests_failed(_Runner);
	srunner_free(_Runner);
	return (_FailedCt == 0) ? (EXIT_SUCCESS) : (EXIT_FAILURE);
}
