#include<iostream>
#include"point.hpp"
//1
point::point(){
    for (int ii = 0; ii<Ndim; ii++){
        coord[ii] = 0.0;
    }
}
//2
point::point(double x){
    for(int ii = 0; ii < Ndim; ii++){
        coord[ii] = x;
    }
}
//3
point::point(double x[Ndim]){
    for(int ii = 0; ii < Ndim; ii++){
        coord[ii] = x[ii];
    }
}
point::point(const point& p){
  for(int ii=0; ii<Ndim; ii++)
    this->coord[ii] = p.coord[ii];
} //  copy constructor
void point::zero(){
    for ( int ii =0; ii <Ndim; ii++){
        this->coord[ii]=0.0;
    }    
}
double point::operator[](int ii)const{
    return this-> coord[ii]; 
}
void point::set(int ii, const double& a) {
    if (ii >= 0 && ii <Ndim){
        coord[ii] = a;
    }
}
const point& point::operator=(const point& p){
    if(this != &p){
        for(int ii=0; ii<Ndim; ii++)
            this->coord[ii] = p.coord[ii];
        }
    return *this;
} 

const point operator-(const point& p){
    point q ;
    for(int ii = 0; ii<point::Ndim; ii++){
        q.coord[ii] = -p.coord[ii];
    }
    return q;
}

const point operator+(const point& p){
    point k;
    for(int ii = 0; ii<point::Ndim; ii++){
        k.coord[ii] = p.coord[ii];
    }
    return k;
}

const point& point::operator+=(const point& p){
    for(int ii = 0; ii<Ndim; ii++){
        coord[ii]+=p.coord[ii];
    }
    return *this;
}

const point& point::operator-=(const point& p){
    for(int ii = 0; ii<Ndim; ii++){
        coord[ii]-=p.coord[ii];
    }
    return *this;
}
const point operator+(const point& p, const point& q){
    point s;
    for(int ii = 0; ii<point::Ndim; ii++){
        s.coord[ii] = p.coord[ii]+q.coord[ii];
    }
    return s;
}
const point operator-(const point& p, const point& q){
    point n;
    for(int ii = 0; ii<point::Ndim; ii++){
        n.coord[ii] = p.coord[ii]-q.coord[ii];
    }
    return n;
}
std::ostream& operator<<(std::ostream& os, const point& p){
    os << "(";
        for (int ii = 0; ii <point::Ndim; ii++) {
            os << p.coord[ii];
            if (ii < point::Ndim - 1) os << ", ";
        }
        os << ")";
    return os;
}