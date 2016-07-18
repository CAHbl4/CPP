#pragma once
#include <string>
#include <fstream>

class Transport
{
protected:
	std::string from;
	std::string to;
public:
	Transport(const std::string& from, const std::string& to)
		: from(from),
		  to(to) {}

	virtual void Save(std::ofstream& out) {
		int len = from.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(int));
		out.write(reinterpret_cast<const char*>(from.data()), len);
		len = to.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(int));
		out.write(reinterpret_cast<const char*>(to.data()), len);
	}

	virtual std::ifstream& Load(std::ifstream& in) {
		int len;
		char* str;
		in.read(reinterpret_cast<char*>(&len), sizeof(int));
		str = new char[len + 1];
		in.read(str, len);
		str[len] = '\0';
		from.assign(str);
		delete[]str;
		in.read(reinterpret_cast<char*>(&len), sizeof(int));
		str = new char[len + 1];
		in.read(str, len);
		str[len] = '\0';
		to.assign(str);
		delete[]str;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& os, const Transport& obj) {
		return os
			<< obj.from << " -> " << obj.to;
	}

	friend bool operator==(const Transport& lhs, const Transport& rhs) {
		return lhs.from == rhs.from
			&& lhs.to == rhs.to;
	}

	friend bool operator!=(const Transport& lhs, const Transport& rhs) {
		return !(lhs == rhs);
	}

	virtual ~Transport() {}
};

