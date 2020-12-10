#pragma once
#include <vector>
#include "Card.h"
class Player
{
public:
	Player();
	~Player();
	void setCredits(int credits);
	int getCredits() const;
	void openHand();
	void addNewHand();
	void deleteNewHand();
	int getSum();
	int getExtraSum();
	friend class Game;
protected:	
	int sum_;
	int extra_sum_;
	std::vector<Card>hand;
private:
	std::vector<Card> additional_hand;
	bool new_hand_;
	int credits_;
};