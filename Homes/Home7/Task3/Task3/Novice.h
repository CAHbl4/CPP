#pragma once
#include "Man.h"

class Novice :
	public Man {
public:
	Novice(std::string name, int age, int expirience)
		: Man(name, age, expirience) {}

	bool Shoot() override {
		int chance = expirience;
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
