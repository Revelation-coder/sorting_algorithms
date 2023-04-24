#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *cur, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    cur = (*list)->next;
    while (cur != NULL)
    {
        tmp = cur->prev;
        while (tmp != NULL && tmp->n > cur->n)
        {
            tmp->next = cur->next;
            if (cur->next != NULL)
                cur->next->prev = tmp;

            cur->next = tmp;
            cur->prev = tmp->prev;
            tmp->prev = cur;

            if (cur->prev == NULL)
                *list = cur;
            else
                cur->prev->next = cur;

            tmp = cur->prev;
            print_list(*list);
        }
        cur = cur->next;
    }
}

