// Task5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include <iostream>
#include <ctime>
#include <vector>
#include "Date2.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const int count = 1000000;
	vector<Date> v(count);
	int start = clock();
	for (int i = 0; i < count; ++i) {
		v[i] = 0x80000000 + i * 86400 * (rand() %31) ;
	}
	int end = clock();
	cout << "it took " << end - start << "ticks, or " << ((float)end - start) / CLOCKS_PER_SEC << "seconds." << endl;

	vector<Date2> v2(count);
	start = clock();
	for (int i = 0; i < count; ++i) {
		v2[i] = 0x80000000 + i * 86400 * (rand() % 31);
	}

	end = clock();
	cout << "it took " << end - start << "ticks, or " << ((float)end - start) / CLOCKS_PER_SEC << "seconds." << endl;

	system("pause");
	return 0;

}