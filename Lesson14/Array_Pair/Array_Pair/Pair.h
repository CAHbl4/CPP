#pragma once

template <class T1, class T2>
class Pair {
	T1 one;
	T2 two;
public:
	Pair(T1 one = 0, T2 two = 0) : one(one), two(two) {}
	void SetPair(T1 one, T2 two){
		this->one = one;
		this->two = two;
	}
	void ShowPair() const {
		cout << one << " : " << two << endl;
	}
};


template <>
class Pair<char*, int> {
	char* one;
	int two;
public:
	Pair(char* str = "\0", int two = 0);
	void SetPair(char* str, int two);
	void ShowPair() const;
	~Pair();
};

template <>
class Pair<char*, char*> {
	char* one;
	char* two;
public:
	Pair(char* str1 = "\0", char* str2 = "\0");
	void SetPair(char* str1, char* str2);
	void ShowPair() const;
	~Pair();
};
