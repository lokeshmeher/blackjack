#include "stdafx.h"

// plays a single game of blackjack
// deck is a shuffled deck of cards
// returns true if the player wins, orherwise false
bool playBlackJack(std::array<Card, 52> &deck)
{
	// keep track of whether the player wins or loses
	bool playerWin;

	// pointer to a card in the deck
	Card *cardPtr = &deck.at(0);

	int playerScore = 0;
	int dealerScore = 0;

	// dealer gets one card to start, player gets two
	dealerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);

	/* getCardValue(*cardPtr++) - deal a card, i.e., get the value of the current card,
	   and then advance the pointer to point at the next card. */

	// Since we assume ace has value 11 only instead of 1 of 11 for player to choose
	// handles the case when player gets two aces in the initial draw -- he loses
	if (playerScore > 21)
		playerWin = false;

	// hit-stand loop:
	while (playerScore <= 21 && dealerScore <= 21)
	{
		// ------ player's turn ------
		std::cout << "The dealer has a score of " << dealerScore << "\n";
		char playerChoice = getPlayerChoice(playerScore);
		if (playerChoice == 'h')
			playerScore += getCardValue(*cardPtr++);
		
		// discard playerChoice for 's'	- if player stands, it's the dealer's turn
		
		if (playerScore > 21)	// player loses
		{
			playerWin = false;
			break;
		}


		// ------ dealer's turn ------
		if (dealerScore < 17)
		{
			std::cout << "The dealer draws.\n";
			dealerScore += getCardValue(*cardPtr++);
			//std::cout << "The dealer's total score is now: " << dealerScore << "\n";
		}
		else if (playerScore > dealerScore)	// and dealerScore >= 17
		{
			playerWin = true;
			break;
		}
		
		if (dealerScore > 21)	// dealer loses
		{
			playerWin = true;
			break;
		}
	}

	return playerWin;
}

/* Note / to-do:
- Doesn't handle the case when the dealer has value > 17 and he stands and then the player also chooses to stand
- When dealerScore = 21 and playerScore=20(or something near 21), the player is asked to stand or hit. It is highly unlikely that the player would take a hit in such a situation and chooses to stand continuously.
  The dealer would never take a hit then. It then continues infinitely.
*/
