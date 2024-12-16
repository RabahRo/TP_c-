#include<iostream>
#include<cmath>
#include"lagrange_template.hpp"

using namespace std;

int main(){
    double xx[] = {1., 2., 3., 4., 5.};
    double yy[] = {exp(1.0), exp(2.0), exp(3.0), exp(4.0), exp(5.0)};
    int n = sizeof(xx)/sizeof(xx[0]);
    double x0 = 2.5;
    cout<< "l'approximation polynomial de l'interpolaleur de lagrange PN(x0) est : "<<lagrange(xx,yy,x0,n);
    return 0;
}