#pragma once
#include "AbstractPurchase.h"
class PurchaseTransport : public AbstractPurchase
{
	const int transportPrice = 100;
public:

	PurchaseTransport(const Commodity& commodity = Commodity(), int count = 0, int transportPrice = 100)
		: AbstractPurchase(commodity, count),
		  transportPrice(transportPrice) {}


	int GetCost() const override{
		return AbstractPurchase::GetCost() + transportPrice;
	}

	void Show() const override{
		std::cout << "Purchase with transport\n";
		AbstractPurchase::Show();
	}
};