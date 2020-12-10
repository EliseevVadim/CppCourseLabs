#include "Player.h"
#include "Game.h"
#include <ctime>
Player::Player() {
	credits_ = 10000;
	sum_ = 0;	
	new_hand_ = false;
	extra_sum_ = 0;
}
Player::~Player() {
	hand.clear();
	additional_hand.clear();
}
int Player::getCredits() const {
	return credits_;
}
void Player::setCredits(int credits) {
	credits_ = credits;
}
void Player::openHand() {
	hand.reserve(5);
}
void Player::addNewHand() {
	additional_hand.reserve(5);
	new_hand_ = true;
}
void Player::deleteNewHand() {
	additional_hand.clear();
	new_hand_ = false;
}
int Player::getSum() {
	return sum_;
}
int Player::getExtraSum() {
	return extra_sum_;
}