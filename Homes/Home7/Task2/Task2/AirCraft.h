#pragma once
#include <string>
#include <iostream>

class AirCraft {
protected:
	std::string mark;
	std::string model;
	int maxSpeed;
	int maxHeight;
public:
	AirCraft(std::string mark, std::string model, int maxSpeed, int maxHeight)
		: mark(mark),
		  model(model),
		  maxSpeed(maxSpeed),
		  maxHeight(maxHeight) {}

	virtual int Cost() const {
		return maxSpeed * 1000 + maxHeight * 100;
	}

	void Info() const {
		std::cout
			<< "Mark: " << mark << std::endl
			<< "Model: " << model << std::endl
			<< "Max speed: " << maxSpeed << " km/h" << std::endl
			<< "Max height: " << maxHeight << " m" << std::endl
			<< "Cost: $" << Cost() << std::endl;
	}

	virtual ~AirCraft() { }
};
