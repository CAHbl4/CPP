#pragma once
#include "AbstractPurchase.h"

class PurchaseDiscount1 : public AbstractPurchase {
	int discount;
public:

	PurchaseDiscount1(const Commodity& commodity = Commodity(), int count = 0, int discount = 0)
		: AbstractPurchase(commodity, count),
		  discount(discount) {}

	double GetDiscount() const {
		return discount;
	}

	void SetDiscount(int discount) {
		this->discount = discount;
	}

	int GetCost() const override {
		return (commodity.GetPrice() - discount) * count;
	}


	void Show() const override{
		std::cout << "Purchase with const discount\n";
		AbstractPurchase::Show();
	}
};
