#include <iostream>
#include"integral.hpp"
#include <cmath> // Pour les fonctions mathématiques comme std::sin

typedef double (*ptf)(double); // Type pour les pointeurs de fonctions


    // Constructeur
integral::integral(double a, double b, ptf f) : a(a), b(b), f(f) {}

    // Accesseurs pour les bornes


    // Méthode pour changer les bornes d'intégration
void integral::change_bounds(double new_a, double new_b) {
    a = new_a;
    b = new_b;
}

    // Méthode pour calculer l'intégrale avec la règle des rectangles
double integral::rectangular(int nn) const {
    double h = (b - a) / nn;
    double integ = 0.0;
    for (int i = 0; i < nn; ++i) {
        double xi = a + i * h;
        integ += f(xi) * h;
    }
    return integ;
}

    // Méthode pour calculer l'intégrale avec la règle des trapèzes
double integral::trapezoidal(int nn) const {
    double h = (b - a) / nn;  // Taille du pas
    double integ = 0.5 * (f(a) + f(b));  

    for (int i = 1; i < nn; ++i) {   
        double xi = a + i * h;
        integ += f(xi);  
    }

    integ *= h;  
    return integ;
}
