#pragma once
double factorial(int n){
	double fact = 1.0;
	for (int i = 1; i<=n; ++i){
		fact= i*fact;
      }
      return fact;
}