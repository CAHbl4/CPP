#pragma once

class Flat {
	float square;
	float price;
public:

	Flat(float square, float price)
		: square(square),
		  price(price) {}

	Flat& operator=(const Flat& other) {
		if (this == &other)
			return *this;
		square = other.square;
		price = other.price;
		return *this;
	}

	friend bool operator==(const Flat& lhs, const Flat& rhs) {
		return lhs.square == rhs.square;
	}

	friend bool operator!=(const Flat& lhs, const Flat& rhs) {
		return !(lhs == rhs);
	}

	friend bool operator<(const Flat& lhs, const Flat& rhs) {
		return lhs.price < rhs.price;
	}

	friend bool operator<=(const Flat& lhs, const Flat& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const Flat& lhs, const Flat& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Flat& lhs, const Flat& rhs) {
		return !(lhs < rhs);
	}


	friend std::ostream& operator<<(std::ostream& os, const Flat& obj) {
		return os
			<< "Square: " << obj.square
			<< "\t\tPrice: " << obj.price;
	}
};
