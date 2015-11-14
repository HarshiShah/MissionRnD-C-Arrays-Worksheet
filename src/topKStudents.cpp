/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void swap1(struct student *s1, struct student *s2);
void sort1(struct student *students, int start, int end);

struct student ** topKStudents(struct student *students, int len, int K) {
	if (len <= 0 || students == NULL || K <= 0)
		return NULL;
	if (K < len)
		sort1(students, 0, len);
	else
		K = len;
	struct student**top = (struct student**)malloc(K*sizeof(struct student));
	for (int i = 0; i < K; i++)
		top[i] = &students[i];
	return top;
}

void sort1(struct student *students, int start, int end){
	if (end > start + 1){
		int piv = students[start].score, left = start + 1, right = end;
		while (left < right){
			if (students[left].score > piv)
				left++;
			else
				swap1(&students[left], &students[--right]);
		}
		swap1(&students[--left], &students[start]);
		sort1(students, start, left);
		sort1(students, right, end);
	}
}

void swap1(struct student *s1, struct student *s2){
	struct student temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
