#include "stdafx.h"
#include "Pair.h"


Pair<char*, int>::Pair(char* str, int two) : two(two) {
	one = new char[strlen(str) + 1];
	strcpy_s(one, strlen(str) + 1, str);
}


void Pair<char*, int>::SetPair(char* str, int two) {
	if (one)
		delete[] one;
	one = new char[strlen(str) + 1];
	strcpy_s(one, strlen(str) + 1, str);
	this->two = two;
}


void Pair<char*, int>::ShowPair() const {
	cout << one << " : " << two << endl;
}


Pair<char*, int>::~Pair() {
	if (one)
		delete[] one;
}


Pair<char*, char*>::Pair(char* str1, char* str2) {
	one = new char[strlen(str1) + 1];
	strcpy_s(one, strlen(str1) + 1, str1);
	two = new char[strlen(str2) + 1];
	strcpy_s(two, strlen(str2) + 1, str2);
}


void Pair<char*, char*>::SetPair(char* str1, char* str2) {
	if (one)
		delete[] one;
	if (two)
		delete[] two;
	one = new char[strlen(str1) + 1];
	strcpy_s(one, strlen(str1) + 1, str1);
	two = new char[strlen(str2) + 1];
	strcpy_s(two, strlen(str2) + 1, str2);
}


void Pair<char*, char*>::ShowPair() const {
	cout << one << " : " << two << endl;
}


Pair<char*, char*>::~Pair() {
	if (one)
		delete[] one;
	if (two)
		delete[] two;
}
