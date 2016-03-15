/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include <malloc.h>
int removeArrayDuplicates(int *Arr, int len)
{
	int i, j, k = len, l = 1, temp = 0,x;
	if (Arr == NULL || len<0)
		return -1;
	else
	{
		x = 2 * len;
		Arr[len] = Arr[0];
		for (i = 1; i < len; i++)
		{
			j = len;
			while (j <= k)
			{
				if ((Arr[j] != Arr[i]) && j == k)
				{
					k++;
					Arr[k] = Arr[i];
					l++;
					break;
				}
				else if (Arr[j] == Arr[i])
				{
					break;
				}
				j++;
			}
		}
		for (i = 0; i < l; i++)
		{
			Arr[i] = Arr[len];
			len++;
		}
		Arr[l] = NULL;
		return l;
	}
}