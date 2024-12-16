#pragma once
#include"point.hpp"
template <int Ndim>
class colorPoint : public point<Ndim> {
private:
    unsigned color;

public:
    // Constructeurs
    colorPoint();
    colorPoint(double x, unsigned color);
    colorPoint(double x[Ndim], unsigned color);
    colorPoint(const colorPoint& p);

    // Méthodes
    unsigned Color() const;
    void setColor(unsigned newColor);
    void zero();

    // Surcharge de l'opérateur d'affichage
    template<int N>
    friend std::ostream& operator<<(std::ostream& os, const colorPoint<N>& p);
};

// Implémentation des méthodes de colorPoint
template <int Ndim>
colorPoint<Ndim>::colorPoint() : point<Ndim>(), color(0) {}

template <int Ndim>
colorPoint<Ndim>::colorPoint( double x, unsigned color) : point<Ndim>(x), color(color) {}

template <int Ndim>
colorPoint<Ndim>::colorPoint(double x[Ndim], unsigned color) : point<Ndim>(x), color(color) {}

template <int Ndim>
colorPoint<Ndim>::colorPoint(const colorPoint& p) : point<Ndim>(p), color(p.color) {}

template <int Ndim>
unsigned colorPoint<Ndim>::Color() const {
    return color;
}

template <int Ndim>
void colorPoint<Ndim>::setColor(unsigned newColor) {
    color = newColor;
}

template <int Ndim>
void colorPoint<Ndim>::zero() {
    point<Ndim>::zero(); // Appeler la méthode zero() de la classe de base
    color = 0;
}

template <int Ndim>
std::ostream& operator<<(std::ostream& os, const colorPoint<Ndim>& p) {
    os << "(";
    for (int ii = 0; ii < Ndim; ii++) {
        os << p.coord[ii];
        if (ii < Ndim - 1) os << ", ";
    }
    os << ") Color: " << p.color;
    return os;
}