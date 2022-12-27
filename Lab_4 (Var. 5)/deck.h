#pragma once
#include <algorithm>
#include <vector>
#include "card.h"

class Deck {
public:
	// == ������������ � ����������� ==
	Deck();

	// ������
	int getCountOfCard() const;
	
	// == ������ ==
	void fillDeck();
	void shuffleDeck();
	void newDeck();
	
	Card getCard();

private:
	vector<Card> cards1;
	int countOfCard;
};