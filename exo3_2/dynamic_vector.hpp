#include<iostream>

class dynamic_vector
{
private:
    size_t Ndim;
    double* cc;
public:
    dynamic_vector(size_t N, double xx=0.);
    dynamic_vector(size_t N, double* xx);
    ~dynamic_vector();
    void zero();
    void set(int ii, const double& a);
    double operator[] (int ii) const;
    double& operator[] (int ii) ;
    dynamic_vector(const dynamic_vector& p);
    const dynamic_vector& operator=(const dynamic_vector& p);
    friend const dynamic_vector operator*(const dynamic_vector& p, const double& lambda);
    friend const dynamic_vector operator*(const double& lambda, const dynamic_vector& p);
    const dynamic_vector& operator=(const double& x);
    friend const dynamic_vector operator-(const dynamic_vector& p);
    friend const dynamic_vector operator+(const dynamic_vector& p);
    const dynamic_vector& operator-=(const dynamic_vector& p);
    const dynamic_vector& operator+=(const dynamic_vector& p);
    friend const dynamic_vector operator+(const dynamic_vector& p, const dynamic_vector& q);
    friend const dynamic_vector operator-(const dynamic_vector& p, const dynamic_vector& q);
    friend std::ostream& operator<<(std::ostream& os, const dynamic_vector& p);
};