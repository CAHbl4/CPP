#pragma once
#include "Transport.h"
#include "Time.h"
#include <set>
#include "Train.h"

enum class WorkingDays {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

static const char* WorkingDaysStrings[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};

inline const char* WorkingDaysToString(int enumVal) {
	return WorkingDaysStrings[enumVal];
}

class Record {
	Transport* transport;
	Time departure;
	Time arrive;
	std::set<WorkingDays> workingDays;
public:
	Record(Transport* transport = nullptr, const Time& departure = Time(), const Time& arrive = Time(), const std::set<WorkingDays>& workingDayses = std::set<WorkingDays>())
		: transport(transport),
		  departure(departure),
		  arrive(arrive),
		  workingDays(workingDayses) { }

	Record(const Record& other)
		: transport(other.transport),
		  departure(other.departure),
		  arrive(other.arrive),
		  workingDays(other.workingDays) {}

	Record(Record&& other)
		: transport(std::move(other.transport)),
		  departure(std::move(other.departure)),
		  arrive(std::move(other.arrive)),
		  workingDays(std::move(other.workingDays)) {}

	Record& operator=(const Record& other) {
		if (this == &other)
			return *this;
		transport = other.transport;
		departure = other.departure;
		arrive = other.arrive;
		workingDays = other.workingDays;
		return *this;
	}

	Record& operator=(Record&& other) {
		if (this == &other)
			return *this;
		transport = std::move(other.transport);
		departure = std::move(other.departure);
		arrive = std::move(other.arrive);
		workingDays = std::move(other.workingDays);
		return *this;
	}

	void Save(std::ofstream& out) const {
		transport->Save(out);
		int time = int(departure);
		out.write(reinterpret_cast<const char*>(&time), sizeof(int));
		time = int(arrive);
		out.write(reinterpret_cast<const char*>(&time), sizeof(int));
		int count = workingDays.size();
		out.write(reinterpret_cast<const char*>(&count), sizeof(int));
		for (WorkingDays workingDay : workingDays) {
			out.write(reinterpret_cast<const char*>(&workingDay), sizeof(WorkingDays));
		}
	}

	std::ifstream& Load(std::ifstream& in) {
		char t;
		in.read(&t, 1);
		switch (t) {
		case 't':
			transport = new Train();
			transport->Load(in);
		}
		int time;
		in.read(reinterpret_cast<char*>(&time), sizeof(int));
		departure = Time(time /3600, time /60 % 60);
		in.read(reinterpret_cast<char*>(&time), sizeof(int));
		arrive = Time(time / 3600, time / 60 % 60);
		int count;
		in.read(reinterpret_cast<char*>(&count), sizeof(int));
		WorkingDays day;
		workingDays.clear();
		for (int i = 0; i < count; ++i) {
			in.read(reinterpret_cast<char*>(&day), sizeof(WorkingDays));
			workingDays.insert(day);
		}
		return in;
	}

	Time GetDeparture() const {
		return departure;
	}

	void SetDeparture(const Time& departure) {
		this->departure = departure;
	}

	Time GetArrive() const {
		return arrive;
	}

	void SetArrive(const Time& arrive) {
		this->arrive = arrive;
	}

	Time TravelTime() const {
		if (departure > arrive)
			return Time(24) + arrive - departure;
		return arrive - departure;
	}

	void AddWorkingDay(WorkingDays day) {
		workingDays.insert(day);
	}

	void RemoveWorkingDay(WorkingDays day) {
		workingDays.erase(day);
	}


	friend bool operator==(const Record& lhs, const Record& rhs) {
		return lhs.transport == rhs.transport
			&& lhs.departure == rhs.departure
			&& lhs.arrive == rhs.arrive
			&& lhs.workingDays == rhs.workingDays;
	}

	friend bool operator!=(const Record& lhs, const Record& rhs) {
		return !(lhs == rhs);
	}

	friend bool operator<(const Record& lhs, const Record& rhs) {
		return lhs.TravelTime() < rhs.TravelTime();
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
		os
			<< *obj.transport << "\t"
			<< obj.departure << "\t"
			<< obj.arrive << "\t"
			<< obj.TravelTime() << "\t";
		for (WorkingDays workingDay : obj.workingDays) {
			os << WorkingDaysToString(int(workingDay)) << " ";
		}
		return os;
	}
};
