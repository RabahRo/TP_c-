#include"power.hpp"
double power(double x,int a){//size_t a
    double r = 1.;
    for (int i = 1; i<=a;++i){
      r = r*x;
    }
    return r;
}