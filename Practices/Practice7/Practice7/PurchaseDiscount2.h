#pragma once
#include "AbstractPurchase.h"

class PurchaseDiscount2 : public AbstractPurchase {
	const double discount = 5.0;
	const int countForDiscount = 15;
public:
	PurchaseDiscount2(const Commodity& commodity = Commodity(), int count = 0, double discount = 5.0, int countForDiscount = 15)
		: AbstractPurchase(commodity, count),
		  discount(discount),
		  countForDiscount(countForDiscount) {}

	int GetCost() const override {
		return (count >= countForDiscount) ?
			       int(commodity.GetPrice() * count * (1 - discount / 100)) :
			       AbstractPurchase::GetCost();
	}

	void Show() const override{
		std::cout << "Purchase with discount based on count\n";
		AbstractPurchase::Show();
	}
};
