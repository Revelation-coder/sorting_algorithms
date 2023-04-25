#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 *
 * Return: void
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
    if (node1 == NULL || node2 == NULL)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 *
 * @list: Pointer to pointer to the head node of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *left, *right, *curr;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    left = NULL;
    right = *list;
    curr = right;

    while (right->next != NULL)
        right = right->next;

    while (left != right)
    {
        while (curr != right)
        {
            if (curr->n > curr->next->n)
            {
                swap_nodes(curr, curr->next);
                if (curr->prev == NULL)
                    *list = curr;
                print_list(*list);
            }
            else
                curr = curr->next;
        }
        right = right->prev;
        curr = right;
        while (curr != left)
        {
            if (curr->n < curr->prev->n)
            {
                swap_nodes(curr, curr->prev);
                if (curr->prev == NULL)
                    *list = curr;
                print_list(*list);
            }
            else
                curr = curr->prev;
        }
        left = left == NULL ? *list : left->next;
        curr = left;
    }
}
