#pragma once
#include "Transport.h"

enum class TrainType {International, Regional, Local};
static const char* TrainTypeStrings[] = { "International", "Regional", "Local" };

inline const char* TrainTypeToString(int enumVal) {
	return TrainTypeStrings[enumVal];
}

class Train :
	public Transport
{
	int number;
	TrainType type;
public:
	Train(const std::string& from = std::string(), const std::string& to = std::string(), int number = 0, TrainType type = TrainType::Local)
		: Transport(from, to),
		  number(number),
		  type(type) {}

	virtual void Save(std::ofstream& out) override {
		char t = 't';
		out.write(&t, 1);
		out.write(reinterpret_cast<const char*>(&number), sizeof(int));
		out.write(reinterpret_cast<const char*>(&type), sizeof(TrainType));
		Transport::Save(out);
	}


	virtual std::ifstream& Load(std::ifstream& in) override{
		in.read(reinterpret_cast<char*>(&number), sizeof(int));
		in.read(reinterpret_cast<char*>(&type), sizeof(TrainType));
		Transport::Load(in);
		return in;
	}

	friend std::ostream& operator<<(std::ostream& os, const Train& obj) {
		return os
			<< "Train " << obj.number << " \""
			<< static_cast<const Transport&>(obj)
			<< "\" (" << TrainTypeToString(int(obj.type))
			<< ")";
	}
};

