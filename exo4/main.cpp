#include <iostream>
#include <cmath>
#include "fact.hpp"
#include "power.hpp"
#include "expTaylor.hpp"
using namespace std;

// la fonction pour calculer automatiquement m
int M(double x) {
    int k = 0;
    while (abs(x / power(2, k)) > 0.5) {
        ++k;
    }
    return k;
}

int main() {
    int N = 10; // Nombre de termes dans la série de Taylor
    double x;

    cout << "Donner la valeur de x : ";
    cin >> x;

    if (abs(x) <= 0.5) {
        // Cas où x est petit (|x| <= 0.5)
        cout << "L'approximation de exp(x) est : " << expTaylor(x, N) << endl;
    } 
    else {
        // Cas où x est grand (|x| > 0.5)
        int m = M(x);
        double X = x / power(2, m); // Réduction de x

      	cout<<"L\'approximation de exp(x) est :"<<power((expTaylor(X,N)),power(2,m));

        
    }

    return 0;
}

