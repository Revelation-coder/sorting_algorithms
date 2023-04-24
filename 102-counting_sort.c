#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm
 *
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int i, max_val;
    int *count, *output;

    if (array == NULL || size < 2)
        return;

    max_val = array[0];
    for (i = 1; i < (int) size; i++)
    {
        if (array[i] > max_val)
            max_val = array[i];
    }

    count = malloc((max_val + 1) * sizeof(int));
    if (count == NULL)
        return;

    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    for (i = 0; i <= max_val; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < (int) size; i++)
    {
        count[array[i]]++;
    }

    for (i = 1; i <= max_val; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < (int) size; i++)
    {
        array[i] = output[i];
    }

    free(count);
    free(output);
}
