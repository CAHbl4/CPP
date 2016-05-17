// Counter_Multi_Files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Counter.h"

int main()
{
	{
		Counter c1(3);
		c1.Show();
		Counter c2;
		c2.Show();

		Counter arr[3];
		for (auto i = 0; i < 3; i++)
		{
			arr[i].Show();
		}

		for (auto i = 0; i < 3; ++i)
		{
			arr[i].set_current(i);
		}

		for (auto i = 0; i < 3; ++i)
		{
			arr[i].Show();
		}
	}
	return 0;
}