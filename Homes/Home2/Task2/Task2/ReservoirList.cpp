#include "stdafx.h"
#include "ReservoirList.h"


ReservoirList::ReservoirList(int count): count(count) {
	ptr = new Reservoir[count];
}


ReservoirList::ReservoirList(const ReservoirList& other) : count(other.count) {
	ptr = new Reservoir[count];
	for (int i = 0; i < count; ++i)
		ptr[i] = other.ptr[i];
}


ReservoirList& ReservoirList::operator=(const ReservoirList& other) {
	if (this == &other)
		return *this;
	if (ptr)
		delete[] ptr;
	count = other.count;
	ptr = new Reservoir[count];
	for (int i = 0; i < count; ++i)
		ptr[i] = other.ptr[i];
	return *this;
}


void ReservoirList::Add(const Reservoir& reservoir) {
	Reservoir* tmp = new Reservoir[count + 1];
	for (int i = 0; i < count; ++i) {
		tmp[i] = ptr[i];
	}
	if (ptr)
		delete[] ptr;
	tmp[count] = reservoir;
	ptr = tmp;
	++count;
}


Reservoir& ReservoirList::Get(int index) const {
	if (index < 0 || index >= count) {
		throw std::out_of_range("get");
	}
	return ptr[index];
}


void ReservoirList::Set(int index, const Reservoir& value) const {
	if (index < 0 || index >= count) {
		throw std::out_of_range("set");
	}
	ptr[index] = value;
}


void ReservoirList::Remove(int index) {
	if (index < 0 || index >= count) {
		throw std::out_of_range("remove");
	}
	Reservoir* tmp = new Reservoir[count - 1];
	for (int i = 0, j = 0; i < count; ++i) {
		if (i != index)
			tmp[j++] = ptr[i];
	}
	if (ptr)
		delete[] ptr;
	ptr = tmp;
	--count;
}


void ReservoirList::Clear() {
	if (ptr)
		delete[] ptr;
	count = 0;
	ptr = nullptr;
}


int ReservoirList::GetCount() const {
	return count;
}


void ReservoirList::Show() const {
	for (int i = 0; i < count; ++i)
		cout
			<< ptr[i]
			<< "Volume: " << ptr[i].Volume() << endl
			<< "Area: " << ptr[i].Area() << endl
			<< "---------------------------\n";	
}


Reservoir& ReservoirList::operator[](int index) const {
	if (index < 0 || index >= count) {
		throw std::out_of_range("[]");
	}
	return ptr[index];
}


int ReservoirList::Export(const char* fileName) const {
	ofstream fout(fileName, ios::out | ios::trunc);
	int i = -1;
	if (fout.is_open()) {
		for (i = 0; i < count; ++i)
			fout << ptr[i];
		fout.close();
	}
	return i;
}


int ReservoirList::Save(const char* fileName) const {
	ofstream fout(fileName, ios::out | ios::binary | ios::trunc);
	int i = -1;
	if (fout.is_open()) {
		int len;
		for (i = 0; i < count; ++i) {
			//количество байт в имени
			len = strlen(ptr[i].name);

			//Пишем количество байт в имени
			fout.write(reinterpret_cast<const char*>(&len), sizeof(int));

			//Пишем имя
			fout.write(ptr[i].name, len);

			//Пишем все остальное
			fout.write(reinterpret_cast<const char*>(&ptr[i].type), sizeof(ReservoirType));
			fout.write(reinterpret_cast<const char*>(&ptr[i].width), sizeof(float));
			fout.write(reinterpret_cast<const char*>(&ptr[i].length), sizeof(float));
			fout.write(reinterpret_cast<const char*>(&ptr[i].maxDepth), sizeof(float));
		}
		fout.close();
	}
	return i;
}


int ReservoirList::Load(const char* fileName) {
	ifstream fin(fileName, ios::in | ios::binary | ios::ate);
	streampos size;
	int len;
	int i = -1;
	if (fin.is_open()) {
		size = fin.tellg();
		fin.seekg(0, ios::beg);
		Clear();
		i = 0;
		while (fin.tellg() < size) {
			Reservoir tmp;
			char* str;
			//Читаем длинну имени
			fin.read(reinterpret_cast<char*>(&len), sizeof(int));
			//Выделяем память под имя
			str = new char[len + 1];
			//Читаем имя и добавляем нуль символ
			fin.read(str, len);
			str[len] = '\0';
			tmp.SetName(str);

			//Читаем все остальное
			fin.read(reinterpret_cast<char*>(&tmp.type), sizeof(ReservoirType));
			fin.read(reinterpret_cast<char*>(&tmp.width), sizeof(int));
			fin.read(reinterpret_cast<char*>(&tmp.length), sizeof(int));
			fin.read(reinterpret_cast<char*>(&tmp.maxDepth), sizeof(int));

			Add(tmp);
			++i;
			delete[] str;
		}
	}
	return i;
}


ReservoirList::~ReservoirList() {
	if (ptr)
		delete[] ptr;
}
