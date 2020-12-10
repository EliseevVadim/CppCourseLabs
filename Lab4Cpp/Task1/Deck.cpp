#include "Deck.h"
#include <ctime>
Deck::Deck() {
	srand(time(NULL));
	int seed = rand() % 2;
	std::wstring names[3] = { L"J", L"Q" , L"K"};
	int pos = 0;
	switch (seed)
	{
	case 0:
		
		cards.reserve(36);
		for (int i = 6; i <= 10; i++) {
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Club));
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Diamond));
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Hearts));
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Spades));
		}
		for (int i = 0; i < 3; i++) {
			cards.push_back(new Card(names[i], 10, Suit::Club));
			cards.push_back(new Card(names[i], 10, Suit::Diamond));
			cards.push_back(new Card(names[i], 10, Suit::Hearts));
			cards.push_back(new Card(names[i], 10, Suit::Spades));
		}
		cards.push_back(new Card(L"A", 11, Suit::Club));
		cards.push_back(new Card(L"A", 11, Suit::Diamond));
		cards.push_back(new Card(L"A", 11, Suit::Hearts));
		cards.push_back(new Card(L"A", 11, Suit::Spades));
		break;
	case 1:
		cards.reserve(52);
		for (int i = 2; i <= 10; i++) {
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Club));
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Diamond));
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Hearts));
			cards.push_back(new Card(std::to_wstring(i), i, Suit::Spades));
		}
		for (int i = 0; i < 3; i++) {
			cards.push_back(new Card(names[i], 10, Suit::Club));
			cards.push_back(new Card(names[i], 10, Suit::Diamond));
			cards.push_back(new Card(names[i], 10, Suit::Hearts));
			cards.push_back(new Card(names[i], 10, Suit::Spades));
		}
		cards.push_back(new Card(L"A", 11, Suit::Club));
		cards.push_back(new Card(L"A", 11, Suit::Diamond));
		cards.push_back(new Card(L"A", 11, Suit::Hearts));
		cards.push_back(new Card(L"A", 11, Suit::Spades));
		break;
	}
}
Deck::~Deck() {
	cards.clear();
}
void Deck::printCount() {
	std::wcout.width(5);
	std::wcout<<"["<<cards.size()<<"]";
}
int Deck::getDeckSum() {
	int ds = 0;
	for (int i = 0; i < cards.size(); i++) {
		ds += cards[i]->getValue();
	}
	return ds;
}
int Deck::getCount() {
	return cards.size();
}
Card Deck::giveCard() {
	srand(time(NULL));
	int index = rand() % cards.size();
	Card buff = *cards[index];
	cards.erase(cards.begin() + index);	
	return buff;
}
Card Deck::getCardPerIndex(int idx) const {
	return *cards[idx];
}