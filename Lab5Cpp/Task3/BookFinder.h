#pragma once
#include "Book.h"
class BookFinder
{
public:
	BookFinder(int start, int last) {
		start_year_ = start;
		last_year_ = last;
	}
	bool operator()(Book* book) {
		return book->getYear() >= start_year_ && book->getYear() <= last_year_;
	}
private:
	int start_year_;
	int last_year_;
};