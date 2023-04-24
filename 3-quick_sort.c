#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer to swap
 * @b: Pointer to the second integer to swap
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * partition - Lomuto partition scheme
 * @array: array to partition
 * @lo: lowest index of partition
 * @hi: highest index of partition
 * @size: size of the array
 *
 * Return: index of partition
 */

size_t partition(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	int pivot = array[hi];
	ssize_t i = lo - 1, j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - quick sort algorithm
 * @array: array to sort
 * @lo: lowest index of partition
 * @hi: highest index of partition
 * @size: size of the array
 *
 * Return: void
 */
void qs(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		qs(array, lo, p - 1, size);
		qs(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs(array, 0, size - 1, size);
}

