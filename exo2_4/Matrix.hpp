#pragma once
#include <iostream>
#include "vector.hpp"

// --- Définition de la classe Matrix ---
template<int L, int C, typename T>
class Matrix : public vector<L, vector<C, T>> {
  private :
    T** coord;
  public:
    // Constructeurs
    Matrix();                            // Constructeur par défaut
    Matrix(T value);                     // Initialisation avec une valeur
    Matrix(T values[L][C]);              // Initialisation avec un tableau 2D

    // Accès aux éléments
    T operator()(int i, int j) const;    // Lecture d'un élément
    T& operator()(int i, int j);         // Modification d'un élément

    // Opérateur *= (Multiplication par un scalaire)
    const Matrix& operator*=(const T& scalar);
    const Matrix<L, C, T>& operator+=(const Matrix<L, C, T>& p);
    const Matrix<L, C, T>& operator-=(const Matrix<L, C, T>& p);
    // Opérateur d'affichage
    template<int P, int Q, typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<P, Q, U>& mat);

    // Opérateurs sur matrices
    template<int P, int Q, typename U>
    friend const Matrix<P, Q, U> operator+(const Matrix<P, Q, U>& a, const Matrix<P, Q, U>& b);

    template<int P, int Q, typename U>
    friend const Matrix<P, Q, U> operator-(const Matrix<P, Q, U>& a, const Matrix<P, Q, U>& b);

    template<int P, int Q, typename U>
    friend const Matrix<P, Q, U> operator*(const Matrix<P, Q, U>& mat, const U& scalar);

    template<int P, int Q, typename U>
    friend const Matrix<P, Q, U> operator*(const U& scalar, const Matrix<P, Q, U>& mat);

    // Produit Matrice-Matrice
    template<int P, int Q, int R, typename U>
    friend const Matrix<P, R, U> operator*(const Matrix<P, Q, U>& a, const Matrix<Q, R, U>& b);
};

// --- Constructeurs ---
template<int L, int C, typename T>
Matrix<L, C, T>::Matrix() : vector<L, vector<C, T>>() {
    coord = new T*[L];
    for (int i = 0; i < L; i++) {
        coord[i] = new T[C]();
    }
}

template<int L, int C, typename T>
Matrix<L, C, T>::Matrix(T value) {
    coord = new T*[L];
    for (int i = 0; i < L; i++) {
        coord[i] = new T[C];
        for (int j = 0; j < C; j++) {
            coord[i][j] = value; // Correctement assigné
        }
    }
}

template<int L, int C, typename T>
Matrix<L, C, T>::Matrix(T values[L][C]) {
    coord = new T*[L]; // Allocation de mémoire pour les lignes
    for (int i = 0; i < L; i++) {
        coord[i] = new T[C]; // Allocation pour chaque colonne
        for (int j = 0; j < C; j++) {
            coord[i][j] = values[i][j]; // Copie des valeurs
        }
    }
}

// --- Accès aux éléments ---
template<int L, int C, typename T>
T Matrix<L, C, T>::operator()(int i, int j) const {
    return coord[i][j];
}

template<int L, int C, typename T>
T& Matrix<L, C, T>::operator()(int i, int j) {
    return coord[i][j];
}

// --- Opérateur *= (Multiplication par un scalaire) ---
template<int L, int C, typename T>
const Matrix<L, C, T>& Matrix<L, C, T>::operator*=(const T& scalar) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            coord[i][j] *= scalar;  // Multiply each element by scalar
        }
    }
    return *this;
}

// --- Opérateur d'affichage ---
template<int L, int C, typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<L, C, T>& mat) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            os << mat(i, j) << " "; // Affiche la valeur à (i, j)
        }
        os << "\n"; // Nouvelle ligne pour chaque ligne de la matrice
    }
    return os;
}

// --- Opérateurs sur matrices ---
template<int L, int C, typename T>
const Matrix<L, C, T> operator+(const Matrix<L, C, T>& a, const Matrix<L, C, T>& b) {
    Matrix<L, C, T> result = a;  // Start with a copy of matrix a
        result += b;  // Add b to it
        return result;
}

template<int L, int C, typename T>
const Matrix<L, C, T> operator-(const Matrix<L, C, T>& a, const Matrix<L, C, T>& b) {
    Matrix<L, C, T> result =a;
    result -= b;
    return result;
}

template<int L, int C, typename T>
const Matrix<L, C, T> operator*(const Matrix<L, C, T>& mat, const T& scalar) {
    Matrix<L, C, T> result = mat;
    result *= scalar;
    return result;
}

template<int L, int C, typename T>
const Matrix<L, C, T> operator*(const T& scalar, const Matrix<L, C, T>& mat) {
    return mat * scalar;
}

// --- Produit Matrice-Matrice ---
template<int P, int Q, int R, typename T>
const Matrix<P, R, T> operator*(const Matrix<P, Q, T>& a, const Matrix<Q, R, T>& b) {
    Matrix<P, R, T> result;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            result(i, j) = 0;
            for (int k = 0; k < Q; k++) {
                result(i, j) += a(i, k) * b(k, j);
            }
        }
    }
    return result;
}
template<int L, int C, typename T>
const Matrix<L, C, T>&Matrix<L, C, T>:: operator+=(const Matrix<L, C, T>& p) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            coord[i][j] += p.coord[i][j];
        }
    }
    return *this;
}
template<int L, int C, typename T>
const Matrix<L, C, T>&Matrix<L, C, T>:: operator-=(const Matrix<L, C, T>& p) {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            coord[i][j] -= p.coord[i][j];
        }
    }
    return *this;
}

// --- Alias utiles ---
using Matrix2d = Matrix<2, 2, double>;
using Matrix3d = Matrix<3, 3, double>;
using Matrix2 = Matrix<3, 3, int>;
