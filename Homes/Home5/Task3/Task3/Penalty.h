#pragma once
#include "Date.h"
#include "String.h"

enum PenaltyTypes{SpeedLimit,DoubleLine,RedSignal};
const char* PenaltyText[] = {"Превышение скорости", "Пересчение двойной сплошной линии разметки", "Проезд на красный сигнал светофора"};

class Penalty
{
	Date date;
	PenaltyTypes type;
	String сomment;
	int value;
public:
	Penalty(Date date = Date(0), PenaltyTypes type = PenaltyTypes(), String сomment = String(), int value = 0)
		: date(date),
		  type(type),
		  сomment(сomment),
		  value(value) {}

	friend std::ostream& operator<<(std::ostream& os, const Penalty& obj) {
		return os
			<< "Дата: " << obj.date << std::endl
			<< "Нарушение: " << PenaltyText[obj.type] << std::endl
			<< "Комментарий: " << obj.сomment << std::endl
			<< "Штраф: " << obj.value << " руб." << std::endl;
	}
};

