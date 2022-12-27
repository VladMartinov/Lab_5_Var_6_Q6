#include "banker.h"
#include <iostream>
#include <windows.h>

using namespace std;

// Конструкторы и деструкторы
Banker::Banker() {
	_countOfCard = 0;
}

Banker::Banker(const Banker& copy) {
	_cards1 = copy._cards1;
	_countOfCard = copy._countOfCard;
}

Banker& Banker::operator=(const Banker& _copyBanker) {
	_cards1 = _copyBanker._cards1;
	_countOfCard = _copyBanker._countOfCard;
	return *this;
}

int Banker::getCountOfCard() { return _countOfCard; }

// Очищает свои старые карты
void Banker::setNewCards() {
	_cards1.clear();
	
	_countOfCard = 0;
}

// Выдает игроку карту
Card Banker::issueACard(Deck &deck) {
	Sleep(5);
	wprintf(L"\n  (The Banker give for player the card)\n");
	return deck.getCard();
}

// Берет себе карту
void Banker::takeACard(Deck &deck) {
	Sleep(5);
	if (_countOfCard < 5) {
		_cards1.push_back(deck.getCard());
		wprintf(L"\n (Banker) The card was taken: ");
		cout << _cards1[_countOfCard];
		_countOfCard++;
	}
	else {
		wprintf(L"\n You have full pack of cards!");
	}
}

void Banker::printAllCard() {
	wprintf(L"\n%8Banker:");
	for (int i = 0; i < _countOfCard; i++) {
		cout << _cards1[i];
	}
	if (sumOfCard() < 17) {
		wprintf(L"  ??");
	}
}

// Сумма очков всех карт
int Banker::sumOfCard() {
	int sum = 0;

	for (int i = 0; i < _countOfCard; i++) {
		
		if (stoi( _cards1[i].getScoreCard() ) != 10)
		{
			if (stoi( _cards1[i].getScoreCard() ) == 11 ) {
				if (sum < 11)
					sum += 11;
				else
					sum += 1;
			}
			else
				sum += stoi(_cards1[i].getScoreCard());
		}
		else sum += 10;
	}

	return sum;
}
