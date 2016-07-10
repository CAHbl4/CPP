#pragma once
#include "Man.h"
#include <iostream>

class Veteran :
	public Man {
public:
	Veteran(std::string name, int age, int expirience)
		: Man(name, age, expirience) {}

	bool Shoot() override {
		int chance = 90 - age;
		int result = rand() % 100;
		if (result < chance){
			std::cout << name << " hit target with " << chance << "% chance. Rand value = " << result << std::endl;
			return true;
		}
		else {
			std::cout << name << " missing target with " << chance << "% chance. Rand value = " << result << std::endl;
			return false;
		}
	}
};
