#pragma once
#include <functional>
#include "Book.h"
class BookSorter
{
public:
	BookSorter(int key) {
		key_ = key;
	}
	BookSorter() {
		key_ = 2;
	}
	bool operator()(Book* b1, Book* b2 ) {
		if (key_ == 1) {
			return b1->getAuthor() < b2->getAuthor();
		}
		return b1->getName() < b2->getName();
	}
private:
	int key_;
};