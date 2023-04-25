#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sub-arrays of integers
 * @array: Pointer to the first element of the first sub-array
 * @size: Number of elements in the first sub-array
 * @middle: Index of the last element of the first sub-array
 * @print_array: Pointer to the print_array function
 * Return: None
 */
void merge(int *array, size_t size, size_t middle, void (*print_array)(const int *, size_t))
{
    size_t i, j, k;
    int *left, *right;

    left = malloc((middle + 1) * sizeof(int));
    if (!left)
        return;
    right = malloc((size - middle) * sizeof(int));
    if (!right)
    {
        free(left);
        return;
    }
    for (i = 0; i <= middle; i++)
        left[i] = array[i];
    for (j = 0; j < size - middle - 1; j++)
        right[j] = array[middle + 1 + j];
    left[i] = 2147483647;
    right[j] = 2147483647;
    i = j = 0;
    for (k = 0; k < size; k++)
    {
        if (left[i] <= right[j])
            array[k] = left[i++];
        else
            array[k] = right[j++];
    }
    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, middle + 1);
    printf("[right]: ");
    print_array(right, size - middle - 1);
    printf("[Done]: ");
    print_array(array, size);
    free(left);
    free(right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge
 * sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
    size_t middle;
    int *left, *right;

    if (size < 2 || !array)
        return;
    middle = size / 2 - 1;
    left = array;
    right = array + middle + 1;
    merge_sort(left, middle + 1);
    merge_sort(right, size - middle - 1);
    merge(array, size, middle, print_array);
}


