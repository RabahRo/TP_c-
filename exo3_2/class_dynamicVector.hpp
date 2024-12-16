#include <iostream>

class dynamicVector{

private:

 size_t Ndim;
 double* coord;

public:

dynamicVector(size_t N, double xx=0.);
dynamicVector(size_t N, double* xx);
double operator[](int ii) const;
double& operator[](int ii);
void zero();
~dynamicVector(){delete [] coord;};  //  destructor
dynamicVector(const dynamicVector& p);  //  copy constructor
const dynamicVector& operator=(const dynamicVector& p); //  dynamicVector-to-dynamicVector assignment
friend const dynamicVector operator*(const dynamicVector& p, const double& lambda); //  dynamicVector times double 
friend const dynamicVector operator*(const double& lambda, const dynamicVector& p); //  double times dynamicVector
const dynamicVector& operator=(const double& x); //  double-to-dynamicVector assignment
friend const dynamicVector operator-(const dynamicVector& p); // unary operator-
friend const dynamicVector operator+(const dynamicVector& p); // unary operator+
const dynamicVector& operator+=(const dynamicVector& p);  // adding a dynamicVector to the current dynamicVector
const dynamicVector& operator-=(const dynamicVector& p);  // subtracting a dynamicVector to the current dynamicVector
friend const dynamicVector operator+(const dynamicVector& p, const dynamicVector& q);
friend const dynamicVector operator-(const dynamicVector& p, const dynamicVector& q);
friend std::ostream& operator<<(std::ostream& os, const dynamicVector& p);
};
