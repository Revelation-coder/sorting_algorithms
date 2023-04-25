#include <stdlib.h>
#include "deck.h"

/* Function prototypes */
int compare_cards(const void *c1, const void *c2);

/* Function definitions */
void sort_deck(deck_node_t **deck)
{
    size_t i;
    deck_node_t *tmp_node, *current_node;
    const card_t *tmp_card;
    card_t *cards_array;

    /* Allocate an array of pointers to the cards */
    cards_array = malloc(sizeof(*cards_array) * 52);
    if (!cards_array)
        return;

    /* Copy the pointers to the cards in the doubly linked list */
    current_node = *deck;
    for (i = 0; i < 52; i++) {
        cards_array[i] = *current_node->card;
        current_node = current_node->next;
    }

    /* Sort the array of pointers using qsort */
    qsort(cards_array, 52, sizeof(*cards_array), compare_cards);

    /* Swap the nodes in the doubly linked list */
    current_node = *deck;
    for (i = 0; i < 52; i++) {
        tmp_card = current_node->card;
        current_node->card = &cards_array[i];
        tmp_node = current_node->next;
        current_node->next = (i == 51) ? NULL : tmp_node->next;
        current_node->prev = tmp_node;
        current_node = tmp_node;
    }

    /* Free the temporary array of pointers */
    free(cards_array);
}

int compare_cards(const void *c1, const void *c2)
{
    const card_t *card1 = (const card_t *) c1;
    const card_t *card2 = (const card_t *) c2;

    /* Compare the cards first by kind, then by value */
    if (card1->kind < card2->kind)
        return -1;
    else if (card1->kind > card2->kind)
        return 1;
    else if (card1->value[0] == 'A')
        return -1;
    else if (card2->value[0] == 'A')
        return 1;
    else if (card1->value[0] == 'K')
        return -1;
    else if (card2->value[0] == 'K')
        return 1;
    else if (card1->value[0] == 'Q')
        return -1;
    else if (card2->value[0] == 'Q')
        return 1;
    else if (card1->value[0] == 'J')
        return -1;
    else if (card2->value[0] == 'J')
        return 1;
    else if (card1->value[0] == '1')
        return -1;
    else if (card2->value[0] == '1')
        return 1;
    else if (card1->value[0] < card2->value[0])
        return -1;
    else if (card1->value[0] > card2->value[0])
        return 1;
    else
        return 0;
}

