#pragma once
#include <vector>
#include "IPlayerActions.h"
#include "card.h"

class Player : public IPlayerActions {
public:

	// == ������������ � ����������� ==
	Player();
	Player(double money);
	Player(const Player& copy);

	//Card* removeCard();
	
	// ��������������� ����������
	Player& operator= (const Player& _copyPlayer);
	
	// �������/������
	double getMoney();
	void setMoney(double money);

	// == ������ ==
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
