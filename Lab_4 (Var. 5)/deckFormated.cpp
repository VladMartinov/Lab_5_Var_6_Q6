#include "DeckFormated.h"

// ������� ��� ������ Deck, ������� ��������� � ���� ������ ����� ������ � ���������� ���-�� ���� (� ��������� UTF-16, ����� ��� ������� ������������ ������ ������ ���������)
wstring DeckFormated::format(const Deck& deck) {
	return to_wstring(deck.getCountOfCard());
}
