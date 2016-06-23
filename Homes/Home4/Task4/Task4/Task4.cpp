// Task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Printer.h"


int _tmain(int argc, _TCHAR* argv[]) {

	Printer pr1;
	Client cl1("Client1");
	Client cl2("Client2", Low);
	Job job(cl1, "1.txt", Time(12, 00, 00));
	pr1.AddJob(job.GetClient().GetDefaultPriority(), job);
	job.SetClient(cl2);
	job.SetFileName("2.txt");
	pr1.AddJob(High, job);
	job.SetFileName("3.txt");
	pr1.AddJob(job.GetClient().GetDefaultPriority(), job);
	pr1.ShowQueue();
	pr1.PrintNext();
	pr1.ShowQueue();
	pr1.PrintAll();
	pr1.ShowQueue();

	pr1.ShowLog();

	system("pause");
	return 0;
}
