#pragma once
#include<iostream>
#include<cmath>
#include"binomial_template.hpp"
#include"power.hpp"
#include"fact.hpp"
template <typename T, int N>
T poly_pade(T x, const Binomial<N>& binomial){
    T sum = 1;
    for (int i =1; i<=N; ++i){
        sum += (binomial(N,i)/(factorial(i)*binomial(2*N,i)))*power(x,i);
    }
    return sum;      
}
