// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void ShowMenu();


int _tmain(int argc, _TCHAR* argv[]) {
	ReservoirList list;
	Reservoir tmp;
	
	tmp.SetName("Pool1");
	tmp.SetType(Pool);
	tmp.SetWidth(3);
	tmp.SetLength(4);
	tmp.SetMaxDepth(2);

	list.Add(tmp);

	tmp.SetName("Pool2");
	tmp.SetType(Pool);
	tmp.SetWidth(4);
	tmp.SetLength(3);
	tmp.SetMaxDepth(2);

	list.Add(tmp);

	tmp.SetName("Lake1");
	tmp.SetType(Lake);
	tmp.SetWidth(300);
	tmp.SetLength(700);
	tmp.SetMaxDepth(6);

	list.Add(tmp);

	list[0].Compare(list[1]);
	list[0].Compare(list[2]);

	//list.Remove(3);
	system("pause");

	char selector;
	do {
		system("cls");
		ShowMenu();
		cout << "Select menu item: ";
		cin >> selector;
		switch (selector) {
		case '1':
			system("cls");
			cin >> tmp;
			list.Add(tmp);
			break;
		case '2':
			{
				system("cls");
				int index;
				cout << "Enter record index to delete: ";
				cin >> index;
				list.Remove(index);
			}
			break;
		case '3':
			system("cls");
			list.Show();
			break;
		case '4':
			{
				system("cls");
				int result = list.Export(EXPORT_FILE_NAME);
				if (result >= 0)
					cout << "Succesfully exported " << result << " items.\n";
				else
					cout << "Export failed!\n";
			}
			break;
		case'5':
			{
				system("cls");
				int result = list.Save(SAVE_FILE_NAME);
				if (result >= 0)
					cout << "Succesfully saved " << result << " items.\n";
				else
					cout << "Save failed!\n";
				break;
			}
		case'6':
			{
				system("cls");
				int result = list.Load(SAVE_FILE_NAME);
				if (result >= 0)
					cout << "Succesfully loaded " << result << " items.\n";
				else
					cout << "Load failed!\n";
				break;
			}
		case '0':
			system("cls");
			cout << "Good bye!\n";
			break;
		default:
			system("cls");
			cout << "Wrong selection. Try again.\n\n";
			break;
		}
		system("pause");
	}
	while (selector != '0');
	return 0;
}


void ShowMenu() {
	cout
		<< "Main menu:\n"
		<< "1. Add item to list\n"
		<< "2. Delete item from list\n"
		<< "3. Show list\n"
		<< "4. Export list to text file\n"
		<< "5. Save list to file\n"
		<< "6. Read list from file\n"
		<< "0. Exit\n";
}
