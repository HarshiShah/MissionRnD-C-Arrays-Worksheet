/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
void qSort(int *x, int start, int end);
void swap(int* a, int* b);


void * removeArrayDuplicates(int *Arr, int len)
{
	if (len <= 0 || Arr == NULL)
		return NULL;
	qSort(Arr, 0, len - 1);
	int j = 1;
	for (int i = 1; i < len; i++){
		if (Arr[i] != Arr[i - 1])
			Arr[j++] = Arr[i];
	}
	return 0;
}

void qSort(int *x, int start, int end){
	int pivot, j, i;
	if (start<end){
		pivot = start;
		i = start;
		j = end;

		while (i<j){
			while (x[i] <= x[pivot] && i<end)
				i++;
			while (x[j]>x[pivot])
				j--;
			if (i<j){
				swap(&x[i], &x[j]);
			}
		}

		swap(&x[pivot], &x[j]);
		qSort(x, start, j - 1);
		qSort(x, j + 1, end);

	}
}
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}