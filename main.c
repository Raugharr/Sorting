#include "Sorting.h"

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SORT_CT (1000000)

double GetTime() {
	struct timeval _Time;

	gettimeofday(&_Time, NULL);
	return _Time.tv_usec;
}

int main() {
	char _Input[512];
	char _SortType;
	char _AlgoChoice;
	int _Size = 0;
	int* _Array;
	int* _TempArray;
	int* _BufferArray;

	size_pick:
	puts("Enter the size of the array:");
	fgets(_Input, 512, stdin);
	if((_Size = strtol(_Input, NULL, 10)) == 0)
		goto size_pick;	
	_Array = calloc(_Size, sizeof(int));
	_TempArray = calloc(_Size, sizeof(int));
	_BufferArray = calloc(_Size, sizeof(int));
	order_pick:
	puts("Enter a number to determine how the array is ordered");
	puts("1: Sorted descending");
	puts("2: All data the same");
	puts("3: Sorted ascending");
	puts("4: Randomly ordered");
	fgets(_Input, 512, stdin);
	_SortType = _Input[0];
	switch(_SortType - '0') {
		case 1:
			for(int i = _Size - 1; i >= 0; --i)
				_Array[i] = i;
		break;
		case 2:
			for(int i = 0; i < _Size; ++i)
				_Array[i] = i;
		break;
		case 3:
			for(int i = 0; i < _Size; ++i)
				_Array[i] = 15;
		break;
		case 4:
			srand(time(NULL));
			for(int i = 0; i < _Size; ++i) {
				_Array[i] = rand() % ((i + 1) * 8) + (i * 8) + 1 ;
			}
		break;
		default:
			printf("Invalid option %c given.", _SortType);
			goto order_pick;
		break;
	}
	algoritm_pick:
	puts("Enter a number for which sorting algoritm to run");
	puts("1: Insertion Sort");
	puts("2: Shell Sort");
	puts("3: Quick Sort with right pivot");
	puts("4: Quick Sort with median pivot");
	puts("5: Quick Sort with Insertion Sort");
	puts("6: Merge Sort");
	puts("7: Heap Sort");
	puts("8: All");
	fgets(_Input, 512, stdin);
	_AlgoChoice = _Input[0];
	int _StartTime = clock(); 
	switch(_AlgoChoice - '0') {
		case 1:
			InsertionSort(_Array, _Size);
		break;
		case 2:
			ShellSort(_Array, _Size);
		break;
		case 3:
			QuickSort_Aux(_Array, _Size, RightPivot);
		break;
		case 4:
			QuickSort_Aux(_Array, _Size, MedianPivot);
		break;
		case 5:
			QuickSortInsert_Aux(_Array, _Size, RightPivot);
		break;
		case 6:
			MergeSort_Aux(_Array, _BufferArray, _Size);
		break;
		case 7:
			Heapify(_Array, _Size);
			HeapSort(_Array, _Size);
		break;
		case 8:
			memcpy(_TempArray, _Array, _Size);
			InsertionSort(_TempArray, _Size);
			for(int i = 0; i < _Size; ++i)
				printf("%i ", _TempArray[i]);
			printf("\n");

			memcpy(_TempArray, _Array, _Size);
			ShellSort(_TempArray, _Size);
			for(int i = 0; i < _Size; ++i)
				printf("%i ", _TempArray[i]);
			printf("\n");

			memcpy(_TempArray, _Array, _Size);
			QuickSort_Aux(_TempArray, _Size, RightPivot);
			for(int i = 0; i < _Size; ++i)
				printf("%i ", _TempArray[i]);
			printf("\n");

			memcpy(_TempArray, _Array, _Size);
			QuickSort_Aux(_TempArray, _Size, MedianPivot);
			for(int i = 0; i < _Size; ++i)
				printf("%i ", _TempArray[i]);
			printf("\n");

			memcpy(_TempArray, _Array, _Size);
			QuickSortInsert_Aux(_TempArray, _Size, RightPivot);
			for(int i = 0; i < _Size; ++i)
				printf("%i ", _TempArray[i]);
			printf("\n");

			memcpy(_TempArray, _Array, _Size);
			MergeSort_Aux(_TempArray, _BufferArray, _Size);
			for(int i = 0; i < _Size; ++i)
				printf("%i ", _TempArray[i]);
			printf("\n");

			memcpy(_TempArray, _Array, _Size);
			Heapify(_TempArray, _Size);
			HeapSort(_TempArray, _Size);
			for(int i = 0; i < _Size; ++i)
				printf("%i ", _TempArray[i]);
			printf("\n");
		break;
		default:
			printf("Invalid option %c selected.", _AlgoChoice);
			goto algoritm_pick;
		break;
	}
	for(int i = 0; i < _Size; ++i)
		printf("%i ", _Array[i]);
	printf("\n");
	printf("%.5f seconds.\n", ((float)(clock() - _StartTime)) / CLOCKS_PER_SEC);
	free(_Array);
	free(_TempArray);
	free(_BufferArray);
	return 0;
}
