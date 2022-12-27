#pragma once
#include <vector>
#include "deck.h"

class Banker {
public:
	// == Конструкторы и деструкторы ==
	Banker();
	Banker(const Banker& copy);

	Banker& operator= (const Banker& _copyBanker);

	int getCountOfCard();

	// == Методы ==
	void setNewCards();

	Card issueACard(Deck &deck);
	void takeACard(Deck &deck);
	
	void printAllCard();
	int sumOfCard();

private:
	vector<Card> _cards1;
	int _countOfCard;

};