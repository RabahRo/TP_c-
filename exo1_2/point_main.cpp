#include<iostream>
#include"point.hpp"
using namespace std;
int main() {
    // Test des constructeurs
    point P(3.0, 5.0);
    point Q(2.0, 6.0);
    point R(P); // Constructeur de copie

    // Affichage initial
    cout << "P: " << P << endl;
    cout << "Q: " << Q << endl;
    cout << "R: " << R << endl;

    // Modification et réinitialisation
    P.set(0, 7.0);
    P.set(1, 2.0);
    cout << "P apres modification: " << P << endl;

    Q.zero();
    cout << "Q apres reinitialisation: " << Q << endl;

    // Test des opérateurs
    P += Q; // Addition avec Q
    cout << "P += Q: " << P << endl;

    P -= 2.0; // Soustraction avec un double
    cout << "P -= 2.0: " << P << endl;

    point S = P + Q; // Addition de deux points
    cout << "S = P + Q: " << S << endl;

    point T = 1.0 - P; // Soustraction d'un double
    cout << "T = 1.0 - P: " << T << endl;

    // Test des opérateurs de conversion
    double px = (double)P; // Conversion de P en double
    cout << "Coordonnee x de P via conversion : " << px << endl;

    return 0;
}