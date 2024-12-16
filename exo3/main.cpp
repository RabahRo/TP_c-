#include <iostream>
#include "fact.hpp"
#include "coef_b.hpp"

using namespace std;

int main() {
    int n;
    cout << "Donner la valeur de n : ";
    cin >> n;
	
    if (n <= 0) {
        cout << "La valeur de n doit être positive." << endl;
        return 1;
    }

    // Déclaration dynamique pour gérer des tailles variables
    int** triangle = new int*[n];
    for (int i = 0; i < n; ++i) {
        triangle[i] = new int[i + 1]; // Chaque ligne a i+1 colonnes
    }

    // Remplissage du triangle de Pascal
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] = Coef_B(i, j);
        }
    }

    // Affichage du triangle de Pascal
    cout << "Le triangle de Pascal est :" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    // Libération de la mémoire dynamique
    for (int i = 0; i < n; ++i) {
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}