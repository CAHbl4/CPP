#pragma once
#include "Man.h"

class Skilled :
	public Man {
public:

	Skilled(std::string name, int age, int expirience)
		: Man(name, age, expirience) {}

	bool Shoot() override {
		int chance = expirience * 5;
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
