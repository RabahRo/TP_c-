#include"coef_binomial.hpp"
double Coef_B(int n,int k){
    return factorial(n)/(factorial(k)*factorial(n-k));
}
double factorial(int n){
	double fact = 1.0;
	for (int i = 1; i<=n; ++i){
		fact= i*fact;
      }
      return fact;
}