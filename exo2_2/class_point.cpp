#include "class_point.hpp"
#include <iostream>

using namespace std;

point::point(){
  for(int ii=0; ii<point::Ndim; ii++)
    this->coord[ii] = 0.;
};

point::point(double xx[point::Ndim]){
  for(int ii=0; ii<point::Ndim; ii++)
    this->coord[ii] = xx[ii];
};

point::point(double xx){
  for(int ii=0; ii<point::Ndim; ii++)
    this->coord[ii] = xx;
};

double point::operator[](int ii) const{return this->coord[ii];};

void point::zero(){
  for(int ii=0; ii<point::Ndim; ii++)
    this->coord[ii] = 0.;
};

point::point(const point& p){
  for(int ii=0; ii<point::Ndim; ii++)
    this->coord[ii] = p.coord[ii];
};  //  copy constructor

const point& point::operator=(const point& p){
  if(this != &p){
    for(int ii=0; ii<point::Ndim; ii++)
     this->coord[ii] = p.coord[ii];
  }
  return *this;
}  //  point-to-point assignment

//
const point operator-(const point& p){
    double minus[point::Ndim];
    for(int ii=0; ii<point::Ndim; ii++)
      minus[ii] = -p.coord[ii];
    return point(minus);
}  // unary -

const point operator+(const point& p){
    double plus[point::Ndim];
    for(int ii=0; ii<point::Ndim; ii++)
      plus[ii] = p.coord[ii];
    return point(plus);
}  // unary +


const point& point::operator+=(const point& p){
  for(int ii=0; ii<point::Ndim; ii++)
    this->coord[ii] += p[ii];
 return *this;
}  //  adding a point to the current point
//
const point& point::operator-=(const point& p){
  for(int ii=0; ii<point::Ndim; ii++)
    this->coord[ii] -= p[ii];
 return *this;
}  //  subtracting a point to the current point

//
const point operator+(const point& p, const point& q){
  point s;
  for(int ii=0; ii<point::Ndim; ii++)
    s.coord[ii] = p[ii]+q[ii];
 return s;
}  //  add two points

const point operator-(const point& p, const point& q){
  point s;
  for(int ii=0; ii<point::Ndim; ii++)
    s.coord[ii] = p[ii]-q[ii];
 return s;
}  //  subtract two points


std::ostream& operator<<(std::ostream& os, const point& p)
{
    os << "(x, y) = (";
    for(int ii=0; ii<point::Ndim-1; ii++) os<< p[ii]<<",";
    os<< p[point::Ndim-1]<< ")";
    os << std::endl<< std::endl;

    return os;
}
