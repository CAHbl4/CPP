#pragma once
#include "Commodity.h"

class AbstractPurchase {
protected:
	Commodity commodity;
	int count;
public:
	AbstractPurchase(const Commodity& commodity = Commodity(), int count = 0)
		: commodity(commodity),
		  count(count) {}

	Commodity GetCommodity() const {
		return commodity;
	}

	void SetCommodity(const Commodity& commodity) {
		this->commodity = commodity;
	}

	int GetCount() const {
		return count;
	}

	void SetCount(int count) {
		this->count = count;
	}

	virtual int GetCost() const {
		return commodity.GetPrice() * count;
	}


	friend bool operator<(const AbstractPurchase& lhs, const AbstractPurchase& rhs) {
		return lhs.CompareTo(rhs);
	}

	friend bool operator<=(const AbstractPurchase& lhs, const AbstractPurchase& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const AbstractPurchase& lhs, const AbstractPurchase& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const AbstractPurchase& lhs, const AbstractPurchase& rhs) {
		return !(lhs < rhs);
	}

	virtual void Show() const {
		commodity.Show();
		std::cout << "Count: " << count << std::endl
			<< "Cost: " << GetCost() << std::endl << std::endl;
	}

	bool CompareTo(const AbstractPurchase& other) const {
		return GetCost() < other.GetCost();
	}

	virtual ~AbstractPurchase() { }
};
