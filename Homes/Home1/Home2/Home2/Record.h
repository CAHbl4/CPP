#pragma once
class Record
{
	char* name;
	char* surname;
	char* patronymic;
	char* phone;
public:
	Record();

	void SetName(const char* str);
	void SetSurname(const char* str);
	void SetPatronymic(const char* str);
	void SetPhone(const char* str);

	char* GetName();
	char* GetSurname();
	char* GetPatronymic();
	char* GetPhone();

	void Show();

	~Record();
};

