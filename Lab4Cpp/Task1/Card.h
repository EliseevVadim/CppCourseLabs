#pragma once
#include <string>
#include "io.h"
#include "fcntl.h"
#include <iostream>
#include "Suit.h"
class Card
{
public:
	Card(std::wstring content, int value, Suit suit);
	~Card();
	int getValue() const;
	std::wstring getPrintInterpretation() const;
	Suit getSuit() const;
	wchar_t getSuitInSymbol() const;
	friend std::wostream& operator<<(std::wostream& out, const Card& card);
private:
	std::wstring content_;
	int value_;
	wchar_t suit_in_symbol_;
	Suit suit_;
};