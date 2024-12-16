#include <iostream>

class point{

private:

 static const int Ndim=2;
 double coord[Ndim];

public:

point();
point(double xx[Ndim]);
point(double xx);
double operator[](int ii) const;
void zero();
~point(){};  //  destructor
point(const point& p);  //  copy constructor
const point& operator=(const point& p); //  point-to-point assignment
friend const point operator-(const point& p); // unary operator-
friend const point operator+(const point& p); // unary operator+
const point& operator+=(const point& p);  // adding a point to the current point
const point& operator-=(const point& p);  // subtracting a point to the current point
friend const point operator+(const point& p, const point& q);
friend const point operator-(const point& p, const point& q);
friend std::ostream& operator<<(std::ostream& os, const point& p);
};
