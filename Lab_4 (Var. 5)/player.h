#pragma once
#include <vector>
#include "IPlayerActions.h"
#include "card.h"

class Player : public IPlayerActions {
public:

	// == Конструкторы и деструкторы ==
	Player();
	Player(double money);
	Player(const Player& copy);

	//Card* removeCard();
	
	// Переопределение операторов
	Player& operator= (const Player& _copyPlayer);
	
	// Геттеры/Сетеры
	double getMoney();
	void setMoney(double money);

	// == Методы ==
	void getTheCard(Card card);
	void setNewCards();

	double placeABet( double bet ) override;

	void printAllCard(bool isStand);
	int sumOfCard(bool isOne);

private:
	double _money;
	vector<Card> _cards1;
	int _countOfCard;
};
