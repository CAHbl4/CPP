#pragma once
#include "PriorityQueue.h"
#include "Job.h"

class Printer {
	PriorityQueue<Job> queue;
public:

	Printer(int queueSize = 50) : queue(PriorityQueue<Job>(queueSize)) { }

	void AddJob(Priority priority, Job job) {
		queue.Push(priority, job);
	}

	void ShowQueue() const {
		queue.Show();
	}

	~Printer() { }
};
