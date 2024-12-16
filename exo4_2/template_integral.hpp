#pragma once
#include <iostream>
#include <functional> // Pour std::function
typedef double (*ptf)(double);
template <typename T>
class Integral {
protected:
    T a, b;                            // Bornes d'intégration
    ptf f; 
public:
    // Constructeur
    Integral(T a, T b, ptf f);

    // Accesseurs
    T lowbd() const { return a; }
    T upbd() const { return b; }

    // Méthode pour changer les bornes d'intégration
    void change_bounds(T new_a, T new_b);

    // Méthodes pour calculer l'intégrale
    T rectangular(int n) const;       // Règle des rectangles
    T trapezoidal(int n) const;       // Règle des trapèzes
};
// Constructeur
template <typename T>
Integral<T>::Integral(T a, T b, ptf f) : a(a), b(b), f(f) {}

// Méthode pour changer les bornes d'intégration
template <typename T>
void Integral<T>::change_bounds(T new_a, T new_b) {
    a = new_a;
    b = new_b;
}

// Méthode pour calculer l'intégrale avec la règle des rectangles
template <typename T>
T Integral<T>::rectangular(int n) const {
    T h = (b - a) / n;
    T integ = 0.0;
    for (int i = 0; i < n; ++i) {
        T xi = a + i * h;
        integ += f(xi) * h;
    }
    return integ;
}

// Méthode pour calculer l'intégrale avec la règle des trapèzes
template <typename T>
T Integral<T>::trapezoidal(int n) const {
    T h = (b - a) / n;  // Taille du pas
    T integ = 0.5 * (f(a) + f(b));  

    for (int i = 1; i < n; ++i) {  
        T xi = a + i * h;
        integ += f(xi);  
    }

    integ *= h;  
    return integ;
}

// Explicit instantiation for common types
template class Integral<double>;
template class Integral<float>;