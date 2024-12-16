#include "class_dynamicVector.hpp"
#include <iostream>
#include <cassert>

using namespace std;

dynamicVector::dynamicVector(size_t N, double* xx) : Ndim(N) {
  coord = new double[Ndim];
  for(int ii=0; ii<this->Ndim; ii++)
    this->coord[ii] = xx[ii];
}

dynamicVector::dynamicVector(size_t N, double xx) : Ndim(N){
  coord = new double[Ndim];
  for(int ii=0; ii<this->Ndim; ii++)
    this->coord[ii] = xx;
}
//
double dynamicVector::operator[](int ii) const{
  return this->coord[ii];
  }
double& dynamicVector::operator[](int ii){
  return this->coord[ii];
  }
//
void dynamicVector::zero(){
  for(int ii=0; ii<this->Ndim; ii++)
    this->coord[ii] = 0.;
}

const dynamicVector operator*(const dynamicVector& p, const double& lambda){ //  dynamicVector-to-dynamicVector assignment
  double product[p.Ndim];
  for(int ii=0; ii<p.Ndim; ii++)
    product[ii] = lambda*p.coord[ii];
  return dynamicVector(p.Ndim, product);
}

const dynamicVector operator*(const double& lambda, const dynamicVector& p){ //  dynamicVector-to-dynamicVector assignment
  double product[p.Ndim];
  for(int ii=0; ii<p.Ndim; ii++)
    product[ii] = lambda*p.coord[ii];
  return dynamicVector(p.Ndim, product);
}

dynamicVector::dynamicVector(const dynamicVector& p)
  :Ndim(p.Ndim), coord(p.Ndim ? new double[p.Ndim] : 0){

  for(int ii=0; ii<this->Ndim; ii++)
    this->coord[ii] = p.coord[ii];
}  //  copy constructor

const dynamicVector& dynamicVector::operator=(const dynamicVector& p){
  if(this != &p){
    if(this->Ndim > p.Ndim)
        delete [] (this->coord + p.Ndim);
    if(this->Ndim < p.Ndim){
        delete [] this->coord;
        coord = new double[p.Ndim];
    }
    for(int ii=0; ii<this->Ndim; ii++)
     this->coord[ii] = p.coord[ii];
  }
  return *this;
}  //  dynamicVector-to-dynamicVector assignment

const dynamicVector& dynamicVector::operator=(const double& x){
  for(int ii=0; ii<this->Ndim; ii++)
   this->coord[ii] = x;
  return *this;
}

// //
const dynamicVector operator-(const dynamicVector& p){
    return -1.0*p;
}  // unary -
//
const dynamicVector operator+(const dynamicVector& p){
    return p;
}  // unary +
//
//
const dynamicVector& dynamicVector::operator+=(const dynamicVector& p){
  assert(p.Ndim == this->Ndim);
  for(int ii=0; ii<this->Ndim; ii++)
    this->coord[ii] += p[ii];
 return *this;
}  //  adding a dynamicVector to the current dynamicVector
//
const dynamicVector& dynamicVector::operator-=(const dynamicVector& p){
  assert(p.Ndim == this->Ndim);
  for(int ii=0; ii<this->Ndim; ii++)
    this->coord[ii] -= p[ii];
 return *this;
}  //  subtracting a dynamicVector to the current dynamicVector

//
const dynamicVector operator+(const dynamicVector& p, const dynamicVector& q){
  assert(p.Ndim == q.Ndim);
  dynamicVector s(p.Ndim);
  for(int ii=0; ii<p.Ndim; ii++)
    s.coord[ii] = p[ii]+q[ii];
 return s;
}  //  add two dynamicVectors

const dynamicVector operator-(const dynamicVector& p, const dynamicVector& q){
  assert(p.Ndim == q.Ndim);
  dynamicVector s(p.Ndim);
  for(int ii=0; ii<s.Ndim; ii++)
    s.coord[ii] = p[ii]-q[ii];
 return s;
}  //  subtract two dynamicVectors


std::ostream& operator<<(std::ostream& os, const dynamicVector& p)
{
    os << "(x, y) = (";
    for(int ii=0; ii<p.Ndim-1; ii++) os<< p[ii]<<",";
    os<< p[p.Ndim-1]<< ")";
    os << std::endl<< std::endl;

    return os;
}
