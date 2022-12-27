#pragma once
#include <vector>
#include "banker.h"
#include "player.h"
#include "DeckFormated.h"

class GameDesk {
public:
	// == ������������ � ����������� ==
	GameDesk();

	// == ������ ==
	void test();
	void startTheGame();

private:
	// ������ ������ ������
	double bet;

	// ��� ������ ������� �������
	Banker banker;
	Player player;
	vector<Deck> decks1;
};
