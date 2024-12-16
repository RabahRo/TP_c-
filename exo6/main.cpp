#include<iostream>
#include"exo6.hpp"
using namespace std;
int main() {
    double r, theta;
    double x, y; // Pour stocker la partie réelle et imaginaire

    // Demande des valeurs à l'utilisateur
    cout << "Entrez le module (r) : ";
    cin >> r;
    cout << "Entrez l'argument (theta en radians) : ";
    cin >> theta;

    CalculateRealAndImaginary(r, theta, x, y);

    // Affichage des résultats
    cout << "Partie réelle : " << x << endl;
    cout << "Partie imaginaire : " << y << endl;

    return 0;
}
/*
int main() {
    double r, theta;
    double x, y; // Pour stocker la partie réelle et imaginaire

    // Demande des valeurs à l'utilisateur
    cout << "Entrez le module (r) : ";
    cin >> r;
    cout << "Entrez l'argument (theta en radians) : ";
    cin >> theta;

    CalculateRealAndImaginary(r, theta, &x, &y);

    // Affichage des résultats
    cout << "Partie réelle : " << x << endl;
    cout << "Partie imaginaire : " << y << endl;

    return 0;
}
*/