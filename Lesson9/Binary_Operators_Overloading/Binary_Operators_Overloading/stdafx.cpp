// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// Binary_Operators_Overloading.pch будет предкомпилированным заголовком
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"

// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле


Test operator+(int lval, const Test& rval){
	int tmp;
	tmp = lval + rval.GetData();
	return Test(tmp);
}