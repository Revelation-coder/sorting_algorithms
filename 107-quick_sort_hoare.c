#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Partition an array using the Hoare scheme
 * @array: Array to partition
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 * @size: Size of the array
 *
 * Return: Index of the pivot
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap_ints(&array[i], &array[j]);
        print_array(array, size);
    }
}

/**
 * quick_sort_helper - Helper function for quick_sort
 * @array: Array to sort
 * @low: Starting index of the partition to sort
 * @high: Ending index of the partition to sort
 * @size: Size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = hoare_partition(array, low, high, size);
        quick_sort_helper(array, low, pivot, size);
        quick_sort_helper(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}

