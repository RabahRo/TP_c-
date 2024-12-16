#pragma once
#include <iostream>
#include <functional> // Pour std::function
typedef double (*ptf)(double);
template <typename T>
class Integral {
protected:
    T aa, bb;                            // Bornes d'intégration
    ptf ff; 
public:
    // Constructeur
    Integral(T a, T b, ptf f);

    // Accesseurs
    T lowbd() const { return aa; }
    T upbd() const { return bb; }

    // Méthode pour changer les bornes d'intégration
    T change_bounds(T new_a, T new_b);
    
    // Méthode virtuelle pure pour le calcul de l'intégrale
    virtual T computeIntegral(int Nint) const = 0;

    // Destructeur virtuel
    virtual ~Integral() = default;
    
};
// Constructeur
template <typename T>
Integral<T>::Integral(T a, T b, ptf f) : aa(a), bb(b), ff(f) {}

// Méthode pour changer les bornes d'intégration
template <typename T>
T Integral<T>::change_bounds(T new_a, T new_b) {
    return aa = new_a;
    return bb = new_b;
    
}

// Explicit instantiation for common types
template class Integral<double>;
template class Integral<float>;