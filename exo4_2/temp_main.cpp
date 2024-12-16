#include<iostream>
#include<cmath>
#include"template_integral.hpp"
#include"fontion.hpp"

using namespace std;

int main(){
    double x = 0.;
    double y = M_PI;
    int n = 1000;
    Integral<double> I(x, y, fonction);

    double z1 = I.rectangular(n);
    double z2 = I.trapezoidal(n);
    cout<<"le resultat avec la methode rectangulaire est :"<< z1 <<endl;
    cout<<"le resultat avec la methode de trapese est :"<< z2 <<endl;

    //I.change_bounds(M_PI/2,M_PI);
    I.change_bounds(0,1);
    double new_z1 = I.rectangular(n);
    double new_z2 = I.trapezoidal(n);
    cout<<"le  nouveau resultat avec la methode rectangulaire apres changement des bornes  est :"<< new_z1 <<endl;
    cout<<"le  nouveau resultat avec la methode de trapese apres changement des bornes est :"<< new_z2 <<endl;

    return 0;
}