#include "vector.h"

Vector::Vector(uint dim): n(dim)
{
	v.resize(n);
}

Vector::Vector(const Vector& c)
{
	n = c.n;
	for (uint i = 0; i < n; i++)
		v.push_back(c.v[i]);
}

Vector::Vector(Vector&& r)
{
	n = r.n;
	for (uint i = 0; i < n; i++)
		v.push_back(r.v[i]);
	r.n = 0;
	r.clearVect();
}

Vector& Vector::operator=(const Vector& g)
{
	if (this != &g) {
		clearVect();
		n = g.n;
		for (uint i = 0; i < n; i++)
			v.push_back(g.v[i]);
	}
	return *this;
}


Vector& Vector::operator=(Vector&& r)
{
	if (this != &r) {
		clearVect();
		n = r.n;
		for (uint i = 0; i < n; i++)
			v.push_back(r.v[i]);
		r.n = 0;
		r.clearVect();
	}
	return *this;
}

Vector::~Vector()
{
	clearVect();
}

void Vector::inpVector()
{
	double val;
	for (uint i = 0; i < n; i++) {
		if (!(cin >> val)) exit(852);
		v[i] = val;
	}
}

void Vector::outVector() const
{
	cout << "( ";
	for (uint i = 0; i < n; i++)
		cout << v[i] << " " << ";" << " ";
	cout << ")\n";
}

double Vector::norm()
{
	double res = 0;
	for (uint i = 0; i < n; i++) {
		res += v[i] * v[i];
	}
	return sqrt(res);
}

double Vector::operator*(const Vector& vect)
{
	double res = 0;
	for (uint i = 0; i < n; i++) {
		res += v[i] * vect.v[i];
	}
	return res;
}

const double& Vector::operator[](uint i) const
{
	if (!(i >= n))return v[i];
	else
	{
		exit(787);
	}
}

Vector operator*(const Vector& v, const Matrix& m)
{
	uint n = v.getN();
	if (m.getN() != n) exit(741);
	Vector vres{ n };
	double res = 0;
	for (uint i = 0; i < n; i++) {
		for (uint j = 0; j < n; j++) {
			res += m.getElem(i, j) * v[j];
		}
		vres.setVal(i, res);
		res = 0;
	}
	return vres;
}

void Vector::clearVect()
{
	v.clear();
}

double& Vector::operator[](uint i)
{
	if (!(i >= n))return v[i];
	else
	{
		exit(787);
	}
}

void Vector::setVal(uint i, double val)
{
	if (i >= n) exit(789);
	v[i] = val;
}

double Vector::getVal(uint i) const
{
	if (i >= n) exit(87);
	return v[i];
}

void Vector::normalize()
{
	double nor = norm();
	for (uint i = 0; i < n; i++) {
		v[i] = v[i] / nor;
	}
}

/*Vector& Vector::getNormed(double norm) const
{
	Vector vect{ n };
	for (uint i = 0; i < n; i++) 
		vect.setVal(i, v[i] / norm);
	return vect;
}*/

istream& operator>>(istream& in, Vector& g)
{
	cout << "[Initial vector] Enter " << g.getN() << " doubles in one line\n";
	g.inpVector();
	return in;
}

ostream& operator<<(ostream& out, const Vector& g)
{
	g.outVector();
	return out;
}
