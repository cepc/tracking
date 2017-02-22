#include "StraightLine.h"
#include <cmath>


double StraightLine::x_r = 0;
double StraightLine::y_r = 0;
double StraightLine::z_r = 0;

StraightLine::StraightLine()
{
    p = new double[3];
}

StraightLine::StraightLine(double _d0, double _phi, double _omega, double _z0, double _tanLambda)
{
    d0 = _d0;
    phi = _phi;
    omega = _omega;
    z0 = _z0;
    tanLambda = _tanLambda;
    R = 1 / omega;
    p = new double[3];
}

StraightLine::~StraightLine()
{
    delete p;
}

void StraightLine::setReferencePoint(double _x, double _y, double _z)
{
    x_r = _x;
    y_r = _y;
    z_r = _z;
}

void StraightLine::setParameters(double _d0, double _phi, double _omega, double _z0, double _tanLambda)
{
    d0 = _d0;
    phi = _phi;
    omega = _omega;
    z0 = _z0;
    tanLambda = _tanLambda;
    R = 1 / omega;
}

double* StraightLine::getPointAt(double s)
{
    p[0] = x_r + d0 * sin(phi) - R * sin(-s + phi) + R * sin(phi);
    p[1] = y_r - d0 * cos(phi) + R * cos(-s + phi) - R * cos(phi);
    p[2] = z_r + tanLambda * s;
    return p;
}

StraightLine a_straightline;
// StraightLine::setReferencePoint(0.0, 0.0, 0.0);
