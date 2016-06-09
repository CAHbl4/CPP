#include "stdafx.h"
#include "Overcoat.h"

Overcoat::Overcoat(const String& name, OvercoatTypes type, float price)
	: name(name),
	  type(type),
	  price(price) {}

Overcoat::Overcoat(const Overcoat& other)
	: name{other.name},
	  type{other.type},
	  price{other.price} {}

Overcoat::Overcoat(Overcoat&& other)
	: name{std::move(other.name)},
	  type{other.type},
	  price{other.price} {}

Overcoat& Overcoat::operator=(const Overcoat& other) {
	if (this == &other)
		return *this;
	name = other.name;
	type = other.type;
	price = other.price;
	return *this;
}

Overcoat& Overcoat::operator=(Overcoat&& other) {
	if (this == &other)
		return *this;
	name = std::move(other.name);
	type = other.type;
	price = other.price;
	return *this;
}

const char* OvercoatTypesStr[OvercoatTypesCount] = {
	"Greatcoat",
	"Redingote",
	"Frock overcoat",
	"Ulster coat",
	"Inverness Coat",
	"Paletot Coat",
	"Paddock Coat",
	"Chesterfield Coat"};

std::ostream& operator<<(std::ostream& os, OvercoatTypes c) {
	return os << OvercoatTypesStr[c];
}
