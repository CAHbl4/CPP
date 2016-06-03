// Bool_Operators_Overloading_Student.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Student.h"


int _tmain(int argc, _TCHAR* argv[]) {
	//Student st1;

	//cin >> st1;
	//cout << st1;

	//Student st2("Jon", "Snow", 20);
	//cout << st2;

	//Student *st3 = new Student("Max", "Mad", 23);

	//cout << *st3;

	//Student st4 = *st3;
	//delete st3;
	//cout << st4;

	//st4 = st1;
	//cout << st4;

	//(st4 == st1) ? cout << "Students are equal\n" : cout << "Students are not equal\n";

	Student *group;
	cout << "Enter size of group: ";
	int size;
	cin >> size;

	group = new Student[size];
	for (int i = 0; i < size; ++i) 
		cin >> group[i];

	for (int i = 0; i < size; ++i) 
		cout << group[i]; 
	
	system("pause");
	system("cls");

	Student search("1", "1", 0);
	for (int i = 0; i < size; ++i) 
	if (group[i] == search)
		cout << group[i];
	

	system("pause");
	return 0;
}
