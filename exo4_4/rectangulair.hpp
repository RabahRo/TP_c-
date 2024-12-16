#pragma once
#include "integral.hpp"

template <typename T>
class RectangleIntegrator : public Integral<T> {
public:
    // Constructeur
    RectangleIntegrator(T a, T b, ptf f);

    // Implémentation de la méthode virtuelle pour le calcul de l'intégrale
    T computeIntegral(int Nint) const ;   //override
};
template <typename T>
RectangleIntegrator<T>::RectangleIntegrator(T a, T b, ptf f)
    : Integral<T>(a, b, f) {}

// Méthode pour calculer l'intégrale avec la règle des rectangles
template <typename T>
T RectangleIntegrator<T>::computeIntegral(int Nint) const {
    T h = (this->bb - this->aa) / Nint;
    T result = 0.0;

    for (int i = 0; i < Nint; ++i) {
        T xi = this->aa + i * h;
        result += this->ff(xi);
    }
    result *= h;
    return result;

    //std::cout << "Résultat de l'intégrale (Rectangle) : " << result << std::endl;
}