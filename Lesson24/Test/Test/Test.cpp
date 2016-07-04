// Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

class A {
public:
	int a;
	A(int a = 0) :a(a){}
};

class B : public A {
public:
	void b() {
		std::cout << "Func B.b()\n";
	}
};

struct my_vptr {
	int fptr[1];
};

void f() {
	std::cout << "Func f()\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
	my_vptr vptr;
	A* ptrA = new A[2]{1, 2};

	std::cout << "Size *ptrA = " << sizeof *ptrA << std::endl;

	std::cout << "ptrA[0].a = " << ptrA[0].a << std::endl;
	std::cout << "ptrA[1].a = " << ptrA[1].a << std::endl;

	std::cout << "Adress f() = " << &f << std::endl;
	vptr.fptr[0] = reinterpret_cast<int>(&f);

	//ptrA[0] = reinterpret_cast<int>(&vptr);
	std::cout << "ptrA[0].a = " << ptrA[0].a << std::endl;

	B* ptrB;
	ptrB = static_cast<B*>(ptrA);

	std::cout << "Size *ptrB = " << sizeof *ptrB << std::endl;

	std::cout << "*ptrB.a = " << ptrB->a << std::endl;
	ptrB->b();

	delete ptrB;

	std::cout << "ptrA[0].a = " << ptrA[0].a << std::endl;
	std::cout << "ptrA[1].a = " << ptrA[1].a << std::endl;

	system("pause");
	
	return 0;
}

