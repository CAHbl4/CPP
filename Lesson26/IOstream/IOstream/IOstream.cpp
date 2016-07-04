// IOstream.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
//для работы манипуляторов
#include<iomanip>

using namespace std;

 
int _tmain(int argc, _TCHAR* argv[])
{
	//работа с флагами
	int a = 100, b = 200;
	float x = 1.25, pi = 3.14;
	char ch1 = 'A', ch2 = 'z';
	bool f1 = true, f2 = false;
	//стандартный вывод
	cout << "a=" << a << ", b=" << b << endl;
	cout << "x=" << x << ", pi=" << pi << endl;
	cout << "ch1=" << ch1 << ", ch2=" << ch2 << endl;
	cout << "f1=" << f1 << ", f2=" << f2 << endl;
	//использование флагов
	cout << "----------------------------------\n";
	cout.unsetf(ios::dec);
	cout << "a=";
	cout.setf(ios::oct);
	cout << a;
	cout<< ", b=";
	cout.unsetf(ios::oct);
	cout.setf(ios::hex);
	cout << b<<endl;
	cout.setf(ios::scientific);
	cout << "x=" << x << endl;
	cout.setf(ios::uppercase);
	cout << "b=" << b << endl;
	cout << "x=" << x << endl;
	cout.unsetf(ios::scientific);
	 
	//использование манипуляторов
	cout << "----------------------------------\n";
	cout << "a=" <<oct<< a << ", b=" <<hex<< b << endl;
	cout << setw(10)<<resetiosflags(ios::right)<<setiosflags(ios::left)<<"x=" <<setprecision(1)<< x << setw(10)<<setfill('0')<<", pi=" << pi << endl;
	cout << "ch1=" << ch1 << ", ch2=" << ch2 << endl;
	cout << "f1=" <<setiosflags(ios::boolalpha)<< f1 << ", f2=" << f2 << endl;

	//классы istream и ostream
	cout << "----------------------------------\n";
	cout << "Enter string:";
	char str[256];
	cin.get(str,5);
	cout << str << endl;
	cout << "Enter string:";
	fflush(stdin);
	cin >> str;
	cout << str << endl;
	cout << "Enter string:";
	fflush(stdin);
	cin.getline(str,256);
	cout << str << endl;
	cout << "Enter string:";
	fflush(stdin);
	cin.getline(str,256,'$');
	cout << str << endl;

	system("pause");
	return 0;
}

