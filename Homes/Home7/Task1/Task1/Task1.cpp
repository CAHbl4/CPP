// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Camera.h"
#include "DigitalCamera.h"

char* BoolToStr(bool b) {
	return b ? "True" : "False";
}


int _tmain(int argc, _TCHAR* argv[]) {

	Camera cam1("Kodak 100", 4, Material::Plastic);
	DigitalCamera cam2("Canon 5D", 3, Material::Metal, 8);
	cam1.Info();
	std::cout << "Expensive: " << BoolToStr(cam1.IsExpensive()) << std::endl << std::endl;

	cam2.Info();
	std::cout << "Expensive: " << BoolToStr(cam2.IsExpensive()) << std::endl << std::endl;

	cam2.Upgrade();
	cam2.Info();
	std::cout << "Expensive: " << BoolToStr(cam2.IsExpensive()) << std::endl << std::endl;

	system("pause");
	return 0;
}
