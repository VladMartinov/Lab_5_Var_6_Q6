#pragma once
#include "deck.h"
#include "IFormattable.h"

// Адаптер переписывающий метод интерфейса
class DeckFormated : Deck, IFormattable {
public:
	wstring format(const Deck& deck) override;
};