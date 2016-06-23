#pragma once
#include "String.h"
#include "Time.h"
#include "Client.h"

class Job {
	Client client;
	String fileName;
	Time timeAdded;
public:
	Job(Client client = Client(), String fileName = String(), Time timeAdded = Time())
		: client(client),
		  fileName(fileName),
		  timeAdded(timeAdded) {}

	Client GetClient() const {
		return client;
	}

	void SetClient(const Client& client) {
		this->client = client;
	}

	String GetFileName() const {
		return fileName;
	}

	void SetFileName(const String& fileName) {
		this->fileName = fileName;
	}

	Time GetTimeAdded() const {
		return timeAdded;
	}

	void SetTimeAdded(const Time& timeAdded) {
		this->timeAdded = timeAdded;
	}

	friend bool operator==(const Job& lhs, const Job& rhs) {
		return lhs.client == rhs.client
			&& lhs.fileName == rhs.fileName
			&& lhs.timeAdded == rhs.timeAdded;
	}

	friend bool operator!=(const Job& lhs, const Job& rhs) {
		return !(lhs == rhs);
	}

	friend bool operator<(const Job& lhs, const Job& rhs) {
		return lhs.timeAdded < rhs.timeAdded;
	}

	friend bool operator<=(const Job& lhs, const Job& rhs) {
		return !(rhs < lhs);
	}

	friend bool operator>(const Job& lhs, const Job& rhs) {
		return rhs < lhs;
	}

	friend bool operator>=(const Job& lhs, const Job& rhs) {
		return !(lhs < rhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const Job& obj) {
		return os
			<< "client: " << obj.client
			<< " fileName: " << obj.fileName
			<< " timeAdded: " << obj.timeAdded;
	}

	~Job() {}
};
