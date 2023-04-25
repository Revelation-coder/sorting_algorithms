#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
    int *output = NULL;
    size_t i, j;
    int exp = 1;
    int max = 0;

    if (!array || size < 2)
        return;

    output = malloc(sizeof(int) * size);
    if (!output)
        return;

    for (i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    while (max / exp > 0) {
        int bucket[10] = {0};

        for (i = 0; i < size; i++) {
            bucket[array[i] / exp % 10]++;
        }

        for (i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }

        for (j = size - 1; (int)j >= 0; j--) {
            output[--bucket[array[j] / exp % 10]] = array[j];
        }

        for (i = 0; i < size; i++) {
            array[i] = output[i];
        }

        print_array(array, size);
        exp *= 10;
    }

    free(output);
}

