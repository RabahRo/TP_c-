
#include<iostream>
#include"exp_pade.hpp"
#include"poly_pade.hpp"
#include"fact.hpp"
#include"power.hpp"
#include"coef_b.hpp"
using namespace std;
int main() {
    double x;
    int N = 2;  // Degré du polynôme de Padé
    cout << "Donner la valeur de x: ";
    cin >> x;
    cout << "L'approximation de exp(x) est: " << exp_pade(x, N) << endl;
    return 0;
}