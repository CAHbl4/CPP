#pragma once
#include "Material.h"
#include <string>
#include <iostream>

class Camera {
protected:
	std::string model;
	double zoom;
	Material caseMaterial;
public:
	Camera(std::string model, double zoom, Material caseMaterial)
		: model(model),
		zoom(1),
		caseMaterial(caseMaterial) {
		SetZoom(zoom);
	}

	std::string GetModel() const {
		return model;
	}

	void SetModel(const std::string& model) {
		this->model = model;
	}

	double GetZoom() const {
		return zoom;
	}

	void SetZoom(double zoom) {
		if (zoom >= 1 && zoom <= 35)
			this->zoom = zoom;
		else
			std::cerr << "Zoom should be between 1 and 35\n";
	}

	Material GetCaseMaterial() const {
		return caseMaterial;
	}

	void SetCaseMaterial(Material caseMaterial) {
		this->caseMaterial = caseMaterial;
	}

	virtual double Cost() const {
		switch (caseMaterial) {
		case Material::Metal: return (zoom + 2) * 15;
		case Material::Plastic: return (zoom + 2) * 10;
		}
		return 0;
	}

	bool IsExpensive() const {
		return Cost() > 200;
	}

	virtual void Info() const {
		std::cout
			<< "Model: " << model << std::endl
			<< "Zoom: " << zoom << std::endl
			<< "Cost: " << Cost() << std::endl;
	}

	virtual ~Camera() {}
};
