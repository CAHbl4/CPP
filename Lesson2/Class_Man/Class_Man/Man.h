#pragma once
class Man
{
	char name[20];
	char surname[20];
	int age;
public:
	//Конструкторы
	Man();
	Man(const char *str_name, const char *str_surname, int value);

	//Геттеры
	const char* GetName() const;
	const char* GetSurName() const;
	int GetAge() const;

	//Сеттеры
	void SetName(const char* str);
	void SetSurName(const char* str);
	void SetAge(int value);

	//Публичные методы
	void Passport();

	//Деструктор
	~Man();
};

