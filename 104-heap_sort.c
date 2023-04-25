#include <stdio.h>
#include "sort.h"

#define SWAP(a, b) do { int t = a; a = b; b = t; } while (0)

/**
 * sift_down - Perform sift down operation on a heap
 *
 * @array: Array representing the heap
 * @start: Index to start sifting down from
 * @end: Index to stop sifting down at
 *
 * Return: void
 */
void sift_down(int *array, size_t start, size_t end)
{
    size_t root = start, child, swap;

    while (root * 2 + 1 <= end)
    {
        child = root * 2 + 1;
        swap = root;

        if (array[swap] < array[child])
            swap = child;

        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;

        if (swap != root)
        {
            SWAP(array[swap], array[root]);
            print_array(array, end + 1);
            root = swap;
        }
        else
        {
            return;
        }
    }
}

/**
 * heap_sort - Sort an array of integers in ascending order using Heap sort
 *
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, i, size - 1);

    for (i = size - 1; i > 0; i--)
    {
        SWAP(array[0], array[i]);
        print_array(array, size);
        sift_down(array, 0, i - 1);
    }
}

