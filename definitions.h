#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

typedef struct Card
{
	int index_face_vaue;
	int index_suit;
}Card;

typedef struct Hand
{
	Card Hand[5];
}Hand;
Hand Hands[2];

void shuffle(int wDeck[][13]);
void initialize_deck(int wDeck[][13]);
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int* face_ptr, int* suit_ptr);
int start_menu();
int index_value(const char* wFace[], char* face_ptr, Hand *hand);
int index_suit(const char* wSuit[], int* suit_ptr, Hand *hand);
int check_duplicate(Hand *hand);
int check_straight(Hand *hand);
void shuffle_and_deal_cards(int num_of_cards, int one, int two, int three, int four, int five, int six, Hand* hand);
void initialize_index_array(int arr[]);
void shuffle_and_deal_cards_computer(int arr[], Hand* hand);
void print_index_array(int arr[]);
void initialize_frequency_array(int arr[]);
void check_two_pair(Hand* hand, int frequency[]);
int sequential_search(Hand* hand, int face, int suit);


