#include "deck.h"
#include "windows.h"
#include <time.h>
#include <iostream>

using namespace std;

// Конструкторы и деструктор
Deck::Deck() {
	Sleep(1000);
	countOfCard = 0;
	fillDeck();
	shuffleDeck();
}

// Оставшееся кол-во кард в колоде
int Deck::getCountOfCard() const { return countOfCard; }

void Deck::fillDeck() {
	// массивы для заполнения калоды
	wstring* allScore = new wstring[] { L"\u0032", L"\u0033", L"\u0034", L"\u0035", L"\u0036", L"\u0037", L"\u0038", L"\u0039", L"\u0030", L"\u004A", L"\u0051", L"\u004B", L"\u0041" };
	wchar_t* allSuit = new wchar_t[] { L'\u2665', L'\u2663', L'\u2666', L'\u2660' };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (j == 8) { // Т.к. 10 занимает состоит из 2х чаров
				cards1.push_back(*(new Card(L"\u0031\u0030", allSuit[i])));
			}
			else {
				cards1.push_back(* (new Card(allScore[j], allSuit[i])));
			}
			countOfCard++;
		}
	}

	delete[] allSuit;
	delete[] allScore;

}

void Deck::shuffleDeck() {
	
	srand(time(NULL));

	
	for(int i = 0; i < 4; i++) {
		for( int j = 0; j < 13; j++) {

			int firstCard = rand() % 52;

			Sleep(5);

			int secondCard = rand() % 52;

			swap(cards1[firstCard], cards1[secondCard]);
		} 

	}

}

// Достаем карту снизу колоды
Card Deck::getCard() { 
	countOfCard--;
	Card tempCard = cards1[cards1.size() - 1];
	cards1.pop_back();
	return tempCard;
}

// Обновляем колоду (не использовалось)
void Deck::newDeck() {
	Sleep(500);
	countOfCard = 0;
	cards1.clear();
	fillDeck();
	Sleep(500);
	shuffleDeck();
}
