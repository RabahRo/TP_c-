#include<iostream>
#include<cmath>
#include"coef_b.hpp"
#include"fact.hpp"
#include"power.hpp"
#include"poly_pade.hpp"
// Fonction pour calculer m
int M(double x){
    int k = 0;
    while (abs(x / power(2, k)) > 0.5) {
        ++k;
    }
    return k;
}
// Fonction pour approximer exp(x) avec la méthode de Padé
double exp_pade(double xx, int N){
    int m = M(xx);
    double X = xx/power(2,m);
    return power(((poly_pade(X,N))/poly_pade(-X,N)),power(2,m));
}

