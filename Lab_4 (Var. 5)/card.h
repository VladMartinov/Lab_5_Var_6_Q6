#pragma once
#include <string>

using namespace std;

class Card
{
public:

	// == Конструкторы и деструкторы ==
	Card();
	Card(wstring scoreCard, wchar_t suitCard);
	Card(const Card& copy);
	~Card();

	// Геттеры
	wstring getScoreCard();
	wchar_t getSuitCard();

	// Переопределенные операторы
	friend ostream& operator<<(ostream&, const Card&);
	Card& operator= (const Card &_copyCard);

	// == Методы ==
	void setScoreCard(wstring score);
	void setSuitCard(wchar_t suit);

private:
	wstring _scoreCard;
	wchar_t _suitCard;
};
