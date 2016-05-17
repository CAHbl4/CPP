#pragma once
class Man
{
	char name[20];
	char surname[20];
	int age;
public:
	//������������
	Man();
	Man(const char *str_name, const char *str_surname, int value);

	//�������
	const char* GetName() const;
	const char* GetSurName() const;
	int GetAge() const;

	//�������
	void SetName(const char* str);
	void SetSurName(const char* str);
	void SetAge(int value);

	//��������� ������
	void Passport();

	//����������
	~Man();
};

