#pragma once
#include <istream>
#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned int uint;

class Matrix
{
public:
	Matrix(uint dim);
	Matrix(const Matrix& g);
	Matrix(Matrix&& g);
	Matrix& operator=(const Matrix& g) = delete;
	Matrix& operator=(Matrix&& r);
	void operator*=(double lambda);
	uint getN()const { return n; };
	void inpMatrix();
	void outMatrix()const;
	void inpBarr();
	double maxElemRow(uint i);
	uint columnIndByElem(double elem, uint row, uint startColumn);
	void swapColumns(uint i, uint j);
	void swapOrts(uint i, uint j);
	double diagComp();
	void setDiagOne(); // E
	void setVal(uint i, uint j, double val);
	double getNorm();
	double getElem(uint i, uint j)const;
	
protected:
	uint n;
	vector<vector<double>> matrix;
	vector<double> barr;
	void clearMatrix();
	vector<uint> ortArr;
};

istream& operator >> (istream& in, Matrix& g);
ostream& operator << (ostream& out, const Matrix& g);
Matrix operator-(const Matrix& m1, const Matrix& m2);
