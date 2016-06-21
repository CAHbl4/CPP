// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "functions.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	int arr1[10] = {5, 2, 6, 4, 8, 1, 7, 8, 2, 7};
	char arr2[10] = {'a', 'c', 'd', 'g', 'E', 'Z', 'A', 'd', 'T', 'D'};


	cout << "--------------------MIN---------------------\n";
	cout << "arr1[" << min(arr1, 10) - arr1 << "] = " << *min(arr1, 10) << endl;
	cout << "arr2[" << min(arr2, 10) - arr2 << "] = " << *min(arr2, 10) << endl;

	cout << "--------------------MAX---------------------\n";
	cout << "arr1[" << max(arr1, 10) - arr1 << "] = " << *max(arr1, 10) << endl;
	cout << "arr2[" << max(arr2, 10) - arr2 << "] = " << *max(arr2, 10) << endl;

	cout << "-------------------SORT---------------------\n";
	for (int i = 0; i < 10; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	sort(arr1, 10);

	for (int i = 0; i < 10; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	sort(arr2, 10);

	for (int i = 0; i < 10; ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	cout << "-------------------SEARCH-------------------\n";
	cout << "arr1[" << bsearch(arr1, 10, 2) - arr1 << "] = " << *bsearch(arr1, 10, 2) << endl;
	cout << "arr2[" << bsearch(arr2, 10, 'g') - arr2 << "] = " << *bsearch(arr2, 10, 'g') << endl;

	cout << "------------------REPLACE-------------------\n";
	replace(arr1, 10, 4, 4);
	for (int i = 0; i < 10; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	replace(arr2, 10, 6, 'W');

	for (int i = 0; i < 10; ++i) {
		cout << arr2[i] << " ";
	}
	cout << endl;

 	system("pause");
	return 0;
}
