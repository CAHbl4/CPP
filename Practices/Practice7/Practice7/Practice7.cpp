// Practice7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Commodity.h"
#include "AbstractPurchase.h"
#include "PurchaseDiscount1.h"
#include "PurchaseDiscount2.h"
#include "PurchaseTransport.h"
#include <vld.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Commodity commodity1("iPhone 6s", 600);
	Commodity commodity2("Samsung galaxy S6", 400);
	
	const int count = 6;
	AbstractPurchase* purchases[count];
	purchases[0] = new PurchaseDiscount1(commodity1, 3, 50);
	purchases[1] = new PurchaseDiscount1(commodity2, 4, 40);
	purchases[2] = new PurchaseDiscount2(commodity1, 8);
	purchases[3] = new PurchaseDiscount2(commodity2, 18);
	purchases[4] = new PurchaseTransport(commodity1, 50);
	purchases[5] = new PurchaseTransport(commodity2, 3);

	for (int i = 0; i < count; ++i) {
		purchases[i]->Show();
	}

	bool sorted = true;
	int i = 0, j = 0;
	AbstractPurchase* tmp;
	do {
		sorted = true;
		for (i = 0; i < count - j - 1; i++) {
			if (*purchases[i] > *purchases[i + 1]) {
				tmp = purchases[i];
				purchases[i] = purchases[i + 1];
				purchases[i + 1] = tmp;
				sorted = false;
			}
		}
		j++;
	} while (!sorted);

	cout << "-------------Sorted-------------\n";
	for (int i = 0; i < count; ++i) {
		purchases[i]->Show();

	}

	for (int i = 0; i < count; ++i) {
		delete purchases[i];

	}
	system("pause");

	return 0;
}

