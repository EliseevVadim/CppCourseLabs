#pragma once
#include "Deck.h"
#include "Player.h"
class Game
{
public:
	Game();
	Game(bool empty);
	~Game();
	void giveCardToPlayer(bool dealer);
	void printInfoAboutDecks();
	void play();
	void getAmount();
	void printPlayersHand(bool dealer);
	void printGameInfo();
	bool checkForContinue();
private:
	Deck* decks[4];
	Player* players[2];
	int amount_;
	bool started_;
	bool player_stoped_;
	bool comp_stoped_;
	bool isSplit_;
};

