#include "stdafx.h"

void swapCard(Card &card1, Card &card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

int getRandomNumber(int min, int max)
{
	// static used for efficiency, so we only calculate this value once
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
	for (auto &card : deck)
	{
		// generate a random number between 1 and 51
		int randomIndex = getRandomNumber(1, 51);

		// swap the current card with the random card
		swapCard(card, deck[randomIndex]);
	}
}

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case CARD_2:		return 2;
	case CARD_3:		return 3;
	case CARD_4:		return 4;
	case CARD_5:		return 5;
	case CARD_6:		return 6;
	case CARD_7:		return 7;
	case CARD_8:		return 8;
	case CARD_9:		return 9;

		// Used individual return statements for each case label for efficiency because if
		// fall-through is used, each of the case labels will still be checked for equality
	case CARD_10:		return 10;
	case CARD_JACK:		return 10;
	case CARD_QUEEN:	return 10;
	case CARD_KING:		return 10;

		// ACE can also have value 1 depending on which value advantages the player
		// for simplicity we assume only 11 here
	case CARD_ACE:		return 11;
	}

	return 0;	// invalid card has no value
}

char getPlayerChoice(int &playerScore)
{
	char playerChoice;

	do
	{
		std::cout << "Your total score is: " << playerScore << "\n";
		std::cout << "Do you want to hit or stand? (enter 'h' for hit, 's' for stand): ";
		std::cin >> playerChoice;
	} while (playerChoice != 'h' && playerChoice != 's');

	return playerChoice;
}
