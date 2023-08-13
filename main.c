#include"definitions.h"


int main(void)
{
	int face_index[5];
	int suit_index[5];
	int similar_index[5];
	int frequency_array[13];

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */
	int menu = 0;
	int option, card = 0, card2 = 0, card3 = 0, card4 = 0, card5 = 0, card6 = 0, winner_meter_player = 0, winner_meter_computer = 0;
	menu = start_menu();
	while (menu == 2 || menu == 1) {
		if (menu == 2) {
			initialize_deck(deck);
			shuffle(deck);
			// player 1 deal
			deal(deck, face, suit, face_index, suit_index, 5);
			index_value(face, face_index, &Hands[0]);
			index_suit(suit, suit_index, &Hands[0]);
			// computer deal
			initialize_deck(deck);
			shuffle(deck);
			deal(deck, face, suit, face_index, suit_index, 5);
			index_value(face, face_index, &Hands[1]);
			index_suit(suit, suit_index, &Hands[1]);
			initialize_index_array(similar_index);
			int count_player = check_duplicate(&Hands[0], similar_index);
			int count_computer = check_duplicate(&Hands[1], similar_index);
			int straight_count_player = check_straight(&Hands[0]);
			int straight_count_computer = check_straight(&Hands[1]);

			// Player turn
			printf("\nhow many cards do you want to replace, enter a number less than 4: ");
			scanf("%d", &option);
			if (option > 0) {
				printf("\nwhat cards do you want to replace, enter an index:");
			}
			switch (option) {
			case 0:
				break;
			case 1:
				scanf("%d", &card);
				break;
			case 2:
				scanf("%d", &card2);
				scanf("%d", &card3);
				break;
			case 3:
				scanf("%d", &card4);
				scanf("%d", &card5);
				scanf("%d", &card6);
			}
			initialize_frequency_array(frequency_array);
			shuffle_and_deal_cards(option, card, card2, card3, card4, card5, card6, &Hands[0]);
			for (int i = 0; i < 5; i++) {
				printf("%5s of %-8s%c", face[Hands[0].Hand[i].index_face_vaue], suit[Hands[0].Hand[i].index_suit], i % 2 == 0 ? '\n' : '\t');
			}
			count_player = check_duplicate(&Hands[0], similar_index);
			if (count_player == 1) {
				printf("\nyou have a pair\n");
				winner_meter_player = 1;
			}
			int counter = 0;
			check_two_pair(&Hands[0], frequency_array);
			for (int i = 0; i < 13; i++) {
				if (frequency_array[i] == 2) {
					counter++;
				}
			}
			if (counter == 2) {
				printf("\nyou have a two pair\n");
				winner_meter_player = 2;
			}
			if (count_player == 2) {
				printf("\nyou have three of a kind\n");
				winner_meter_player = 3;
			}
			if (count_player == 3) {
				printf("\nyou have four of a kind\n");
				winner_meter_player = 4;
			}
			if (count_player == 4) {
				printf("\nyou have a flush\n");
				winner_meter_player = 5;
			}
			straight_count_player = check_straight(&Hands[0]);
			if (straight_count_player == 4) {
				printf("\nyou have a straight\n");
				winner_meter_player = 6;
			}
			// computer turn
			initialize_frequency_array(frequency_array);
			shuffle_and_deal_cards_computer(similar_index, &Hands[1]);
			for (int i = 0; i < 5; i++) {
				printf("%5s of %-8s%c", face[Hands[1].Hand[i].index_face_vaue], suit[Hands[1].Hand[i].index_suit], i % 2 == 0 ? '\n' : '\t');
			}
			count_computer = check_duplicate(&Hands[1], similar_index);
			if (count_computer == 1) {
				printf("\nyou have a pair\n");
				winner_meter_computer = 1;
			} 

			counter = 0;
			check_two_pair(&Hands[1], frequency_array);
			for (int i = 0; i < 13; i++) {
				if (frequency_array[i] == 2) {
					counter++;
				}
			}
			if (counter == 2) {
				printf("\nyou have a two pair\n");
				winner_meter_computer = 2;
			}
			if (count_computer == 2) {
				printf("\nyou have three of a kind\n");
				winner_meter_computer = 3;
			}
			if (count_computer == 3) {
				printf("\nyou have four of a kind\n");
				winner_meter_computer = 4;
			}
			if (count_computer == 4) {
				printf("\nyou have a flush\n");
				winner_meter_computer = 5;
			}
			straight_count_computer = check_straight(&Hands[1]);
			if (straight_count_computer == 4) {
				printf("\nyou have a straight\n");
				winner_meter_computer = 6;
			}
			if (winner_meter_player > winner_meter_computer) {
				printf("\nplayer wins\n");
			}
			if (winner_meter_player == winner_meter_computer) {
				printf("\nits a draw\n");
			}
			if (winner_meter_computer > winner_meter_player) {
				printf("\n computer wins \n");
			}
			menu = start_menu();
		}
		else {
			printf("\n five card draw, where a user gets dealt five cards, and the computer gets dealt five cards, the user has the option to draw at most three cards and so does the computer, a pair is the basic amount, two pair is worth more, three of a kind is next, four of a kind is next, full house is next and straight is worth the most, the winner is determined after each round \n");
			menu = start_menu();
		}
	}

	return 0;
}
