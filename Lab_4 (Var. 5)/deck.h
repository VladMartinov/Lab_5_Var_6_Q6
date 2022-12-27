#pragma once
#include <algorithm>
#include <vector>
#include "card.h"

class Deck {
public:
	// == Конструкторы и деструкторы ==
	Deck();

	// Геттер
	int getCountOfCard() const;
	
	// == Методы ==
	void fillDeck();
	void shuffleDeck();
	void newDeck();
	
	Card getCard();

private:
	vector<Card> cards1;
	int countOfCard;
};