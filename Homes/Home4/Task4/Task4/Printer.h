#pragma once
#include "PriorityQueue.h"
#include "Job.h"
#include "PrinterLog.h"

class Printer {
	PriorityQueue<Job> queue;
	PrinterLog log;
public:

	Printer(int queueSize = 50) : queue(PriorityQueue<Job>(queueSize)) { }

	void AddJob(Priority priority, Job job) {
		queue.Push(priority, job);
	}

	void ShowQueue() const {
		if (!queue.Empty())
			queue.Show();
		else std::cout << "Queue is empty.\n";
	}

	void PrintNext() {
		log << queue.Pop().GetSecond();
	}

	void PrintAll() {
		while (!queue.Empty())
			PrintNext();
	}

	void ShowLog() const {
		std::cout << "Print log: \n";
		log.ShowLog();
	}
};
