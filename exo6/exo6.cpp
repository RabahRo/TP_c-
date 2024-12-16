#include"exo6.hpp"
#include<iostream>
#include<cmath>
void CalculateRealAndImaginary(double r , double theta , double &pReal, double &pImaginary ){
    pReal = r*cos(theta);
    pImaginary = r*sin(theta);
}
/* deuxieme methode :
void CalculateRealAndImaginary(double r , double theta , double *pReal, double *pImaginary ){
    *pReal = r*cos(theta);
    *pImaginary = r*sin(theta);
}
*/