#pragma once
#include "String.h"

class Commodity {
	String name;
	int price;
public:
	Commodity(const String& name = "/0", int price = 0)
		: name(name),
		  price(price) {}

	String GetName() const {
		return name;
	}

	void SetName(const String& name) {
		this->name = name;
	}

	int GetPrice() const {
		return price;
	}

	void SetPrice(int price) {
		this->price = price;
	}

	void Show() const {
		std::cout << "Name: " << name << "\nPrice: " << price << std::endl;
	}
};
