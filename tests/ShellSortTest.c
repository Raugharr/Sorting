/**
 * Author: David Brotz
 * File: ShellSortTest.h
 */

#include "ShellSortTest.h"

#include "../Sorting.h"

#include <check.h>
#include <alloca.h>
#include <stdlib.h>
#include <time.h>

#define LARGE (1000)

START_TEST(ShellSortAscendingTest) {
	int* _Table = alloca(sizeof(int) * LARGE);

	for(int i = 0; i < LARGE; ++i)
		_Table[i] = i;
	ShellSort(_Table, LARGE);
	for(int i = 0; i < LARGE; ++i)
		ck_assert_int_eq(_Table[i], i);
}
END_TEST

START_TEST(ShellSortDescendingTest) {
	int* _Table = alloca(sizeof(int) * LARGE);

	for(int i = 0; i < LARGE; ++i)
		_Table[i] = LARGE - i - 1 ;
	ShellSort(_Table, LARGE);
	for(int i = 0; i < LARGE; ++i)
		ck_assert_int_eq(_Table[i], i);
}
END_TEST

START_TEST(ShellSortRandomTest) {
	int* _Test = alloca(sizeof(int) * LARGE);

	srand(time(NULL));
	for(int i = 0; i < LARGE; ++i)
		_Test[i] = rand();
	ShellSort(_Test, LARGE);
	for(int i = 1; i < LARGE; ++i) {
		for(int k = 0; k < i; ++k) {
			ck_assert_int_le(_Test[k], _Test[i]);
		}
	}
}
END_TEST

Suite* ShellSortSuite(void) {
	Suite* _Suite = suite_create("Shell Sort");
	TCase* _Ascending = tcase_create("Ascending");
	TCase* _Descending = tcase_create("Descending");
	TCase* _Random = tcase_create("Random");

	tcase_add_test(_Ascending, ShellSortAscendingTest);
	tcase_add_test(_Descending, ShellSortDescendingTest);
	tcase_add_test(_Random, ShellSortRandomTest);

	suite_add_tcase(_Suite, _Ascending);
	suite_add_tcase(_Suite, _Descending);
	suite_add_tcase(_Suite, _Random);
	return _Suite;
}

