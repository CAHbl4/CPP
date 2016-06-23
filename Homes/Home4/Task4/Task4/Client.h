#pragma once
#include "String.h"
#include "Priority.h"

class Client {
	String name;
	Priority defaultPriority;
public:

	Client(String name = String(), Priority defaultPriority = Normal)
		: name(name),
		  defaultPriority(defaultPriority) {}

	String GetName() const {
		return name;
	}

	void SetName(const String& name) {
		this->name = name;
	}

	Priority GetDefaultPriority() const {
		return defaultPriority;
	}

	void SetDefaultPriority(Priority defaultPriority) {
		this->defaultPriority = defaultPriority;
	}

	friend bool operator==(const Client& lhs, const Client& rhs) {
		return lhs.name == rhs.name
			&& lhs.defaultPriority == rhs.defaultPriority;
	}

	friend bool operator!=(const Client& lhs, const Client& rhs) {
		return !(lhs == rhs);
	}


	friend bool operator<(const Client& lhs, const Client& rhs) {
		return lhs.defaultPriority < rhs.defaultPriority;
	}

	friend bool operator<=(const Client& lhs, const Client& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const Client& lhs, const Client& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Client& lhs, const Client& rhs) {
		return !(lhs < rhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const Client& obj) {
		return os << "name: " << obj.name;
	}
};
