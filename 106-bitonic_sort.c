#include <stdio.h>
#include "sort.h"

/* Function prototypes */
void bitonic_merge(int *array, size_t low, size_t size, int order);
void bitonic_sort_rec(int *array, size_t low, size_t size, int order);

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_rec(array, 0, size, 1);
}

/**
 * bitonic_merge - Merges two subarrays in bitonic order
 *
 * @array: Array of integers to sort
 * @low: Starting index of the first subarray
 * @size: Size of the subarrays to merge
 * @order: Sorting order (1 for ascending, -1 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t size, int order)
{
    if (size > 1)
    {
        size_t k = size / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == order)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }

        bitonic_merge(array, low, k, order);
        bitonic_merge(array, low + k, k, order);
    }
}

/**
 * bitonic_sort_rec - Sorts a subarray of integers in bitonic order
 *
 * @array: Array of integers to sort
 * @low: Starting index of the subarray
 * @size: Size of the subarray
 * @order: Sorting order (1 for ascending, -1 for descending)
 */
void bitonic_sort_rec(int *array, size_t low, size_t size, int order)
{
    if (size > 1)
    {
        size_t k = size / 2;

        bitonic_sort_rec(array, low, k, 1);
        bitonic_sort_rec(array, low + k, k, -1);
        bitonic_merge(array, low, size, order);
        printf("Result [%lu/%lu] (%s):\n", size, size, order == 1 ? "UP" : "DOWN");
        print_array(array + low, size);
    }
}

