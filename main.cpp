#include "stdafx.h"
/* Note:
	In our simplified version of Blackjack, we’re not going to keep track of which specific
	cards the player and the dealer have been dealt. We’ll only track the sum of the values of
	the cards they have been dealt for the player and dealer. This keeps things simpler.
*/
int main()
{
	// call this before calling getRandomNumber()
	// set initial seed value to system clock
	// time() returns the number of seconds since midnight on Jan 1, 1970.
	srand(static_cast<unsigned int>(time(0)));
	
	// first result discarded to overcome a flaw in how rand() is implemented by the compiler
	rand();

	std::array<Card, 52> deck;

	// initialize deck with each card
	int index = 0;
	for (int suit = SUIT_CLUB; suit < MAX_SUITS; ++suit)
	{
		for (int rank = CARD_2; rank < MAX_RANKS; ++rank)
		{
			deck.at(index).suit = static_cast<CardSuit>(suit);
			deck.at(index).rank = static_cast<CardRank>(rank);
			++index;
		}
	}
	
	// printDeck(deck);

	shuffleDeck(deck);

	if (playBlackJack(deck))
		std::cout << "You win!\n";
	else
		std::cout << "You lose!\n";
	
	return 0;
}
