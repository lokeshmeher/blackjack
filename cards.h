#pragma once

#include "stdafx.h"

enum CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS
};

enum CardRank
{
	CARD_2,
	CARD_3,
	CARD_4,
	CARD_5,
	CARD_6,
	CARD_7,
	CARD_8,
	CARD_9,
	CARD_10,
	CARD_JACK,
	CARD_QUEEN,
	CARD_KING,
	CARD_ACE,
	MAX_RANKS
};

struct Card
{
	CardRank rank;
	CardSuit suit;
};


// Function forward declarations as prototypes
void printCard(const Card &card);

void printDeck(const std::array<Card, 52> &deck);

void swapCard(Card &card1, Card &card2);

int getRandomNumber(int min, int max);

void shuffleDeck(std::array<Card, 52> &deck);

int getCardValue(const Card &card);

int getCardValue(const Card &card);

char getPlayerChoice(int &playerScore);

bool playBlackJack(std::array<Card, 52> &deck);
