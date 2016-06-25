#pragma once
#include <iostream>
template <class T1, class T2>
class Pair {
	T1 first;
	T2 second;
public:
	Pair(T1 first = T1(), T2 second = T2()) : first(first), second(second) {}

	void SetPair(T1 first, T2 second) {
		this->first = first;
		this->second = second;
	}

	void ShowPair() {
		std::cout << first << " : " << second;
	}

	T1 GetFirst() const {
		return first;
	}

	T2 GetSecond() const {
		return second;
	}

	friend bool operator<(const Pair& lhs, const Pair& rhs) {
		if (lhs.first < rhs.first)
			return true;
		if (rhs.first < lhs.first)
			return false;
		return lhs.second < rhs.second;
	}

	friend bool operator<=(const Pair& lhs, const Pair& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const Pair& lhs, const Pair& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Pair& lhs, const Pair& rhs) {
		return !(lhs < rhs);
	}
};
