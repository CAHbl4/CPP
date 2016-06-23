#pragma once
class Computer {
protected:
	int CPUClock;
	int CPUCores;
	int RAMSize;
	int HDDSize;

public:
	Computer(int cpuClock = 0, int cpuCores = 0, int ramSize = 0, int hddSize = 0)
		: CPUClock(cpuClock),
		  CPUCores(cpuCores),
		  RAMSize(ramSize),
		  HDDSize(hddSize) {}

	virtual int Cost() const {
		return CPUClock * CPUCores / 100
			+ RAMSize / 80
			+ HDDSize / 20;
	}

	virtual bool IsGood() const {
		return CPUClock >= 2000 && CPUCores >= 2 && RAMSize >= 2048 && HDDSize >= 320;
	}

	friend std::ostream& operator<<(std::ostream& os, const Computer& obj) {
		return os
			<< "CPUClock: " << obj.CPUClock
			<< " CPUCores: " << obj.CPUCores
			<< " RAMSize: " << obj.RAMSize
			<< " HDDSize: " << obj.HDDSize;
	}

	virtual ~Computer() {}
};
