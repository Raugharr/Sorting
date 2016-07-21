/**
 * Author: David Brotz
 * File: InsertSortTest.c
 */

#include "InsertSortTest.h"

#include "../Sorting.h"

#include <check.h>
#include <alloca.h>
#include <stdlib.h>
#include <time.h>

#define LARGE (1000)

START_TEST(InsertionSortAscendingTest) {
	int* _Test = alloca(sizeof(int) * LARGE);

	for(int i = 0; i < LARGE; ++i)
		_Test[i] = i * 2;
	InsertionSort(_Test, LARGE);
	for(int i = 0; i < LARGE; ++i)
		ck_assert_int_eq(_Test[i], i * 2);
}
END_TEST

START_TEST(InsertionSortDescendingTest) {
	int* _Test = alloca(sizeof(int) * LARGE);

	for(int i = 0; i < LARGE; ++i)
		_Test[i] = (LARGE - i - 1) * 2;
	InsertionSort(_Test, LARGE);
	for(int i = 0; i < LARGE; ++i)
		ck_assert_int_eq(_Test[i], i * 2);
}
END_TEST

START_TEST(InsertionSortRandTest) {
	int* _Test = alloca(sizeof(int) * LARGE);

	srand(time(NULL));
	for(int i = 0; i < LARGE; ++i)
		_Test[i] = rand();
	InsertionSort(_Test, LARGE);
	for(int i = 1; i < LARGE; ++i) {
		for(int k = 0; k < i; ++k) {
			ck_assert_int_le(_Test[k], _Test[i]);
		}
	}
}
END_TEST

Suite* InsertionSortSuite(void) {
	Suite* _Suite = suite_create("Insertion Sort");
	TCase* _Ascending = tcase_create("Ascending");
	TCase* _Descending = tcase_create("Descending");
	TCase* _Random = tcase_create("Random");

	tcase_add_test(_Ascending, InsertionSortAscendingTest);
	tcase_add_test(_Descending, InsertionSortDescendingTest);
	tcase_add_test(_Random, InsertionSortRandTest);

	suite_add_tcase(_Suite, _Ascending);
	suite_add_tcase(_Suite, _Descending);
	suite_add_tcase(_Suite, _Random);
	return _Suite;
}
