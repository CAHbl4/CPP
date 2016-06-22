// Task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Printer.h"


int _tmain(int argc, _TCHAR* argv[]) {

	Printer pr1;
	Client cl1("Client1");
	Job job(cl1, "1.txt", Time(12, 00, 00));
	pr1.AddJob(job.GetClient().GetDefaultPriority(), job);
	pr1.ShowQueue();

	system("pause");
	return 0;
}
