#include "stdafx.h"

void printCard(const Card &card)
{
	switch (card.rank)
	{
	case CARD_2:
		std::cout << "2";
		break;
	case CARD_3:
		std::cout << "3";
		break;
	case CARD_4:
		std::cout << "4";
		break;
	case CARD_5:
		std::cout << "5";
		break;
	case CARD_6:
		std::cout << "6";
		break;
	case CARD_7:
		std::cout << "7";
		break;
	case CARD_8:
		std::cout << "8";
		break;
	case CARD_9:
		std::cout << "9";
		break;
	case CARD_10:
		std::cout << "X";
		break;
	case CARD_JACK:
		std::cout << "J";
		break;
	case CARD_QUEEN:
		std::cout << "Q";
		break;
	case CARD_KING:
		std::cout << "K";
		break;
	case CARD_ACE:
		std::cout << "A";
		break;
	}

	switch (card.suit)
	{
	case SUIT_CLUB:
		std::cout << "C";
		break;
	case SUIT_DIAMOND:
		std::cout << "D";
		break;
	case SUIT_HEART:
		std::cout << "H";
		break;
	case SUIT_SPADE:
		std::cout << "S";
		break;
	}
}

void printDeck(const std::array<Card, 52> &deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}
