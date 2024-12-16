#pragma once
#include<iostream>
#include<cmath>
#include"coef_binomial.hpp"
#include"power.hpp"
#include"poly_pade.hpp"
#include "binomial_template.hpp"


int M(double x) {
    int m = 0;
    while (abs(x / power(2, m)) > 0.5) {
        ++m;
    }
    return m;
}

template <typename T, int N = 5>
T exp_pade(T xx){
    int m = M(xx);
    T X = xx/power(T(2),m);
    const Binomial<N> binomial;
    return power(((poly_pade(X, binomial))/poly_pade(-X, binomial)),power(T(2),m));
}

