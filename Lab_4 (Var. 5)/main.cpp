/* 
* ===== author: Vlad Martinov (ICT - 3) =====
* 
* ������������ ������ �5, ������� �6 �� ���������������� �� �++, ������� �6
* 
*/

#include <iostream>
#include "gameDesk.h"

using namespace std;

int main() {

	// ��������� ������ ��� ������ ������
	GameDesk gameDesk = *(new GameDesk());

	// ����� ������ ������ ����
	gameDesk.startTheGame();


	return 0;
}
