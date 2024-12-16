#include<iostream>
#include"power.hpp"
#include"fact.hpp"

double expTaylor(double x, int N){
	double sum = 0.;
	
	for(int i = 0; i<N; ++i){
		sum +=  (power(x,i)/factorial(i));	
	}
    return sum;
}
