#include<iostream>
class point {
  private:
    static const int Ndim = 2;
    double coord[Ndim] ;
  public:
    point();
    point(double x);
    point(double x[Ndim]);
    void zero();
    double operator[](int ii)const;
    point(const point& p);
    void set(int ii, const double& a);
    const point& operator=(const point& p);
    friend const point operator-(const point& p);
    friend const point operator+(const point& p);
    const point& operator+=(const point& p);
    const point& operator-=(const point& p);
    friend const point operator+(const point& p, const point& q);
    friend const point operator-(const point& p, const point& q);
    friend std::ostream& operator<<(std::ostream& os, const point& p);
    
};