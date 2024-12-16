#include<iostream>
#include<cmath>
#include"coef_b.hpp"
#include"fact.hpp"
#include"power.hpp"
double poly_pade(double x, int N){
    double sum = 1;
    for (int i =1; i<=N; ++i){
        sum += (Coef_B(N,i)/(factorial(i)*Coef_B(2*N,i)))*power(x,i);
    }
    return sum;      
}
