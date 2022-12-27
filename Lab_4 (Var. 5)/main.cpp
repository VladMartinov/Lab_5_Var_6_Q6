/* 
* ===== author: Vlad Martinov (ICT - 3) =====
* 
* Лабораторная работа №5, задание №6 по программированию на С++, Вариант №6
* 
*/

#include <iostream>
#include "gameDesk.h"

using namespace std;

int main() {

	// Выделение памяти под объект класса
	GameDesk gameDesk = *(new GameDesk());

	// Вызов метода начала игры
	gameDesk.startTheGame();


	return 0;
}
