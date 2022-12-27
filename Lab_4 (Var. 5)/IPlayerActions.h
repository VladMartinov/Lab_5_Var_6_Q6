#pragma once

// Небольшой интерфей для игрока)
class IPlayerActions {
public:
	double virtual placeABet( double bet ) = 0;
};
