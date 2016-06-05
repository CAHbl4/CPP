#pragma once
class ReservoirList;

enum ReservoirType { Pool, Pond, Lake, Sea, Ocean, ReservoirType_COUNT};

istream& operator>>(istream& is, ReservoirType& rval);

class Reservoir {
	char* name;
	ReservoirType type;
	float width, length, maxDepth;
	friend ReservoirList;
public:
	explicit Reservoir(char* const name = "\0", ReservoirType type = Pool, float width = .0, float length = .0, float maxDepth = .0);

	Reservoir(const Reservoir& other);
	Reservoir& operator=(const Reservoir& other);


	float Volume() const {
		return width * length * maxDepth;
	}


	float Area() const {
		return width * length;
	}


	friend ostream& operator<<(ostream& os, const Reservoir& obj);
	friend istream& operator>>(istream& is, Reservoir& obj);

	const char* GetName() const;
	ReservoirType GetType() const;
	float GetWidth() const;
	float GetLength() const;
	float GetMaxDepth() const;

	void SetName(char* name);
	void SetType(ReservoirType type);
	void SetWidth(float width);
	void SetLength(float length);
	void SetMaxDepth(float maxDepth);


	friend bool operator==(const Reservoir& lval, const Reservoir& rval) {
		return lval.type == rval.type;
	}


	friend bool operator!=(const Reservoir& lval, const Reservoir& rval) {
		return !(lval == rval);
	}


	~Reservoir();
};
