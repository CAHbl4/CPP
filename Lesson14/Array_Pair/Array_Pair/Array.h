#pragma once

template<class T1, class T2>
class Array {
	int size;
	Pair<T1, T2> *ptr;
public:
	Array(int size) : size(size) {
		ptr = new Pair<T1, T2>[size];
	}

	void SetArray() const {
		T1 a;
		T2 b;
		for (int i = 0; i < size; ++i) {
			cout << "Enter pair: ";
			cin >> a >> b;
			ptr[i].SetPair(a, b);
		}
	}

	void Show() {
		for (int i = 0; i < size; ++i) {
			ptr[i].ShowPair();
		}
	}

	~Array() {
		if (ptr)
			delete[] ptr;
	}

};

template<>
inline void Array<char*, char*>::SetArray() const {
	char str1[256], str2[256];
	for (int i = 0; i < size; ++i) {
		cout << "Enter pair: ";
		cin >> str1 >> str2;
		ptr[i].SetPair(str1, str2);
	}
}
