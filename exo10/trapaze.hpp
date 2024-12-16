#pragma once
typedef double(*ptf)(double);
double trapese(double a, double b, ptf f,int n);