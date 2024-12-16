#pragma once
#include<iostream>
template <int Ndim>
class point {
  protected:
    double coord[Ndim] ;
  public:
    void zero();
    double operator[](int ii)const;
    void set(int ii, const double& a);
    
    point();
    point(double x);
    point(double x[Ndim]);
    point(const point& p);
    const point& operator=(const point& p);
    const point& operator+=(const point& p);
    const point& operator-=(const point& p);
    template<int N>
    friend const point<N> operator-(const point<N>& p);
    template<int N>
    friend const point<N> operator+(const point<N>& p);
    template<int N>
    friend const point<N> operator+(const point<N>& p, const point<N>& q);
    template<int N>
    friend const point<N> operator-(const point<N>& p, const point<N>& q);
    template<int N>
    friend std::ostream& operator<<(std::ostream& os, const point<N>& p);
    
};
template<int Ndim>
point<Ndim>::point(){
    for (int ii = 0; ii<Ndim; ii++){
        coord[ii] = 0.0;
    }
}
//2
template<int Ndim>
point<Ndim>::point(double x){
    for(int ii = 0; ii < Ndim; ii++){
        coord[ii] = x;
    }
}
//3
template<int Ndim>
point<Ndim>::point(double x[Ndim]){
    for(int ii = 0; ii < Ndim; ii++){
        coord[ii] = x[ii];
    }
}
template<int Ndim>
point<Ndim>::point(const point& p){
  for(int ii=0; ii<Ndim; ii++)
    this->coord[ii] = p.coord[ii];
} //  copy constructor
template<int Ndim>
void point<Ndim>::zero(){
    for ( int ii =0; ii <Ndim; ii++){
        this->coord[ii]=0.0;
    }    
}
template<int Ndim>
double point<Ndim>::operator[](int ii)const{
    return this-> coord[ii]; 
}
template<int Ndim>
void point<Ndim>::set(int ii, const double& a) {
    if (ii >= 0 && ii <Ndim){
        coord[ii] = a;
    }
}
template<int Ndim>
const point<Ndim>& point<Ndim>::operator=(const point<Ndim>& p){
    if(this != &p){
        for(int ii=0; ii<Ndim; ii++)
            this->coord[ii] = p.coord[ii];
        }
    return *this;
} 
template<int Ndim>
const point<Ndim> operator-(const point<Ndim>& p){
    point<Ndim> q ;
    for(int ii = 0; ii<Ndim; ii++){
        q.coord[ii] = -p.coord[ii];
    }
    return q;
}
template<int Ndim>
const point<Ndim> operator+(const point<Ndim>& p){
    point<Ndim> k;
    for(int ii = 0; ii<Ndim; ii++){
        k.coord[ii] = p.coord[ii];
    }
    return k;
}
template<int Ndim>
const point<Ndim>& point<Ndim>::operator+=(const point<Ndim>& p){
    for(int ii = 0; ii<Ndim; ii++){
        coord[ii]+=p.coord[ii];
    }
    return *this;
}
template<int Ndim>
const point<Ndim>& point<Ndim>::operator-=(const point<Ndim>& p){
    for(int ii = 0; ii<Ndim; ii++){
        coord[ii]-=p.coord[ii];
    }
    return *this;
}
template<int Ndim>
const point<Ndim> operator+(const point<Ndim>& p, const point<Ndim>& q){
    point<Ndim> s;
    for(int ii = 0; ii<Ndim; ii++){
        s.coord[ii] = p.coord[ii]+q.coord[ii];
    }
    return s;
}
template<int Ndim>
const point<Ndim> operator-(const point<Ndim>& p, const point<Ndim>& q){
    point<Ndim> n;
    for(int ii = 0; ii<Ndim; ii++){
        n.coord[ii] = p.coord[ii]-q.coord[ii];
    }
    return n;
}
template<int Ndim>
std::ostream& operator<<(std::ostream& os, const point<Ndim>& p){
    os << "(";
        for (int ii = 0; ii <Ndim; ii++) {
            os << p.coord[ii];
            if (ii < Ndim - 1) os << ", ";
        }
        os << ")";
    return os;
}