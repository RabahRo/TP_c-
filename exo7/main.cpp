#include<iostream>
#include<cmath>
#include <utility>
#include"quad.hpp"
using namespace std;
int main(){
    double a,b,c;
    cout<<"donner les valeur de a,b et c successif:";
    cin>> a >>b >>c;
    try {
        // Calcul des racines
        pair<double, double> result = quadraticRoot(a, b, c);
        cout << "x1 = " << result.first << ", x2 = " << result.second << endl;
    }
     catch (const exception &e) {
        // Gestion des erreurs
        
        cout<< e.what() << endl;
    }
    return 0;
}