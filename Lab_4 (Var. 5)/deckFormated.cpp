#include "DeckFormated.h"

// Адаптер для класса Deck, который принимает в себя объект этого класса и возвращает кол-во карт (В кодировке UTF-16, якобы наш дисплей поддерживает только данную кодировку)
wstring DeckFormated::format(const Deck& deck) {
	return to_wstring(deck.getCountOfCard());
}
