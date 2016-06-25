#pragma once
#include "Date.h"
#include "String.h"

enum PenaltyTypes{SpeedLimit,DoubleLine,RedSignal};
const char* PenaltyText[] = {"���������� ��������", "���������� ������� �������� ����� ��������", "������ �� ������� ������ ���������"};

class Penalty
{
	Date date;
	PenaltyTypes type;
	String �omment;
	int value;
public:
	Penalty(Date date = Date(0), PenaltyTypes type = PenaltyTypes(), String �omment = String(), int value = 0)
		: date(date),
		  type(type),
		  �omment(�omment),
		  value(value) {}

	friend std::ostream& operator<<(std::ostream& os, const Penalty& obj) {
		return os
			<< "����: " << obj.date << std::endl
			<< "���������: " << PenaltyText[obj.type] << std::endl
			<< "�����������: " << obj.�omment << std::endl
			<< "�����: " << obj.value << " ���." << std::endl;
	}
};

