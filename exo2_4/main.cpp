#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main() {
    // Test du constructeur par défaut
    cout << "Test du constructeur par défaut:" << endl;
    Matrix3d m1;
    cout << "m1 =\n" << m1 << endl;

    // Test du constructeur avec une valeur
    cout << "Test du constructeur avec une valeur:" << endl;
    Matrix3d m2(3.0);
    cout << "m2 =\n" << m2 << endl;

    // Test du constructeur avec un tableau 2D
    cout << "Test du constructeur avec un tableau 2D:" << endl;
    double values[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    Matrix3d m3(values);
    cout << "m3 =\n" << m3 << endl;

    // Test de l'accès aux éléments
    cout << "Test de l'accès aux éléments:" << endl;
    cout << "m3(1, 2) = " << m3(1, 2) << endl;
    m3(1, 2) = 10.0;
    cout << "Après modification, m3(1, 2) = " << m3(1, 2) << endl;

    // Test des opérateurs arithmétiques
    cout << "Test des opérateurs arithmétiques:" << endl;
    Matrix3d m4 = m2 + m3;
    cout << "m4 = m2 + m3 =\n" << m4 << endl;

    Matrix3d m5 = m3 - m2;
    cout << "m5 = m3 - m2 =\n" << m5 << endl;

    Matrix3d m6 = m3 * 2.0;
    cout << "m6 = m3 * 2.0 =\n" << m6 << endl;

    Matrix3d m7 = 0.5 * m3;
    cout << "m7 = 0.5 * m3 =\n" << m7 << endl;

    // Test de l'opérateur += et -=
    cout << "Test de l'opérateur += et -=:" << endl;
    m4 += m2;
    cout << "m4 += m2 =\n" << m4 << endl;

    m5 -= m2;
    cout << "m5 -= m2 =\n" << m5 << endl;

    // Test du produit matriciel
    cout << "Test du produit matriciel:" << endl;
    Matrix3d m8 = m3 * m2;
    cout << "m8 = m3 * m2 =\n" << m8 << endl;

    // Test de la multiplication par un scalaire avec l'opérateur *=
    cout << "Test de la multiplication par un scalaire avec l'opérateur *=:" << endl;
    m8 *= 2.0;
    cout << "m8 *= 2.0 =\n" << m8 << endl;

        double values2[2][2] = {
        {1.0, 2.0},
        {3.0, 4.0}
    };
    Matrix2d m9(values2);
    cout << "m9 =\n" << m9 << endl;
    Matrix2d m12 = m9 * m9;
    cout << "m12 = m9 * m9 =\n" << m12 << endl;

    Matrix2d m10 = m9 + m9;
    cout << "m10 = m9 + m9 =\n" << m10 << endl;

    Matrix2d m11 = m9 * 2.0;
    cout << "m11 = m9 * 2.0 =\n" << m11 << endl;

    // Test du produit Matrice-Matrice avec Matrix2d
    cout << "Test du produit Matrice-Matrice avec Matrix2d:" << endl;
    

    // Test des alias pour des matrices avec des types différents
    cout << "Test avec une matrice d'entiers (Matrix2):" << endl;
    int int_values[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Matrix2 m13(int_values);
    cout << "m13 =\n" << m13 << endl;

    Matrix2 m14 = m13 * 2;
    cout << "m14 = m13 * 2 =\n" << m14 << endl;

    // Test de l'ajout sur une matrice d'entiers
    cout << "Test de l'ajout sur une matrice d'entiers:" << endl;
    m13 += m14;
    cout << "m13 += m14 =\n" << m13 << endl;

    // Test du destructeur et gestion mémoire
    cout << "Test de destruction (gestion mémoire automatique):" << endl;
    {
        Matrix3d K(5.0);
        cout << "K(5.0) =\n" << K << endl;
    } // La matrice est automatiquement détruite ici

    cout << "Tous les tests sont terminés avec succès !" << endl;

    return 0;
}

