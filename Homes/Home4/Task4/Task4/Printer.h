#pragma once
#include "PriorityQueue.h"
#include "Job.h"

class Printer {
	PriorityQueue<Job> queue;
public:

	Printer() : queue(PriorityQueue<Job>(50)) { }

	void AddJob(Priority priority, Job job) {
		queue.Push(priority, job);
	}

	void ShowQueue() const {
		queue.Show();
	}

	~Printer() { }
};
