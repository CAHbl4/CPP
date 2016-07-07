// Methods_String.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	string s1("��� ������, ���������� �������.");
	string s2("���������");
	string s3("�����������, ");
	//�������� � ��������� ������� � ���������� ��������
	s1.erase(0, 12);              // ������� "��� ������, "
	cout << s1 << endl;
	//������ ������� � ��������� ������� � ���������� ���������
	s1.replace(11, 7, s2);        // �������� "�������" �� "���������"
	cout << s1 << endl;
	//������� � ��������� �������
	s1.insert(0, s3);             // ��������� "�����������, "
	cout << s1 << endl;
	//��������� ����� ������
	int n = s1.length();
	//��� n=s1.size();
	//������� ��������� ������
	s1.erase(n - 1, 1);
	//���������� � �����
	s1.append(3, '!'); //��������� !!!
	cout << s1 << endl;
	//������ ���� ������� �� ������ "
	//x - ��� ����������� ������� ������� �������
	int x;
	//���� ������� ������� �������
	x = s1.find(' ');
	while (x >= 0)
	{
		cout << "Pos=" << x << endl;
		//�������� ������ "
		s1.replace(x, 1, "%");
		//���������� ����� �� ��������� �������
		x=s1.find(' ', x + 1);
	}
	cout << s1 << endl;

	//����� ������� � � �����

	string s4 = "� \\���� \"�������� ������\", � ���� ��� �����.";
	cout << "--------------------------------------------\n" << s4 << endl;
	x = s4.find("������");
	if (x >= 0)
		cout << "������ ������� � ������� - " << x << endl;
	else
		cout << "������ �� �������" << endl;
	//����� �������
	x = s4.find("����");
	cout << "���� ������� � ������� - " << x << endl;
	//����� � �����
	x = s4.rfind("����");
	cout << "���� ������� � ������� - " << x << endl;

	//����� ��������, �������� � ������������������
	x = s4.find_first_of("��\"��");
	cout << "������ �� ��\"��: " << x + 1 << endl;
	//����� ��������, �� �������� � ������������������
	x = s4.find_first_not_of("�����");
	cout << "������ �� �� �������� �����: " << x + 1 << endl;

	//����� � �����
	n = s4.find_last_of("�����");
	cout << "��������� �� �����: " << n + 1 << endl;
	cout << "s[n]=" << s4[n] << endl;

	n = s4.find_last_not_of("����������");
	cout << "������ �� �� : " << n + 1 << endl;





	string s5 = "123 45";
	//�������� �� ������� �������
	int i = 0;
	while (s5.length())
	{
		//��������� �� ������� ��� ��������� ����������
		/*if (s5[i] == ' ')
			break;*/
		//����� �t ���������� ���������� out_of_range
		if (s5.at(i) == ' ')
			break;
		s5.erase(i, 1);
	}
	cout << s5 << endl;

	//��������� �����
	string Name = "Nick";
	string userName;
	cout << "������� ���� ���: ";
	cin >> userName;
	if (userName == Name)
		cout << "������, Nick\n";
	else if (userName < Name)
		cout << "���� ��� " << userName << " ���� �� ����� " << Name << "\n";
	else
		cout << "���� ��� " << userName << " ���� ����� ����� " << Name << "\n";

	//or
	if (Name.compare(userName) == 0)
		cout << "����� ���������" << endl;
	//�������� ���������� ������ ������ ���� ��������
	n = userName.compare(0, 2, Name, 0, 2);
	cout << "������ ��� ����� ������ ����� ";
	if (n == 0)
		cout << "��������� ";
	else if (n < 0)
		cout << "���� �� ";
	else
		cout << "���� ����� ";
	cout << Name.substr(0, 2) << endl;
	
	system("pause");
	return 0;
}

