#include "deck.h"

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

char value_to_int(const char *value)
{
	if (_strcmp(value, "Ace") == 0)
		return (0);
	else if (_strcmp(value, "1") == 0)
		return (1);
	else if (_strcmp(value, "2") == 0)
		return (2);
	else if (_strcmp(value, "3") == 0)
		return (3);
	else if (_strcmp(value, "4") == 0)
		return (4);
	else if (_strcmp(value, "5") == 0)
		return (5);
	else if (_strcmp(value, "6") == 0)
		return (6);
	else if (_strcmp(value, "7") == 0)
		return (7);
	else if (_strcmp(value, "8") == 0)
		return (8);
	else if (_strcmp(value, "9") == 0)
		return (9);
	else if (_strcmp(value, "10") == 0)
		return (10);
	else if (_strcmp(value, "Jack") == 0)
		return (11);
	else if (_strcmp(value, "Queen") == 0)
		return (12);
	else
		return (13);
}

int compare_cards(const card_t *card1, const card_t *card2)
{
	int value1, value2;

	if (card1->kind != card2->kind)
		return card1->kind - card2->kind;
	else
	{
		value1 = value_to_int(card1->value);
		value2 = value_to_int(card2->value);
		return (value1 - value2);
	}

}

void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *next_card;
	int swapped = 1;

	while (swapped == 1)
	{
		swapped = 0;
		current = *deck;
		while (current && current->next)
		{
			next_card = current->next;
			if (compare_cards(current->card, next_card->card))
			{
				if (current->prev)
					current->prev->next = next_card;
				else
					*deck = next_card;

				next_card->prev = current->prev;
				current->next = next_card->next;

				if (next_card->next)
					next_card->next->prev = current;

				next_card->next = current;
				current->prev = next_card;
				swapped = 1;
			}
			current = next_card;
		}
	}
}
