#include<iostream>
double power(double x,int a){//size_t a
    double r = 1.0;
    for (int i = 0; i<a;++i){
      r = r*x;
    }
    return r;
}
