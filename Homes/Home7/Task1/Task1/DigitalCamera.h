#pragma once
#include "Camera.h"
class DigitalCamera :
	public Camera
{
	int megaPixels;
public:
	DigitalCamera(std::string model, double zoom, Material caseMaterial, int megaPixels)
		: Camera(model, zoom, caseMaterial),
		megaPixels(megaPixels) {}

	double Cost() const override{
		return Camera::Cost() * megaPixels;
	}


	void Info() const override{
		Camera::Info();
		std::cout << "Megapixels: " << megaPixels << std::endl;
	}

	void Upgrade() {
		megaPixels += 2;
	}

};

