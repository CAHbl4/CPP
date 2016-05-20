#pragma once
#include "Material.h"

class Article
{
	char* name;
	Material material;
	float weight;
public:
	Article();

	void Show();

	~Article();
};

