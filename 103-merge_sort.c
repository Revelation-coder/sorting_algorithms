#include "sort.h"
#include <stdlib.h>

/**
 * merge - Merge two sorted arrays
 * @array: Array of integers to be sorted
 * @size: Size of array
 * @left: Pointer to the left sub-array
 * @right: Pointer to the right sub-array
 **/
void merge(int *array, size_t size, int *left, int *right)
{
    int i = 0, j = 0, k = 0;
    int left_size = size / 2;
    int right_size = size - left_size;

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

/**
 * merge_sort - Sort an array of integers using the Merge sort algorithm
 * @array: Array of integers to be sorted
 * @size: Size of array
 **/
void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        int mid = size / 2;
        int *left = malloc(mid * sizeof(int));
        int *right = malloc((size - mid) * sizeof(int));
        int i;

        if (!left || !right)
        {
            free(left);
            free(right);
            return;
        }

        for (i = 0; i < mid; i++)
            left[i] = array[i];
        for (i = mid; i < size; i++)
            right[i - mid] = array[i];

        merge_sort(left, mid);
        merge_sort(right, size - mid);
        merge(array, size, left, right);

        free(left);
        free(right);
    }
}

