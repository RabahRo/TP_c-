#include<iostream>
#include<cmath>
#include<cassert>
template<int Ndim, typename T>
class dynamic_vector
{
private:
    int siz;
    T* cc;
public:
    dynamic_vector(int N, T xx=0.);
    dynamic_vector(int N, T* xx);
    ~dynamic_vector();
    void zero();
    void set(int ii, const T& a);
    T operator[] (int ii) const;
    T& operator[] (int ii) ;
    dynamic_vector(const dynamic_vector& p);
    const dynamic_vector& operator=(const dynamic_vector& p);
    template<int N, typename S>
    friend const dynamic_vector<N,S> operator*(const dynamic_vector<N,S>& p, const double& lambda);
    template<int N, typename S>
    friend const dynamic_vector<N,S> operator*(const double& lambda, const dynamic_vector<N,S>& p);
    const dynamic_vector& operator=(const T& x);
    template<int N, typename S>
    friend const dynamic_vector<N,S> operator-(const dynamic_vector<N,S>& p);
    template<int N, typename S>
    friend const dynamic_vector<N,S> operator+(const dynamic_vector<N,S>& p);
    const dynamic_vector& operator-=(const dynamic_vector& p);
    const dynamic_vector& operator+=(const dynamic_vector& p);
    template<int N, typename S>
    friend const dynamic_vector<N,S> operator+(const dynamic_vector<N,S>& p, const dynamic_vector<N,S>& q);
    template<int N, typename S>
    friend const dynamic_vector<N,S> operator-(const dynamic_vector<N,S>& p, const dynamic_vector<N,S>& q);
    template<int N, typename S>
    friend const S operator*(const dynamic_vector<N,S>& u, const dynamic_vector<N,S>& v);
    template<int N, typename S>
    friend std::ostream& operator<<(std::ostream& os, const dynamic_vector<N,S>& p);
    T norm2();
};
template<int Ndim, typename T>
dynamic_vector<Ndim,T>::dynamic_vector(int N, T xx):siz(N){
    cc = new T[siz];
    for(int ii = 0; ii<this->siz; ii++){
        this->cc[ii] = xx; 
    }
}
template<int Ndim, typename T>
dynamic_vector<Ndim,T>::dynamic_vector(int N, T* xx):siz(N){
    cc = new T[siz];
    for(int ii = 0; ii<this->siz; ii++){
        this->cc[ii]=xx[ii];
    }
}
template<int Ndim, typename T>
dynamic_vector<Ndim,T>::~dynamic_vector(){
    delete [] cc;
}
template<int Ndim, typename T>
void dynamic_vector<Ndim,T>::zero(){
    for(int ii=0; ii<this->siz; ii++){
        this->cc[ii] = 0.;
    }
}
template<int Ndim, typename T>
void dynamic_vector<Ndim,T>::set(int ii, const T& a){
    for(int ii=0; ii<this->siz; ii++){
        this->cc[ii] = a;
    }
}
template<int Ndim, typename T>
T dynamic_vector<Ndim,T>::operator[] (int ii) const{
    return this->cc[ii];
}
template<int Ndim, typename T>
T& dynamic_vector<Ndim,T>::operator[] (int ii){
    return this->cc[ii];
}
template<int Ndim, typename T>
dynamic_vector<Ndim,T>::dynamic_vector(const dynamic_vector& p): siz(p.siz), cc(p.siz ? new T[p.siz]:0){
    for(int ii=0; ii<siz; ii++){
        this->cc[ii]=p.cc[ii];
    } 
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T>& dynamic_vector<Ndim,T>::operator=(const dynamic_vector& p){
    if(this != &p){
        delete[] this->cc;
        cc = new T[p.siz]; 
        for(int ii = 0; ii<p.siz; ii++){
            this->cc[ii]= p.cc[ii];
        }
    }
    return *this;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T> operator*(const dynamic_vector<Ndim,T>& p, const double& lambda){
    dynamic_vector<Ndim,T> prod(p.siz);
    for(int ii=0; ii<p.siz; ii++){
        prod[ii] = lambda*p.cc[ii];
    }
    return prod;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T> operator*(const double& lambda, const dynamic_vector<Ndim,T>& p){
    dynamic_vector<Ndim, T> prod(p.siz) ;
    for(int ii=0; ii<p.siz; ii++){
        prod[ii] = lambda*p.cc[ii];
    }
    return prod;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T>& dynamic_vector<Ndim,T>::operator=(const T& x){
    for(int ii=0; ii<siz; ii++){
        this->cc[ii] = x;
    }
    return *this;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T> operator-(const dynamic_vector<Ndim,T>& p){
    dynamic_vector<Ndim,T> m(p.siz);
    for(int ii=0; ii<p.siz;ii++){
        m[ii] = -p[ii];
    }
    return m;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T> operator+(const dynamic_vector<Ndim,T>& p){
    dynamic_vector<Ndim,T> k(p.siz);
    for(int ii=0; ii<p.siz;ii++){
        k[ii] = -p[ii];
    }
    return k;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T>& dynamic_vector<Ndim,T>::operator-=(const dynamic_vector& p){
    assert(p.siz == this->siz);
    for(int ii = 0; ii<p.siz; ii++){
        this->cc[ii] -= cc[ii];
    }
    return *this;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T>& dynamic_vector<Ndim,T>::operator+=(const dynamic_vector& p){
    assert(p.siz == this->siz);
    for(int ii = 0; ii<p.siz; ii++){
        this->cc[ii] += cc[ii];
    }
    return *this;
}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T> operator+(const dynamic_vector<Ndim,T>& p, const dynamic_vector<Ndim,T>& q){
    assert(p.siz == q.siz);
    dynamic_vector<Ndim,T> s(p.siz);
    for(int ii = 0; ii<p.siz; ii++){
        s[ii] = p[ii] + q[ii];
    }
    return s;

}
template<int Ndim, typename T>
const dynamic_vector<Ndim,T> operator-(const dynamic_vector<Ndim,T>& p, const dynamic_vector<Ndim,T>& q){
    assert(p.siz == q.siz);
    dynamic_vector<Ndim,T> s(p.siz);
    for(int ii = 0; ii<p.siz; ii++){
        s[ii] = p[ii] - q[ii];
    }
    return s;

}
template<int Ndim, typename T>
const T operator*(const dynamic_vector<Ndim,T>& u, const dynamic_vector<Ndim,T>& v){
    assert(u.siz == v.siz);
    T sum = 0;
    for(int ii = 0; ii<u.siz; ii++){
        sum += u[ii] * v[ii];
    }
    return sum;

}
template<int Ndim, typename T>
T dynamic_vector<Ndim,T>::norm2(){
    T somme = 0;
    for(int ii =0; ii<siz; ii++){
        somme += (this->cc[ii])*(this->cc[ii]);
    }
    return sqrt(somme);
}
template<int Ndim, typename T>
std::ostream& operator<<(std::ostream& os, const dynamic_vector<Ndim,T>& p){
    os << "(x, y) =(";
        for (int ii = 0; ii <p.siz; ii++) {
            os << p.cc[ii];
            if (ii < p.siz - 1) os << ", ";
        }
        os << ")";
    return os;
}