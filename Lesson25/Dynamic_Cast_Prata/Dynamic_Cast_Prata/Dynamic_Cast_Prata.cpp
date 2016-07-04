// Dynamic_Cast_Prata.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;


//������� �����
class Grand
{
private:
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "I am a grand class!\n"; }
	//���������� ����� ��������� �������� ��������� ���� hold (getter)
	virtual int GetValue() const { return hold; }
};

//������ ����� ���������
class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	//���������������� ����������� ����� Speak
	void Speak() const { cout << "I am a superb class!!\n"; }
	//����������� ����� ����������� ����� Say
	virtual void Say() const
	{
		cout << "I hold the superb value of " << GetValue() << "!\n";
	}
};

//����� ��������� ��������� (������������)
class Magnificent : public Superb
{
	//�������������� ���� 
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') : Superb(h), ch(c) {}
	//���������������� ����������� ����� Speak
	void Speak() const { cout << "I am a magnificent class!!!\n"; }
	//���������������� ����������� ����� Say
	void Say() const
	{
		cout << "I hold the character " << ch <<
		" and the integer " << GetValue() << "!\n";
	}
};

//������� �������� ������� � ����������� ��������� �� ��������� ������
Grand* GetOne();

int _tmain(int argc, _TCHAR* argv[])
{
		//��������� ��������� ��������� �����
		std::srand(std::time(0));
		//������� ��������� �� ������� ����� � ������� ����������
		Grand * pg;
		//��������� �� ������� ���������� ��������� ��� ������ ������ Say
		Superb * ps;
		for (int i = 0; i < 5; i++)
		{
			//������� ������ � �������� ���������, �������� ����� ��������� �������� ������
			pg = GetOne();
			//�������� ����� Speak
			pg->Speak();
			//�������� �������� ��������� �������� ������ � ��������� �� ������� ����������
			//��� ������ ������ Say
			//����� Say ��� ������� �������� ������ �� ���������� (��� ��� � ������� ������)
			if (ps = dynamic_cast<Superb *>(pg))
				ps->Say();
		}
		std::cin.get();
		return 0;
	}

//������� �������� ������� � ����������� ��������� �� ��������� ������
Grand * GetOne()    // generate one of three kinds of objects randomly
{
	Grand * p=NULL;
	//���������� ��������� ����� (0-2)
	switch (std::rand() % 3)
	{
		//���� 0 ������� ������ ������ Grand
	case 0: p = new Grand(std::rand() % 100);
		break;
		//���� 1 ������� ������ ������ Superb
	case 1: p = new Superb(std::rand() % 100);
		break;
		//���� 2 ������� ������ ������ Magnificent
	case 2: p = new Magnificent(std::rand() % 100,
		'A' + std::rand() % 26);
		break;
	}
	//���������� ��������� �� ��������� ������
	return p;
}



