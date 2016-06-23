#pragma once
#include "Computer.h"
#include <ostream>

class Notebook : public Computer {
protected:
	int autonomousTime;
public:


	Notebook(int cpuClock, int cpuCores, int ramSize, int hddSize, int autonomousTime = 0)
		: Computer(cpuClock, cpuCores, ramSize, hddSize),
		  autonomousTime(autonomousTime) {}

	int Cost() const override {
		return Computer::Cost() + autonomousTime / 10;
	}

	bool IsGood() const override {
		return Computer::IsGood() && autonomousTime >= 60;
	}

	friend std::ostream& operator<<(std::ostream& os, const Notebook& obj) {
		return os
			<< static_cast<const Computer&>(obj)
			<< " autonomousTime: " << obj.autonomousTime;
	}
};
