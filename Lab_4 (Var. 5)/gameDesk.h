#pragma once
#include <vector>
#include "banker.h"
#include "player.h"
#include "DeckFormated.h"

class GameDesk {
public:
	// == Конструкторы и деструкторы ==
	GameDesk();

	// == Методы ==
	void test();
	void startTheGame();

private:
	// Хранит ставку игрока
	double bet;

	// Все нужные объекты классов
	Banker banker;
	Player player;
	vector<Deck> decks1;
};
