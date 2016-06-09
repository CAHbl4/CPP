#pragma once
#include "String.h"

enum OvercoatTypes {
	Greatcoat,
	Redingote,
	FrockOvercoat,
	UlsterCoat,
	InvernessCoat,
	PaletotCoat,
	PaddockCoat,
	ChesterfieldCoat,
	OvercoatTypesCount
};								 //https://en.wikipedia.org/wiki/Overcoat

std::ostream& operator<<(std::ostream& os, enum OvercoatTypes c);

class Overcoat {
	String name;
	enum OvercoatTypes type;
	float price;
public:
	Overcoat(const String& name = "\0", OvercoatTypes type = Greatcoat, float price = 0);
	Overcoat(const Overcoat& other);
	Overcoat(Overcoat&& other);

	Overcoat& operator=(const Overcoat& other);
	Overcoat& operator=(Overcoat&& other);

	friend bool operator==(const Overcoat& lhs, const Overcoat& rhs) {
		return lhs.type == rhs.type;
	}

	friend bool operator!=(const Overcoat& lhs, const Overcoat& rhs) {
		return !(lhs == rhs);
	}

	friend bool operator<(const Overcoat& lhs, const Overcoat& rhs) {
		return lhs.price < rhs.price;
	}

	friend bool operator<=(const Overcoat& lhs, const Overcoat& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const Overcoat& lhs, const Overcoat& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Overcoat& lhs, const Overcoat& rhs) {
		return !(lhs < rhs);
	}


	friend std::ostream& operator<<(std::ostream& os, const Overcoat& obj) {
		return os
			<< "Name: " << obj.name << std::endl
			<< "Type: " << obj.type << std::endl
			<< "Price: " << obj.price << std::endl;
	}
};
