#pragma once
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
		cout << first << " : " << second;
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
