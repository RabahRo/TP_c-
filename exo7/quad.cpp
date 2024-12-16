#include<iostream>
#include<cmath>
using namespace std;
pair<double,double>
quadraticRoot(const double & a, const double & b, const double & c){
    double delta = b*b -4*a*c;
    double tol = 1e-15;
    double x1;
    double x2;
    if(a == tol){
        return make_pair(x1 = -c/b,x2 = -c/b);
    }
    else if (delta == tol){
        return make_pair(x1 = -b/(2*a),x2 = -b/(2*a));
    }
    else if (delta > tol){
        return make_pair(x1 = (-b-sqrt(delta))/(2*a),x2 = (-b-sqrt(delta))/(2*a));
    }
    else{
        throw runtime_error("Erreur : Pas de racines réelles (discriminant négatif).");
        
    }

}