/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void swap(struct student *s1, struct student *s2);
void sort(struct student *students, int start, int end);


void * scoresDescendingSort(struct student *students, int len) {
	if (len <= 0 || students == NULL)
		return NULL;
	sort(students, 0, len);
	return 0;

}

void sort(struct student *students, int start, int end){
	if (end > start + 1){
		int piv = students[start].score, left = start + 1, right = end;
		while (left < right){
			if (students[left].score > piv)
				left++;
			else
				swap(&students[left], &students[--right]);
		}
		swap(&students[--left], &students[start]);
		sort(students, start, left);
		sort(students, right, end);
	}
}

void swap(struct student *s1, struct student *s2){
	struct student temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
