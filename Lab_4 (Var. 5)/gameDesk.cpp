#include <iostream>
#include <time.h>
#include "io.h"
#include "fcntl.h"
#include "gameDesk.h"

using namespace std;


// Конструктор с выделением памяти для объекта всех нужных классов
GameDesk::GameDesk() {
	_setmode(_fileno(stdout), _O_U16TEXT);

	player = *(new Player(500));

	banker = *(new Banker());

	for (int i = 0; i < 4; i++)
		decks1.push_back(*(new Deck()));

	banker = *(new Banker());

}

// Главная функция класса
void GameDesk::startTheGame() {
	// Инициализируем все нужные флаги и переменные для игры
	int summeryPlayer = 0;
	int summeryBanker = 0;

	int gameNum = 0;

	bool flagGame = true;
	bool flagOfBet = true;
	bool flagOfProces = true;
	bool isHit = false;

	// Адаптер для колоды карт (есть метод format который принимает const Deck и возвращает отформатированное кол-во кард)
	DeckFormated deckFormated = *(new DeckFormated());

	while (flagGame) {

		// Если у вас на счету больше 0 то можно и поиграть
		if (player.getMoney() > 0) {
			wprintf(L"\n---- You want to start the Game (1-Yes, 2-No) ----\n");
			int answer = 0;

			cin >> answer;

			if (answer == 1) {

				// Если это уже не первая игра забераем все карты у диллера и игрока и берем новую колоду
				if (gameNum > 0) {

					for (int i = 0; i < 4; i++) {
						decks1[i].newDeck();
					}

					player.setNewCards();
					banker.setNewCards();

				}

				gameNum++;

				wprintf(L"\nYour balance: %.2f\n", player.getMoney());

				wprintf(L"\nYour bet?\n");
				bet = 0;


				while (flagOfBet) {
					cin >> bet;

					// Вводим ставку 
					if (bet <= 0)
					{
						wprintf(L"\n---- (Error) Your bet = 0 or smaller then 0!\n");

						// Чтобы можно повторно было ввести в cin
						std::cin.clear(); // clear bad input flag
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
					}
					else {
						double setBet = player.placeABet(bet);
						if (setBet > 0) {
							flagOfBet = false;
							continue;
						}
					}

					wprintf(L"\n---- Try again ----\n");
				}

				wprintf(L"\nYour bet: %.2f", bet);


				srand(time(NULL));

				// Логи показывающие, что проиходит на поле игры
				wprintf(L"\n ==== LOGS ==== \n");
				int randDeck = rand() % 4;
				player.getTheCard(banker.issueACard(decks1[randDeck]));
				
				randDeck = rand() % 4;
				player.getTheCard(banker.issueACard(decks1[randDeck]));

				randDeck = rand() % 4;
				banker.takeACard(decks1[randDeck]);
				wprintf(L"\n ==== END LOGS ==== \n");

				int answer;


				isHit = false;
				flagOfBet = true;
				flagOfProces = true;
				while (flagOfProces) {
					try {

						summeryPlayer = player.sumOfCard(true);
						// Если мы набрали больше 21 выбрасываем exception 
						if (summeryPlayer > 21) {
							throw 1;
						}

						// Выводим кол-во карт в колодах
						wprintf(L"\nDecks: ");
						
						// Вызов адаптера для нашего вывода
						for (int i = 0; i < 4; i++) wcout << L" [" << deckFormated.format(decks1[i]) << "]";
						wcout << endl;

						// Выводим все карты игрока и диллера (false для того чтобы А не предлагало выбирать каждый раз 11 или 1)
						banker.printAllCard();
						player.printAllCard(false);

						// Если мы уже взяли доп. карту откроется доп. метод
						if (!isHit)
							wprintf(L"\n Your turn! \n1. Stand \n2. Hit\n");
						else
							wprintf(L"\n Your turn! \n1. Stand \n2. Hit \n3. Double\n");

						cin >> answer;

						if (answer == 1) {
							flagOfProces = false;
							wprintf(L"\n Deck of cards:\n");


							summeryBanker = banker.sumOfCard();

							wprintf(L"\n ==== LOGS ==== \n");
							bool flagTake = true;
							// Диллер набирает карты в колоду ( по европейскому стилю, если у него меньше 17 то он берет еще )
							while (flagTake) {
								if (summeryBanker < 17 && banker.getCountOfCard() < 5) {
									randDeck = rand() % 4;
									banker.takeACard(decks1[randDeck]);
								}
								else
									flagTake = false;
								summeryBanker = banker.sumOfCard();
							}
							wprintf(L"\n ==== END LOGS ==== \n");

							// Выводим всю информацию перед финальным расчетом
							wprintf(L"\nDecks: ");
							for (int i = 0; i < 4; i++) wcout << L" [" << deckFormated.format(decks1[i]) << "]";
							wcout << endl;
							
							banker.printAllCard();
							player.printAllCard(true);

							// Передаем false т.к. нам уже нужно выбирать 1 или 11 (если есть А)
							summeryPlayer = player.sumOfCard(false);

							// Выбрасываем Exceptions если банкер наберет больше 21
							if (summeryBanker > 21) {
								throw 2;
							}
							else if (summeryPlayer > 21) {
								throw 1;
							}
							else if (summeryBanker > summeryPlayer) {
								wprintf(L"\n You lose: (Banker score)%i > %i(You score)", summeryBanker, summeryPlayer);
							}
							else if (summeryBanker == summeryPlayer) {
								wprintf(L"\n You lose: (Banker score)%i = %i(You score)", summeryBanker, summeryPlayer);
							}
							else {
								wprintf(L"\n You win: (Banker score)%i < %i(You score)", summeryBanker, summeryPlayer);
								double totalMoney = player.getMoney();
								totalMoney += bet * 2;

								player.setMoney(totalMoney);
							}

						}
						else if (answer == 2) {
							// Диллер выдает карту из рандомной калоды
							wprintf(L"\n ==== LOGS ==== \n");
							randDeck = rand() % 4;
							player.getTheCard(banker.issueACard(decks1[randDeck]));
							isHit = true;
							wprintf(L"\n ==== END LOGS ==== \n");
						}
						else if (answer == 3) {
							// Удвоение ставки если у нас достаточно средств
							if (isHit) {
								if (player.getMoney() >= bet) {
									player.placeABet(bet);

									bet = bet * 2;
								}
								else wprintf(L"\n == Not enough money! == \n");

								isHit = false;
							}
							else wprintf(L"\n == Wrong answer. Try again\n");
						}
						else {
							wprintf(L"\n == Wrong answer. Try again\n");

							std::cin.clear(); //clear bad input flag
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
						}
					}
					catch (int i) {
						if (i == 1) {
							flagOfProces = false;
							wprintf(L"\n You've lost: you have too much ((Your)%i > 21), Bet: %.2f. Final balance: %.2f", summeryPlayer, bet, player.getMoney());
							continue;
						}
						else if (i == 2) {
							wprintf(L"\n You've win: banker have too much ((Banker) %i > 21)", summeryBanker);
							double totalMoney = player.getMoney();
							totalMoney += bet * 2;

							player.setMoney(totalMoney);
						}
						else wprintf(L"\n (Num of Error: %i\n", i);
					}

				}

			}
			else if (answer == 2) {
				wprintf(L"\n Close the app!");
				flagGame = false;
				return;
			}
			else {
				wprintf(L"\n Wrong answer, try again! \n");

				std::cin.clear(); //clear bad input flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			}
		}
		else {
			wprintf(L"\n Your don't have money!");
			flagGame = false;
			continue;
		}
	}
}
