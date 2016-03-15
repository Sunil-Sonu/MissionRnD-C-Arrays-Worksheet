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
void quick(struct student *, int, int);
struct student {
	char *name;
	int score;
}t,**temp1;

struct student ** topKStudents(struct student *students, int len, int K) {
	int i;
	if (students == NULL||len<0 || K<=0)
	return NULL;
	else
{
	temp1 = (struct student**)malloc(2 * sizeof(struct student));;
	quick(students, 0, len - 1);
	for (i = 0; i < K; i++)
		temp1[i] = &students[i];
	return temp1;
}

}
void quick(struct student *students, int first, int last){
	int pivot, i, j;
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (students[i].score >= students[pivot].score && i < last)
				i++;
			while (students[j].score < students[pivot].score)
				j--;
			if (i < j)
			{
				t = students[i];
				students[i] = students[j];
				students[j] = t;
			}

		}
		t = students[pivot];
		students[pivot] = students[j];
		students[j] = t;
		quick(students, first, j - 1);
		quick(students, j + 1, last);
	}
}