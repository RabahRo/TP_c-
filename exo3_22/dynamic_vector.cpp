#include<iostream>
#include"dynamic_vector.hpp"
#include <cassert>



dynamic_vector::dynamic_vector(size_t N, double xx):Ndim(N){
    cc = new double[Ndim];
    for(int ii = 0; ii<this->Ndim; ii++){
        this->cc[ii] = xx; 
    }
}
dynamic_vector::dynamic_vector(size_t N, double* xx):Ndim(N){
    cc = new double[Ndim];
    for(int ii = 0; ii<this->Ndim; ii++){
        this->cc[ii]=xx[ii];
    }
}

dynamic_vector::~dynamic_vector(){
    delete [] cc;
}
void dynamic_vector::zero(){
    for(int ii=0; ii<this->Ndim; ii++){
        this->cc[ii] = 0.;
    }
}

void dynamic_vector::set(int ii, const double& a){
    for(int ii=0; ii<this->Ndim; ii++){
        this->cc[ii] = a;
    }
}
double dynamic_vector::operator[] (int ii) const{
    return this->cc[ii];
}
double& dynamic_vector::operator[] (int ii){
    return this->cc[ii];
}
dynamic_vector::dynamic_vector(const dynamic_vector& p): Ndim(p.Ndim), cc(p.Ndim ? new double[p.Ndim]:0){
    for(int ii=0; ii<this->Ndim; ii++){
        this->cc[ii]=p.cc[ii];
    } 
}
const dynamic_vector& dynamic_vector::operator=(const dynamic_vector& p){
    if(this != &p){
        if(this->Ndim > p.Ndim){
            delete[](this->cc+p.Ndim);
        }
        else if (this->Ndim < p.Ndim){
            delete[] this->cc;
            cc = new double[p.Ndim];
        }  
    }
    for(int ii = 0; ii<this->Ndim; ii++){
        this->cc[ii]= p.cc[ii];
    }
    return *this;
}
const dynamic_vector operator*(const dynamic_vector& p, const double& lambda){
    dynamic_vector prod(p.Ndim);
    for(int ii=0; ii<p.Ndim; ii++){
        prod[ii] = lambda*p.cc[ii];
    }
    return prod;
}
const dynamic_vector operator*(const double& lambda, const dynamic_vector& p){
    dynamic_vector prod(p.Ndim);
    for(int ii=0; ii<p.Ndim; ii++){
        prod[ii] = lambda*p.cc[ii];
    }
    return prod;
}
const dynamic_vector& dynamic_vector::operator=(const double& x){
    for(int ii=0; ii<this->Ndim; ii++){
        this->cc[ii] = x;
    }
    return *this;
}
const dynamic_vector operator-(const dynamic_vector& p){
    dynamic_vector m(p.Ndim);
    for(int ii=0; ii<p.Ndim;ii++){
        m[ii] = -p[ii];
    }
    return m;
}
const dynamic_vector operator+(const dynamic_vector& p){
    dynamic_vector k(p.Ndim);
    for(int ii=0; ii<p.Ndim;ii++){
        k[ii] = -p[ii];
    }
    return k;
}
const dynamic_vector& dynamic_vector::operator-=(const dynamic_vector& p){
    assert(p.Ndim == this->Ndim);
    for(int ii = 0; ii<Ndim; ii++){
        this->cc[ii] -= p.cc[ii];
    }
    return *this;
}
const dynamic_vector& dynamic_vector::operator+=(const dynamic_vector& p){
    assert(p.Ndim == this->Ndim);
    for(int ii = 0; ii<Ndim; ii++){
        this->cc[ii] += p.cc[ii];
    }
    return *this;
}
const dynamic_vector operator-(const dynamic_vector& p, const dynamic_vector& q){
    assert(p.Ndim == q.Ndim);
    dynamic_vector m(p.Ndim);
    for(int ii = 0; ii<p.Ndim; ii++){
        m[ii] = p[ii] - q[ii];
    }
    return m;

}
const dynamic_vector operator+(const dynamic_vector& p, const dynamic_vector& q){
    assert(p.Ndim == q.Ndim);
    dynamic_vector s(p.Ndim);
    for(int ii = 0; ii<p.Ndim; ii++){
        s[ii] = p[ii] + q[ii];
    }
    return s;

}
std::ostream& operator<<(std::ostream& os, const dynamic_vector& p){
    os << "(x, y) =(";
        for (int ii = 0; ii <p.Ndim; ii++) {
            os << p.cc[ii];
            if (ii < p.Ndim - 1) os << ", ";
        }
        os << ")";
    return os;
}