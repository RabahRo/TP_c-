#include <iostream>
#include <cmath>
#include "rectangulair.hpp"
#include "trapese.hpp"
using namespace std;
// Fonction à intégrer, exemple : f(x) = sin(x)
double fonction(double x) {
    return std::sin(x); // Exemple : intégrale de sin(x)
}

int main() {
    double a = 0.0, b = M_PI; // Bornes de l'intégration
    int N = 1000; // Nombre de sous-intervalles

    // Création des objets pour les méthodes d'intégration
    RectangleIntegrator<double> ri(a, b, fonction);
    TrapezoidalIntegrator<double> ti(a, b, fonction);

    // Calcul de l'intégrale avec la méthode des rectangles
    double x1 = ri.computeIntegral(N);
    cout << "Le resultat de l'intégrale (Rectangle) : " << x1 << endl;
    // Calcul de l'intégrale avec la méthode des trapèzes
    double x2 = ti.computeIntegral(N);
    cout << "Le resultat de l'intégrale (Trapese) : " << x2 << endl;

    // Changer les bornes d'intégration
    double new_x1 = ri.change_bounds(M_PI / 2, M_PI);
    cout << "Le resultat de l'intégrale (Rectangle) apres le changement de borne : " << new_x1 << endl;
    double new_x2 = ti.change_bounds(M_PI / 2, M_PI);
    cout << "Le resultat de l'intégrale (Trapese) apres le changement de borne : " << new_x2 << endl;

    return 0;
}