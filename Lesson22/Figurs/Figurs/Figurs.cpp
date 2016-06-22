// Figurs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vld.h>

using namespace std;

//класс, содержащий хотя бы одну чисто виртуальную функцию
//называется абстрактным. Создавть объекты такогог класса нельзя
class CFigure
{
protected:
	int X;
	int Y;
public:
	CFigure(int AX = 0, int AY = 0) : X(AX), Y(AY) {}

	int GetX() const { return X; }
	int GetY() const { return Y; }
	void MoveTo(int AX, int AY) { X = AX; Y = AY; }

	//чисто виртуальная функция 
	virtual void Draw() = 0;
};

//класс точка
class CPoint : public CFigure
{
public:
	CPoint(int AX = 0, int AY = 0) : CFigure(AX, AY) {}
	virtual void Draw(){
		cout << "Draw Point" << endl;
	}
};

//класс линии, потомок точки и абстрактного класса CFigure
class CLine : public CPoint
{
protected:
	//допорлнительные поля (конечная точка)
	int EndX;
	int EndY;
public:
	CLine(int AX = 0, int AY = 0, int AEndX = 0, int AEndY = 0)
		: CPoint(AX, AY), EndX(AEndX), EndY(EndY) {}

	int GetEndX() const { return EndX; }
	int GetEndY() const { return EndY; }
	void MoveEndTo(int AEndX, int AEndY) { EndX = AEndX; EndY = AEndY; }

	virtual void Draw(){
		cout << "Draw Line" << endl;
	}


};

//класс окружность - наслденик CPoint, CFigure
class CCircle : public CPoint
{
protected:
	//дополнительное поле - радиус
	int Radius;
public:
	CCircle(int AX = 0, int AY = 0, int ARadius = 10)
		: CPoint(AX, AY), Radius(ARadius) {}

	int GetRadius() const { return Radius; }
	void SetRadius(int ARadius) { Radius = ARadius; }

	//    virtual void Draw();
	virtual void Draw(){
		cout << "Draw Circle" << endl;
	}
};

//класс треугольник - наслденик CPoint, CFigure
class CTriangle : public CPoint
{
protected:
	//дополнительные поля - координаты двух вершин
	int X2;
	int Y2;
	int X3;
	int Y3;
public:
	CTriangle(int AX = 0, int AY = 0, int AX2 = 0,
		int AY2 = 0, int AX3 = 0, int AY3 = 0)
		: CPoint(AX, AY), X2(AX2), Y2(AY2), X3(AX3), Y3(AY3) {}

	int GetX2() const { return X2; }
	int GetY2() const { return Y2; }
	int GetX3() const { return X3; }
	int GetY4() const { return Y3; }
	void MoveSecondTo(int AX2, int AY2) { X2 = AX2; Y2 = AY2; }
	void MoveThirdTo(int AX3, int AY3) { X3 = AX3; Y3 = AY3; }

	//    virtual void Draw();

	virtual void Draw(){
		cout << "Draw Triangle" << endl;
	}
};

//класс квадрат - наслденик CPoint, CFigure
class CSquare : public CPoint
{
protected:
	//дополнительный параметр - ширина
	int Width;
public:
	CSquare(int AX = 0, int AY = 0, int AWidth = 100)
		: CPoint(AX, AY), Width(AWidth) {}

	int GetWidth() const { return Width; }
	void SetWidth(int AWidth) { Width = AWidth; }

	//    virtual void Draw();

	virtual void Draw(){
		cout << "Draw Square" << endl;
	}
};

//класс прямоугольник - наслденик CPoint, CFigure, CSquare
class CRect : public CSquare
{
protected:
	//дополнительное поле - высота
	int Height;
public:
	CRect(int AX = 0, int AY = 0, int AWidth = 100, int AHeight = 100)
		: CSquare(AX, AY, AWidth), Height(AHeight) {}

	int GetHeight() const { return Height; }
	void SetHeight(int AHeight) { Height = AHeight; }

	//   virtual void Draw();

	virtual void Draw(){
		cout << "Draw Rect" << endl;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	// Массив для хранения объектов
	// как массив указателей на базовый класс
	const int arraySize = 3;
	CPoint *fig[arraySize];

	// Заполняем массив
	fig[0] = new CPoint(1, 1);
	fig[1] = new CLine(5, 5, 30, 20);
	fig[2] = new CRect(10, 10, 50, 35);

	// Полиморфизм в действии
	for (int i = 0; i < arraySize; i++)
		fig[i]->Draw();

	cout << "Good-bye!" << endl;

	// Вызов деструкторов базового класса.
	// Т.к. в производных классах деструкторов нет, то делать
	// деструкторы виртуальными нет необходимости.
	/*for (int i = 0; i < arraySize; i++)
		delete fig[i];*/

	system("pause");
	return 0;
}

