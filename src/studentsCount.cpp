
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	if (len <= 0 || Arr == NULL)
		return NULL;
	int left = 0, right = len, mid = (left + right) / 2;
	while (mid>left && mid<right){
		if (score>Arr[mid] && score<Arr[mid + 1])
			break;
		else if (score>Arr[mid])
			left = mid;
		else
			right = mid;
		mid = (left + right) / 2;

	}
	if (Arr[mid] < score)
		*lessCount = mid + 1;
	else
		*lessCount = mid;
	if (mid + 1<len && score != Arr[mid + 1])
		*moreCount = len - *lessCount;
	else{
		left = mid;
		right = len;
		mid = ((left + right) / 2);
		while (mid>left && mid<right){
			if (Arr[mid] > score && Arr[mid - 1] == score)
				break;
			else if (score == Arr[mid])
				left = mid;
			else
				right = mid + 1;
			mid = ((left + right) / 2);
		}
		if (Arr[mid] > score)
			*moreCount = len - mid;
		else
			*moreCount = len - mid - 1;
	}
	return 0;
}
