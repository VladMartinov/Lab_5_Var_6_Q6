#include "player.h"
#include <iostream>

using namespace std;


// Конструкторы копирования, методы копирования, обычные констркукторы
Player::Player() {
	_money = 100;
	_countOfCard = 0;
}


Player::Player(double money) {
	if (money > 0) _money = money;
	else _money = 0;
	_countOfCard = 0;
}

Player::Player(const Player& copy) {
	_money = copy._money;
	_cards1 = copy._cards1;
	_countOfCard = copy._countOfCard;
}

Player& Player::operator=(const Player& _copyPlayer) {
	_money = _copyPlayer._money;
	_cards1 = _copyPlayer._cards1;
	_countOfCard = _copyPlayer._countOfCard;
	return *this;
}

void Player::getTheCard(Card card) {
	if (_countOfCard < 5) {
		_cards1.push_back(card);
		wprintf(L"\n (Player) The card was taken: ");
		cout << _cards1[_countOfCard];
		_countOfCard++;
	}
	else {
		wprintf(L"\n You have full pack of cards!");
	}
}

void Player::setMoney(double money) { _money = money; }
double Player::getMoney () { return _money; }

// Добавление карты в нашу колоду
void Player::setNewCards() {
	_cards1.clear();
	_countOfCard = 0;
}

double Player::placeABet( double bet ) {
	if (bet > _money) {
		wprintf(L"\nInsufficient funds");
		return 0;
	}
	
	_money -= bet;
	return bet;
}

void Player::printAllCard(bool isStand = false) {
	wprintf(L"\n%8Player:");
	for (int i = 0; i < _countOfCard; i++) {
		cout << _cards1[i];
	}
	if (!isStand) {
		wprintf(L"  ??");
	}
}

// Сумма всех очков кард в нашем наборе
int Player::sumOfCard(bool isOne = false) {
	int sum = 0;

	for (int i = 0; i < _countOfCard; i++) {
		if (stoi(_cards1[i].getScoreCard()) != 10) {
			if (stoi(_cards1[i].getScoreCard()) == 11) {
				if(isOne){
					sum += 1;
				}
				else {
					wprintf(L"\n A it 1 or 11? (select 1/11)...\n");
					int selectedA = 0;
					cin >> selectedA;
					if (selectedA == 11)
						sum += 11;
					else
						sum += 1;
				}
			}
			else
				sum += stoi(_cards1[i].getScoreCard());
		}
		else sum += 10;
	}

	return sum;
}
