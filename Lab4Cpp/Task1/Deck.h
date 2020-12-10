#pragma once
#include <vector>
#include "Card.h"
class Deck
{
public:
	Deck();
	~Deck();
	void printCount();
	int getDeckSum();
	int getCount();
	Card giveCard();
	Card getCardPerIndex(int idx) const;
private:
	std::vector<Card*> cards;
};