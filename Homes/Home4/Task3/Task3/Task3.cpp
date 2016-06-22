// Task3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"

int CheckString(char* str) {
	int i = 0;
	Stack<char> stack(strlen(str));
	while (str[i] != ';' && str[i] != '\0') {
		switch (str[i]){
		case '(':
		case '[':
		case '{':
		case '<':
			stack.Push(str[i]);
			break;
		case ')':
			if (stack.Pop() != '(')
				return i;
			break;
		case ']':
			if (stack.Pop() != '[')
				return i;
			break;
		case '}':
			if (stack.Pop() != '{')
				return i;
			break;
		case '>':
			if (stack.Pop() != '<')
				return i;
			break;
		default:
			break;
		}
		++i;
	}
	return stack.Empty() ? 0 : i;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[256];
	cout << "Enter string for check: ";
	cin >> str;
	int result = CheckString(str);
	if (result) {
		cout << "Check failed on " << result << " position: ";
		for (int i = 0; i <= result; ++i) {
			cout << str[i];
		}
		cout << endl;
	} else {
		cout << "String is correct.\n";
	}

	system("pause");
	return 0;
}

