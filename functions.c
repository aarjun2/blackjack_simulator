#include "definitions.h"
int start_menu (){
	int option = 0;
	printf("choose a option between 1 and 3\n");
	scanf("%d", &option);
		switch (option) {
		case 1:
			printf("game rules\n");
			return option;
			break;
		case 2:
			return option;
			break;
		case 3:
			printf("goodbye\n");
			return option;
		}
	}

/* shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}
void initialize_deck(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (row = 0; row < 4; row++)
	{
		for (column = 0; column < 13; column++) {
			wDeck[row][column] = 0;
		}
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int face[], int suit[], int amount_deal)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	//int index_face[5];
	//int index_suit[5];
	
	int noofcards = 5;
	int indexforface = -1;
	int indexforsuit = -1;
	/* deal each of the 52 cards */
	for (card = 1; card <= amount_deal; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					indexforface = indexforface + 1;
					indexforsuit = indexforsuit + 1;
					face[indexforface] = column;
					suit[indexforsuit] = row;
				}
			}
		}
	}
}

int index_value(const char* wFace[], int *face_ptr, Hand *hand) {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 5; j++) {
			if (strcmp(wFace[i], wFace[face_ptr[j]]) == 0) {
				hand->Hand[j].index_face_vaue = i;
			}
		}
	}
}
int index_suit(const char* wSuit[], int* suit_ptr, Hand *hand) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (strcmp(wSuit[i], wSuit[suit_ptr[j]]) == 0) {
				hand->Hand[j].index_suit = i;
			}
		}
	}
}

int check_duplicate(Hand *hand, int arr[]) {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (hand->Hand[i].index_face_vaue == hand->Hand[j].index_face_vaue) {
				arr[i] = 1; 
				arr[j] = 1;
				count++;
			}
		}
	}
	return count;
}

void check_two_pair(Hand *hand, int frequency[]) {
	for (int i = 0; i < 5; i++) {
		frequency[hand->Hand[i].index_face_vaue] = frequency[hand->Hand[i].index_face_vaue] + 1;
		}
	}

int check_straight(Hand *hand) {
	int straight_count = 0;
	for (int i = 0; i < 5; i++) {
		if (hand->Hand[i].index_face_vaue+1 == hand->Hand[i + 1].index_face_vaue) {
			straight_count++;
		}
	}
	return straight_count;
}

void shuffle_and_deal_cards(int num_of_cards, int one, int two, int three, int four, int five, int six, Hand *hand) {
	int row = -1, column = -1;
	int found = 1;
	switch (num_of_cards) {
	case 1:
		found = 1;
		do {
			row = rand() % 4;
			column = rand() % 13;
			found = sequential_search(hand, column, row);
		} while (found == 1);
		if (found == 0) {
			hand->Hand[one].index_face_vaue = column;
			hand->Hand[one].index_suit = row;
		}
		/*row = rand() % 4;
		column = rand() % 13;
		hand->Hand[one].index_face_vaue = column;
		hand->Hand[one].index_suit = row;*/
		break;
	case 2:
		found = 1;
		do {
			row = rand() % 4;
			column = rand() % 13;
			found = sequential_search(hand, column, row);
		} while (found == 1);
		if (found == 0) {
			hand->Hand[two].index_face_vaue = column;
			hand->Hand[two].index_suit = row;
		}
		/*row = rand() % 4;
		column = rand() % 13;
		hand->Hand[two].index_face_vaue = column;
		hand->Hand[two].index_suit = row;*/
		found = 1;
		do {
			row = rand() % 4;
			column = rand() % 13;
			found = sequential_search(hand, column, row);
		} while (found == 1);
		if (found == 0) {
			hand->Hand[three].index_face_vaue = column;
			hand->Hand[three].index_suit = row;
		}
		/*row = rand() % 4;
		column = rand() % 13;
		hand->Hand[three].index_face_vaue = column;
		hand->Hand[three].index_suit = row;*/
		break;
	case 3:
		found = 1;
		do {
			row = rand() % 4;
			column = rand() % 13;
			found = sequential_search(hand, column, row);
		} while (found == 1);
		if (found == 0) {
			hand->Hand[four].index_face_vaue = column;
			hand->Hand[four].index_suit = row;
		}
		/*row = rand() % 4;
		column = rand() % 13;
		hand->Hand[four].index_face_vaue = column;
		hand->Hand[four].index_suit = row;*/
		found = 1;
		do {
			row = rand() % 4;
			column = rand() % 13;
			found = sequential_search(hand, column, row);
		} while (found == 1);
		if (found == 0) {
			hand->Hand[five].index_face_vaue = column;
			hand->Hand[five].index_suit = row;
		}
		/*row = rand() % 4;
		column = rand() % 13;
		hand->Hand[five].index_face_vaue = column;
		hand->Hand[five].index_suit = row;*/
		found = 1;
		do {
			row = rand() % 4;
			column = rand() % 13;
			found = sequential_search(hand, column, row);
		} while (found == 1);
		if (found == 0) {
			hand->Hand[six].index_face_vaue = column;
			hand->Hand[six].index_suit = row;
		}
		/*row = rand() % 4;
		column = rand() % 13;
		hand->Hand[six].index_face_vaue = column;
		hand->Hand[six].index_suit = row;*/
		break;
	}
}

void shuffle_and_deal_cards_computer(int arr[], Hand* hand) {
	int row = -1, column = -1;
	for (int i = 0; i < 5; i++) {
		if (arr[i] != 1) {
			int found = 1;
			do {
				row = rand() % 4;
				column = rand() % 13;
				found = sequential_search(hand, column, row);
			} while (found == 1);
			if (found == 0) {
				hand->Hand[i].index_face_vaue = column;
				hand->Hand[i].index_suit = row;
			}
		}
	}
}

void initialize_index_array(int arr[]) {
	for (int row = 0; row < 5; row++)
	{
		arr[row] = -1;
	}
}

void print_index_array(int arr[])
{
	for (int row = 0; row < 5; row++)
	{
		printf("\n %d", arr[row]);
	}
}

void initialize_frequency_array(int arr[]) {
	for (int row = 0; row < 13; row++)
	{
		arr[row] = -1;
	}
}

int sequential_search(Hand *hand, int face, int suit)
	{
		int index = 0, found = 0, size = 5;

		for (index = 0, found = 0; index < size && !found; ++index)
		{
			if (hand->Hand[index].index_face_vaue == face && hand->Hand[index].index_suit == suit)
			{
				found = 1;
			}
		}

		return found;
	}