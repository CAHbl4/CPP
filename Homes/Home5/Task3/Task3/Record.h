#pragma once
#include "LinkedList.h"
#include "Penalty.h"

class Record {
	int number;
	LinkedList<Penalty> list;
public:
	Record(int number = 0)
		: number(number), list(LinkedList<Penalty>()) {}

	void AddPenalty(Date date, PenaltyTypes type, String comment, int value) {
		list.Add(Penalty(date, type, comment, value));
	}

	void AddPenalty(Penalty penalty) {
		list.Add(penalty);
	}

	int GetNumber() const {
		return number;
	}

	void SetNumber(int number) {
		this->number = number;
	}

	LinkedList<Penalty>& GetList() {
		return list;
	}

	void SetList(const LinkedList<Penalty>& list) {
		this->list = list;
	}

	friend bool operator==(const Record& lhs, const Record& rhs) {
		return lhs.number == rhs.number;
	}

	friend bool operator!=(const Record& lhs, const Record& rhs) {
		return !(lhs == rhs);
	}

	friend bool operator<(const Record& lhs, const Record& rhs) {
		return lhs.number < rhs.number;
	}

	friend bool operator<=(const Record& lhs, const Record& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const Record& lhs, const Record& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Record& lhs, const Record& rhs) {
		return !(lhs < rhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const Record& obj) {
		os << "================================\n"
		 <<"Номер: " << obj.number << std::endl
		 << "Количество нарушений: " << obj.list.GetUpperBound() + 1 << std::endl
		 << "Список нарушений:\n"
		 << "--------------------------------\n";
		for (int i = 0; i <= obj.list.GetUpperBound(); ++i) {
			os << obj.list[i] << std::endl;
		}
		return os;
	}

};
