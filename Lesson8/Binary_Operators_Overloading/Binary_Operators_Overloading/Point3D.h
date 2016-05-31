#pragma once
class Point3D
{
	int x, y, z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z){}
	void Show() const
	{
		cout << "Point3D(" << x << "," << y << "," << z << ")" << endl;
	}

	Point3D operator+(const Point3D& other) const
	{
		Point3D tmp = *this;
		tmp.x += other.x;
		tmp.y += other.y;
		tmp.z += other.z;
		return tmp;
	}
	
	Point3D operator+(const int value) const
	{
		Point3D tmp = *this;
		tmp.x += value;
		tmp.y += value;
		tmp.z += value;
		return tmp;
	}

	Point3D operator*(const int value) const {
		Point3D tmp = *this;
		tmp.x *= value;
		tmp.y *= value;
		tmp.z *= value;
		return tmp;
	}

	Point3D operator*(const Point3D& other) const {
		Point3D tmp = *this;
		tmp.x *= other.x;
		tmp.y *= other.y;
		tmp.z *= other.z;
		return tmp;
	}

	~Point3D();
};
