#pragma once
#include "matrix.h"
class Vector
{
public:
	Vector(uint dim);
	Vector(const Vector&);
	Vector(Vector&&);
	Vector& operator=(const Vector& g);
	Vector& operator=(Vector&&);
	~Vector();
	uint getN()const { return n; };
	void inpVector();
	void outVector()const;
	double norm();
	double operator*(const Vector& vect);
	const double& operator[](uint i) const;
	double& operator[](uint i);
	void setVal(uint i, double val);
	double getVal(uint i)const;
	//Vector& getNormed(double norm)const;
	void normalize();

private:
	uint n;
	vector<double> v;
	void clearVect();
	
};
istream& operator >> (istream& in, Vector& g);
ostream& operator << (ostream& out, const Vector& g);
Vector operator*(const Vector& v, const Matrix& m);

