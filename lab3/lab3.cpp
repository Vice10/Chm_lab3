#include <iostream>
#include <exception>
#include "matrix.h"
#include "vector.h"
using namespace std;
const double eps = 1e-1;
double getMaxEigen(Matrix, Vector);
int main()
{
    uint n;
    cout << "Enter matrix and vector dimension\n";
    if (!(cin >> n))exit(3);
    Matrix matr{ n };
    Vector vect{ n };
    cin >> matr;
    cin >> vect;
    double maxEigenA = 0;
    try {
        maxEigenA = getMaxEigen(matr, vect);
        cout << "|Max eigen value| = " << fabs(maxEigenA) << "\n";
    }
    catch (exception ex) {
        cout << ex.what();
    }
    Matrix em{ n };
    em.setDiagOne();
    em *= maxEigenA;
    Matrix b{ n };
    b = em - matr;
    double maxEigenB = getMaxEigen(b, vect);

    cout << "|Min eigen value| = " << fabs(maxEigenA - maxEigenB) << "\n";
}

double getMaxEigen(Matrix matr, Vector vect) {
    double m1 = 1, m2 = 0;
    while (fabs(m1 - m2) >= eps)
    {
        Vector ev{ vect };
        ev.normalize();
        vect = ev * matr;
        m1 = m2;
        m2 = vect * ev;
    }
    return m2;
}