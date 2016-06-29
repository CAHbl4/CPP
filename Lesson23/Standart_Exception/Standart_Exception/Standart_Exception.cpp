// Standart_Exception.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
#include<stdexcept>

#include <string>

using namespace std;

//пользовательский класс исключений, наследник exception
class MyException :public exception
{
public:
	MyException(const char* str) :exception(str)
	{
	}
	const char* what()
	{
		char* str = "MyException.what()!!!";
		return str;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		char a,b;
		a = 35;
		b = 130;
		//класс string из библиотеки STL
		string str = "1,2,3";
		cout << str.at(5) << endl;

		cout << "a=" << int(a) << ", b=" << int(b)  << endl;
		//throw overflow_error("Overflow Error!!!");
		cout << "a+b=" << a + b << endl;

		//throw MyException("MyError!!!");
		//throw exception("Error!!!");
	}
	catch (out_of_range& e)
	{
		cout << "Out of range\n" << e.what() << endl;
	}
	catch (overflow_error& e)
	{
		cout << e.what() << endl;
	}
	catch (MyException& e)
	{
		cout << "MyException!!!\n";
		cout << e.what() << endl;
	}
	catch (exception& e)
	{
		cout << "Standart exception!!!\n";
		cout << e.what() << endl;
	}
	
	system("pause");
	return 0;
}

