#include<iostream>
#include"fact.hpp"
double Coef_B(int n,int k){
    return factorial(n)/(factorial(k)*factorial(n-k));
}