#include<iostream>
#include<cmath>
template <int Ndim, typename T>
class vector {
  private:
    T coord[Ndim] ;
  public:
    void zero();
    T operator[](int ii)const;
    void set(int ii, const double& a);
    
    vector();
    vector(T x);
    vector(T x[Ndim]);
    vector(const vector& p);
    const vector& operator=(const vector& p);
    const vector& operator+=(const vector& p);
    const vector& operator-=(const vector& p);
    template<int N, typename S>
    friend const vector<N, S> operator-(const vector<N, S>& p);
    template<int N, typename S>
    friend const vector<N, S> operator+(const vector<N, S>& p);
    template<int N, typename S>
    friend const vector<N, S> operator+(const vector<N, S>& p, const vector<N, S>& q);
    template<int N, typename S>
    friend const vector<N, S> operator-(const vector<N, S>& p, const vector<N, S>& q);
    template<int N, typename S>
    friend const S operator*(const vector<N, S>& u, const vector<N, S>& v);
    template<int N, typename S>
    friend std::ostream& operator<<(std::ostream& os, const vector<N, S>& p);
    T norm2();
    
};

typedef vector<2,double> point2d;
typedef vector<3,int> point3d;



//template<typename T>
//using point2d = vector<2,T>;

//template<typename T>
//using point3d = vector<3,T>;

template<int Ndim, typename T>
vector<Ndim, T>::vector(){
    for (int ii = 0; ii<Ndim; ii++){
        coord[ii] = 0.0;
    }
}
//2
template<int Ndim, typename T>
vector<Ndim, T>::vector(T x){
    for(int ii = 0; ii < Ndim; ii++){
        coord[ii] = x;
    }
}
//3
template<int Ndim, typename T>
vector<Ndim, T>::vector(T x[Ndim]){
    for(int ii = 0; ii < Ndim; ii++){
        coord[ii] = x[ii];
    }
}
template<int Ndim, typename T>
vector<Ndim,T>::vector(const vector& p){
  for(int ii=0; ii<Ndim; ii++)
    this->coord[ii] = p.coord[ii];
} //  copy constructor
template<int Ndim, typename T>
void vector<Ndim, T>::zero(){
    for ( int ii =0; ii <Ndim; ii++){
        this->coord[ii]=0.0;
    }    
}
template<int Ndim, typename T>
T vector<Ndim,T>::operator[](int ii)const{
    return this-> coord[ii]; 
}
template<int Ndim, typename T>
void vector<Ndim,T>::set(int ii, const double& a) {
    if (ii >= 0 && ii <Ndim){
        coord[ii] = a;
    }
}
template<int Ndim, typename T>
const vector<Ndim,T>& vector<Ndim,T>::operator=(const vector<Ndim,T>& p){
    if(this != &p){
        for(int ii=0; ii<Ndim; ii++)
            this->coord[ii] = p.coord[ii];
        }
    return *this;
} 
template<int Ndim, typename T>
const vector<Ndim,T> operator-(const vector<Ndim,T>& p){
    vector<Ndim,T> q ;
    for(int ii = 0; ii<Ndim; ii++){
        q.coord[ii] = -p.coord[ii];
    }
    return q;
}
template<int Ndim, typename T>
const vector<Ndim,T> operator+(const vector<Ndim,T>& p){
    vector<Ndim,T> k;
    for(int ii = 0; ii<Ndim; ii++){
        k.coord[ii] = p.coord[ii];
    }
    return k;
}
template<int Ndim,typename T>
const vector<Ndim,T>& vector<Ndim,T>::operator+=(const vector<Ndim,T>& p){
    for(int ii = 0; ii<Ndim; ii++){
        coord[ii]+=p.coord[ii];
    }
    return *this;
}
template<int Ndim, typename T>
const vector<Ndim,T>& vector<Ndim,T>::operator-=(const vector<Ndim,T>& p){
    for(int ii = 0; ii<Ndim; ii++){
        coord[ii]-=p.coord[ii];
    }
    return *this;
}
template<int Ndim,typename T>
const vector<Ndim,T> operator+(const vector<Ndim,T>& p, const vector<Ndim,T>& q){
    vector<Ndim,T> s;
    for(int ii = 0; ii<Ndim; ii++){
        s.coord[ii] = p.coord[ii]+q.coord[ii];
    }
    return s;
}
template<int Ndim, typename T>
const vector<Ndim,T> operator-(const vector<Ndim,T>& p, const vector<Ndim,T>& q){
    vector<Ndim,T> n;
    for(int ii = 0; ii<Ndim; ii++){
        n.coord[ii] = p.coord[ii]-q.coord[ii];
    }
    return n;
}
template<int Ndim, typename T>
const T operator*(const vector<Ndim,T>& u, const vector<Ndim,T>& v){
    T sum = 0;
    for(int ii = 0; ii<Ndim; ii++){
        sum += u[ii]*v[ii];
    }
    return sum;
}
template<int Ndim, typename T>
std::ostream& operator<<(std::ostream& os, const vector<Ndim,T>& p){
    os << "(";
        for (int ii = 0; ii <Ndim; ii++) {
            os << p.coord[ii];
            if (ii < Ndim - 1) os << ", ";
        }
        os << ")";
    return os;
}
template<int Ndim, typename T>
T vector<Ndim,T>::norm2(){
    T somme = 0;
    for(int ii=0; ii<Ndim; ii++){
        somme += (this->coord[ii])*(this->coord[ii]);
    }
    return sqrt(somme);
}
