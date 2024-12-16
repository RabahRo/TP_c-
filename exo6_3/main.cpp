
#include<iostream>
#include"exp_pade.hpp"
#include"poly_pade.hpp"
#include"power.hpp"
#include"coef_binomial.hpp"
#include"binomial_template.hpp"
using namespace std;
int main() {
    double x;
    int y;
    int N = 5;  // Degré du polynôme de Padé
    cout << "Donner la valeur de x: ";
    cin >> x;
    cout << "Donner un entier y : ";
    cin >> y;
    cout << "L'approximation de exp(x) est: " << exp_pade<double,5>(x) << endl;
    cout << "L'approximation de exp(y) est: " << exp_pade<int,5>(y) << endl;
    return 0;
}
