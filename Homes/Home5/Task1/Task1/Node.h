#pragma once

//описание структуры узла (элемент списка)
template <class T>
struct Node {
	//данные
	T data;
	//указатель на следующий узел (элемент)
	Node<T>* next;
};