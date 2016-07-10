#pragma once
#include <string>
#include <iostream>

class Man {
protected:
	std::string name;
	int age;
	int expirience;
public:


	Man(std::string name, int age, int expirience)
		: name(name),
		  age(age),
		  expirience(expirience) {}

	virtual bool Shoot() = 0;

	std::string GetName() const {
		return name;
	}

	friend std::ostream& operator<<(std::ostream& os, const Man& obj) {
		return os
			<< "Name: " << obj.name
			<< " age: " << obj.age
			<< " expirience: " << obj.expirience;
	}

	virtual ~Man() { }
};
