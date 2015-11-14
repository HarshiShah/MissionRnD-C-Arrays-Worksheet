/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (len <= 0 || Arr == NULL)
		return NULL;
	int left = 0, right = len - 1, mid;
	if (num>Arr[right]){
		mid = right;
	}
	else if (num<Arr[left]){
		mid = left - 1;
	}
	else{
		mid = (left + right) / 2;
		while (mid>left && mid<right){
			if (num>Arr[mid])
				left = mid;
			else if (num<Arr[mid])
				right = mid;
			else
				break;
			mid = (left + right) / 2;
		}
	}
	Arr = (int *)realloc(Arr, ((len + 1)*sizeof(int)));
	for (int i = len; i > mid + 1; i--)
		Arr[i] = Arr[i - 1];
	Arr[mid + 1] = num;
	return Arr;
}