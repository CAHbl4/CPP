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


	friend std::ostream& operator<<(std::ostream& os, const Client& obj) {
		return os << "name: " << obj.name;
	}
};
