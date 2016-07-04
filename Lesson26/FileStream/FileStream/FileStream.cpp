// FileStream.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//для работы с файлами
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//запись данных в файл
	int a = 2;
	double pi = 3.14;
	char* str = "One!!!";
	

	//создание файлового потока
	try
	{
		fstream file("test.txt", ios::out);   //out - запись в файл
		if (!file)
			throw exception ("Error...");
		file << "a=" << a << ", pi= " << pi << ", str=" << str << endl;
		//после работы с файлом его надо закрыть
		file.close();

		//считывание данных из текстового файла
		fstream filein("test.txt", ios::in);		//in - чтение
		if (!file)
			throw exception("Error...");
		char str[256];
		filein >> str;		//считывает до пробела
		cout << str << endl;	

		//полное считывание файла
		filein.seekp(ios::beg);//устанавливаем указатель на начало файла
		char result[256];
		result[0] = '\0';
		//организовываем цикл пока не будет достигнут конец файла
		while (!filein.eof())
		{
			filein >> str;
			strcat_s(result, 256, str);
			cout << str << endl;
		}
		filein.close();
		cout << result << endl;
		//вариант 2
		cout << "-----------Variant 2-----------------\n";
		fstream f2("test.txt", ios::in);
		if (!f2)
			throw exception("Error...");
		char str2[256];
		while (f2.getline(str2,256))
		{
			//f2.getline(str2, 5);
			cout << str2<<endl;
		}
		f2.close();
		//вариант 3
		cout << "-----------Variant 3-----------------\n";
		fstream f3("test.txt", ios::in);
		if (!f3)
			throw exception("Error...");
		//считывание посимвольно
		char сh;
		while (!f3.eof())
		{
			сh=f3.get();
			cout <<сh;
		}
		f3.close();
		//вариант 4
		cout << "-----------Variant 4-----------------\n";
		fstream f4("test1.txt", ios::in);
		if (!f4)
			throw exception("Error...");
		//считывание из буфера
		cout << f4.rdbuf();
		f4.close();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}

