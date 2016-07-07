// Methods_String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	string s1("Все хорошо, прекрасная маркиза.");
	string s2("принцесса");
	string s3("Приветствую, ");
	//удаление с указанной позиции и количество символов
	s1.erase(0, 12);              // убираем "Все хорошо, "
	cout << s1 << endl;
	//замена начиная с указанной позиции и количество сисмволов
	s1.replace(11, 7, s2);        // заменяем "маркиза" на "принцесса"
	cout << s1 << endl;
	//вставка с указанной позиции
	s1.insert(0, s3);             // вставляем "Приветствую, "
	cout << s1 << endl;
	//получение длины строки
	int n = s1.length();
	//или n=s1.size();
	//удаляем последний символ
	s1.erase(n - 1, 1);
	//добавление в конец
	s1.append(3, '!'); //добавляем !!!
	cout << s1 << endl;
	//замена всех пробело на символ "
	//x - для определения текущей позиции пробела
	int x;
	//ищем позицию первого пробела
	x = s1.find(' ');
	while (x >= 0)
	{
		cout << "Pos=" << x << endl;
		//заменяем пробел "
		s1.replace(x, 1, "%");
		//продолжаем поиск со следующей позиции
		x=s1.find(' ', x + 1);
	}
	cout << s1 << endl;

	//поиск сначала и с конца

	string s4 = "В \\лесу \"родилась елочка\", в лесу она росла.";
	cout << "--------------------------------------------\n" << s4 << endl;
	x = s4.find("елочка");
	if (x >= 0)
		cout << "елочка найдена в позиции - " << x << endl;
	else
		cout << "елочка не найдена" << endl;
	//поиск сначала
	x = s4.find("лесу");
	cout << "лесу найдено в позиции - " << x << endl;
	//поиск с конца
	x = s4.rfind("лесу");
	cout << "лесу найдено в позиции - " << x << endl;

	//поиск символов, входящих в последовательность
	x = s4.find_first_of("ёк\"мн");
	cout << "Первый из ёк\"мн: " << x + 1 << endl;
	//поиск символов, не входящих в последовательность
	x = s4.find_first_not_of("ёклмн");
	cout << "Первый из не входящих ёклмн: " << x + 1 << endl;

	//поиск с конца
	n = s4.find_last_of("ёклмн");
	cout << "Последний из ёклмн: " << n + 1 << endl;
	cout << "s[n]=" << s4[n] << endl;

	n = s4.find_last_not_of("абвгдАБВГД");
	cout << "Первый не из : " << n + 1 << endl;





	string s5 = "123 45";
	//удаление до первого пробела
	int i = 0;
	while (s5.length())
	{
		//обращение по индексу без генерации исключения
		/*if (s5[i] == ' ')
			break;*/
		//метод аt генерирует исключение out_of_range
		if (s5.at(i) == ' ')
			break;
		s5.erase(i, 1);
	}
	cout << s5 << endl;

	//сравнение строк
	string Name = "Nick";
	string userName;
	cout << "Введите Ваше имя: ";
	cin >> userName;
	if (userName == Name)
		cout << "Привет, Nick\n";
	else if (userName < Name)
		cout << "Ваше имя " << userName << " идет до имени " << Name << "\n";
	else
		cout << "Ваше имя " << userName << " идет после имени " << Name << "\n";

	//or
	if (Name.compare(userName) == 0)
		cout << "Имена совпадают" << endl;
	//проверка совпадения только первых двух символов
	n = userName.compare(0, 2, Name, 0, 2);
	cout << "Первые две буквы Вашего имени ";
	if (n == 0)
		cout << "совпадают ";
	else if (n < 0)
		cout << "идут до ";
	else
		cout << "идут после ";
	cout << Name.substr(0, 2) << endl;
	
	system("pause");
	return 0;
}

