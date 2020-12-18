#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "CacheOverflowException.h"
#include "SymbolsComparer.h"
template <class T>
class Cache
{
public:
	Cache() {
		cache_vector.reserve(10);
	}
	void put(T elem) {
		cache_vector.push_back(elem);
	}
	void operator+=(T elem) {
		cache_vector.push_back(elem);
	}
	bool contains(T elem) {
		return std::find(cache_vector.begin(), cache_vector.end(), elem)!=cache_vector.end();
	}
private:
	std::vector<T> cache_vector;
};
template<>
class Cache<std::string> {
public:
	Cache() {
		cache_vector.reserve(10);
	}
	void put(std::string elem) {
		if (cache_vector.size() < 100) {
			cache_vector.push_back(elem);
		}
		else
		{
			throw new CacheOverflowException;
		}
	}
	void operator+=(std::string elem) {
		cache_vector.push_back(elem);
	}
	bool contains(std::string elem) {
		SymbolsComparer comparer(elem);
		return std::find_if(cache_vector.begin(), cache_vector.end(), comparer) != cache_vector.end();
	}
private:
	std::vector<std::string> cache_vector;
};