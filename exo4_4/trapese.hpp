#pragma once
#include "integral.hpp"
template<typename T>
class TrapezoidalIntegrator : public Integral<T> {
public:
    // Constructeur
    TrapezoidalIntegrator(T a, T b, ptf f);

    // Implémentation de la méthode virtuelle pour le calcul de l'intégrale
    T computeIntegral(int Nint) const ;  //override
};
template<typename T>
TrapezoidalIntegrator<T>::TrapezoidalIntegrator(T a, T b, ptf f)
    : Integral<T>(a, b, f) {}

// Méthode pour calculer l'intégrale avec la règle des trapèzes
template<typename T>
T TrapezoidalIntegrator<T>::computeIntegral(int Nint) const {
    T h = (this->bb - this->aa) / Nint;
    T result = 0.5 * (this->ff(this->aa) + this->ff(this->bb));
    

    for (int i = 1; i < Nint; ++i) {
        T xi = this->aa + i * h;
        result += this->ff(xi);
    }

    result *= h;
    return result;

    //std::cout << "Résultat de l'intégrale (Trapèze) : " << result << std::endl;
}