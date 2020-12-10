#include "Game.h"
#include "Dealer.h"
#include "BlackJackException.h"
#include "EqualException.h"
#include "LoseAtPointsException.h"
#include "WinAtPointsException.h"
#include "OutOfScoreException.h"
#include <Windows.h>
#include <stdio.h>
#include <ctime>
Game::Game() {
	for (int i = 0; i < 4; i++) {
		decks[i] = new Deck();
	}
	players[0] = new Player();
	players[0]->setCredits(1000);
	players[1] = new Dealer();
	started_ = true;
	player_stoped_ = false;
	comp_stoped_ = false;
	isSplit_ = false;
}
Game::Game(bool empty) {

}
Game::~Game() {
	delete[] decks;
}
void Game::giveCardToPlayer(bool dealer) {
	srand(time(NULL));
	if (dealer) {
		if (!comp_stoped_) {
			Card card = decks[rand() % 4]->giveCard();
			players[1]->hand.push_back(card);
			players[1]->sum_ += card.getValue();
		}
		if (players[1]->getSum() == 21) {
			throw BlackJackException();
		}
		if (players[1]->getSum() > 21) {
			throw OutOfScoreException();
		}
		if (players[0]->getSum() == players[1]->getSum()&&player_stoped_&&comp_stoped_) {
			throw EqualException();
		}
		if (players[0]->getSum() < players[1]->getSum() && player_stoped_ && comp_stoped_) {
			throw WinAtPointsException();
		}
		if (players[0]->getSum() > players[1]->getSum() && player_stoped_&& comp_stoped_) {
			throw LoseAtPointsException();
		}
	}
	else
	{
		if (!isSplit_) {
			Card card = decks[rand() % 4]->giveCard();
			players[0]->hand.push_back(card);
			players[0]->sum_ += card.getValue();
			if (players[0]->getSum() == 21) {
				throw BlackJackException();
			}
			if (players[0]->getSum() > 21) {
				throw OutOfScoreException();
			}
			if (players[0]->getSum() == players[1]->getSum() && player_stoped_ && comp_stoped_) {
				throw EqualException();
			}
		}
		else {
			Card card = decks[rand() % 4]->giveCard();
			players[0]->additional_hand.push_back(card);
			players[0]->extra_sum_ += card.getValue();
			if (players[0]->getExtraSum() == 21) {
				throw BlackJackException();
			}
			if (players[0]->getExtraSum() > 21) {
				throw OutOfScoreException();
			}
			if (players[0]->getExtraSum() == players[1]->getSum() && player_stoped_ && comp_stoped_) {
				throw EqualException();
			}
		}
	}
}
void Game::printPlayersHand(bool dealer) {
	if (dealer) {
		for (size_t i = 0; i < players[1]->hand.size(); i++)
		{
			std::wcout.width(5);
			std::wcout << players[1]->hand[i];
		}
		std::wcout.width(5);
		std::wcout << "??";
	}
	else
	{
		if (!isSplit_) {
			for (size_t i = 0; i < players[0]->hand.size(); i++)
			{
				std::wcout.width(5);
				std::wcout << players[0]->hand[i];
			}
		}
		else {
			for (size_t i = 0; i < players[0]->hand.size(); i++)
			{
				std::wcout.width(5);
				std::wcout << players[0]->hand[i];
			}
			std::wcout << L"\nДополнительная рука: ";
			for (size_t i = 0; i < players[0]->additional_hand.size(); i++)
			{
				std::wcout.width(5);
				std::wcout << players[0]->additional_hand[i];
			}
		}
	}
}
void Game::printInfoAboutDecks() {
	for (int i = 0; i < 4; i++) {
		decks[i]->printCount();
	}
	std::wcout << "\n";
}
void Game::printGameInfo() {
	if (!isSplit_) {
		std::cout << "Колоды:";
		printInfoAboutDecks();
		std::cout << "\nДилер:";
		printPlayersHand(true);
		std::wcout << L"\nВы:";
		printPlayersHand(false);
		std::wcout << L"\n\n1.Хватит";
		std::wcout << L"\n2.Еще\n";
		std::wcout << L"3.Сплит?\n";
	}
	else {
		std::cout << "Колоды:";
		printInfoAboutDecks();
		std::cout << "\nДилер:";
		printPlayersHand(true);
		std::wcout << L"\nВы:";
		printPlayersHand(false);
		std::wcout << L"\n\n1.Хватит";
		std::wcout << L"\n2.Еще\n";
	}
}
void Game::getAmount() {
	int candidate = 0;
	std::cout << "Ваша ставка?\n";
	std::cin >> candidate;
	if (candidate > 0 && candidate <= players[0]->getCredits()) {
		amount_ = candidate;
		system("cls");
	}
	else
	{
		std::wcout << L"Ошибка ставки\n";
		system("pause");
		system("cls");
		getAmount();
	}
}
void Game::play() {
	wchar_t answer;
	getAmount();
	players[1]->openHand();
	giveCardToPlayer(true);
	players[0]->openHand();
	giveCardToPlayer(false);
	printGameInfo();
	int requiredValue = 0;
	int allval = 0;
	int allcount = 0;
	int average = 0;
	while (started_)
	{
		std::wcin >> answer;
		switch (answer)
		{
		case L'1':
			system("cls");
			player_stoped_ = true;
			while (!comp_stoped_) {
				requiredValue = 21 - players[1]->sum_;
				allval = 0;
				allcount = 0;
				for (int i = 0; i < 4; i++) {
					allval += decks[i]->getDeckSum();
					allcount += decks[i]->getCount();
				}
				average = allval / allcount;
				if (average <= requiredValue) {
					try {
						giveCardToPlayer(true);
					}
					catch (BlackJackException) {
						if (!isSplit_) {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() - amount_);
							std::wcout << L"\nВы проиграли! Ваш проигрыш: " << std::to_wstring(amount_) << L". Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
						else {
							printGameInfo();
							std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
					}
					catch (OutOfScoreException) {
						if (!isSplit_) {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() + amount_);
							std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(amount_) << L" Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
						else {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() + (2 * amount_));
							std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(2*amount_) << L" Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
					}
				}
				else
				{
					comp_stoped_ = true;
					try {
						giveCardToPlayer(true);
					}
					catch (BlackJackException) {
						if (!isSplit_) {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() - amount_);
							std::wcout << L"\nВы проиграли! Ваш проигрыш: " << std::to_wstring(amount_) << L". Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
						else {
							printGameInfo();
							std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
					}
					catch (OutOfScoreException) {
						if (!isSplit_) {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() + amount_);
							std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(amount_) << L" Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
						else {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() + (2 * amount_));
							std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(amount_*2) << L" Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
					}
					catch (WinAtPointsException) {
						if (!isSplit_) {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() - amount_);
							std::wcout << L"\nВы проиграли! Ваш проигрыш: " << std::to_wstring(amount_) << L". Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
						else {
							if (players[0]->getExtraSum() > players[1]->getSum()) {
								printGameInfo();
								std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
							else if (players[0]->getExtraSum() < players[1]->getSum()) {
								printGameInfo();
								players[0]->setCredits(players[0]->getCredits() - amount_);
								std::wcout << L"\nВы проиграли! Ваш проигрыш: " << std::to_wstring(amount_) << L". Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
							else {
								printGameInfo();
								players[0]->setCredits(players[0]->getCredits() - amount_ / 2);
								std::wcout << L"\nВы проиграли! Ваш проигрыш: " << std::to_wstring(amount_/2) << L". Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
						}
					}
					catch (EqualException) {
						if (!isSplit_) {
							printGameInfo();
							std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
						}
						else {
							if (players[0]->getExtraSum() > players[1]->getSum()) {
								printGameInfo();
								players[0]->setCredits(players[0]->getCredits() + 3 * amount_ / 2);
								std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(3*amount_/2) << L" Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
							else if (players[0]->getExtraSum() < players[1]->getSum()) {
								printGameInfo();
								players[0]->setCredits(players[0]->getCredits() - amount_ / 2);
								std::wcout << L"\nВы проиграли! Ваш проигрыш: " << std::to_wstring(amount_ / 2) << L". Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
							else {
								printGameInfo();
								std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
						}
					}
					catch (LoseAtPointsException) {
						if (!isSplit_) {
							printGameInfo();
							players[0]->setCredits(players[0]->getCredits() + amount_);
							std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(amount_) << L" Всего: " << std::to_wstring(players[0]->getCredits());
							started_ = false;
							break;
						}
						else {
							if (players[0]->getExtraSum() > players[1]->getSum()) {
								printGameInfo();
								players[0]->setCredits(players[0]->getCredits() + amount_ * 2);
								std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(amount_ * 2) << L" Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
							else if (players[0]->getExtraSum() < players[1]->getSum()) {
								printGameInfo();
								std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
							else {
								printGameInfo();
								players[0]->setCredits(players[0]->getCredits() + 3 * amount_ / 2);
								std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(3 * amount_ / 2) << L" Всего: " << std::to_wstring(players[0]->getCredits());
								started_ = false;
								break;
							}
						}
					}
				}
			}
			started_ = false;
			break;
		case L'2':
			system("cls");
			try {
				giveCardToPlayer(false);
			}
			catch (BlackJackException) {
				printGameInfo();
				players[0]->setCredits(players[0]->getCredits() + amount_);
				std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(amount_) << L" Всего: " << std::to_wstring(players[0]->getCredits());
				started_ = false;
				break;
			}
			catch (OutOfScoreException) {
				printGameInfo();
				players[0]->setCredits(players[0]->getCredits() - amount_);
				std::wcout << L"\nПеребор! Вы проиграли! Ваш проигрыш: " << std::to_wstring(amount_) << L". Всего: " << std::to_wstring(players[0]->getCredits());
				started_ = false;
				break;
			}
			printGameInfo();
			break;
		case L'3':
			system("cls");
			players[0]->addNewHand();
			isSplit_ = true;
			try {
				giveCardToPlayer(false);
			}
			catch (BlackJackException) {
				if (players[0]->getSum() > players[1]->getSum()) {
					printGameInfo();
					players[0]->setCredits(players[0]->getCredits() + amount_*2);
					std::wcout << L"\nПоздравляем! Вы выиграли! Ваш выигрыш " << std::to_wstring(amount_*2) << L" Всего: " << std::to_wstring(players[0]->getCredits());
					started_ = false;
					break;
				}
				else {
					printGameInfo();
					std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
				}
			}
			catch (OutOfScoreException) {
				if (players[0]->getSum() > players[1]->getSum()) {
					printGameInfo();
					std::wcout << L"\nНичья! Ваша ставка " << std::to_wstring(amount_) << L" сохранена. Всего: " << std::to_wstring(players[0]->getCredits());
					break;
				}
				else {
					printGameInfo();
					players[0]->setCredits(players[0]->getCredits() - amount_);
					std::wcout << L"\nПеребор! Вы проиграли! Ваш проигрыш: " << std::to_wstring(amount_) << L". Всего: " << std::to_wstring(players[0]->getCredits());
				}
			}
			printGameInfo();
			break;
		default:
			system("cls");
			started_ = false;
			break;
		}
	}	
}
bool Game::checkForContinue() {
	std::wcout << L"\n1.Продолжить\n2.Выход\n";
	wchar_t answer;
	std::wcin >> answer;
	switch (answer)
	{
	case L'1':
		system("cls");
		started_ = true;
		comp_stoped_ = false;
		player_stoped_ = false;
		isSplit_ = false;
		players[0]->sum_ = 0;
		players[1]->sum_ = 0;
		players[0]->hand.clear();
		players[1]->hand.clear();
		players[0]->extra_sum_ = 0;
		players[0]->deleteNewHand();
		return true;
	default:
		return false;
	}
}