#pragma once

// ��������� � ������� format
class IFormattable {
public:
	wstring virtual format(const Deck& deck) = 0;
};
