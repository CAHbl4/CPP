#pragma once
class Material
{
	char* name;
	float price;

public:
	Material();

	float GetPrice();
	void Show();

	~Material();
};