#pragma once 
#include<iostream>

class point
{
private:
    double x,y ;
public:
    point(){}; // constructeur
    ~point(){}; // déstructeur
    point(double xx = 0.0, double yy= 0.0) : x(xx), y(yy){};   //  Constructeur par défaut
    point(const point& p) : x(p.x), y(p.y){};  //  copy constructor
    double X() const {return this->x;}; // Accesseurs pour x 
    double Y() const{return this->y;};  // Accesseurs pour  y
    void zero() {x = 0.0; y = 0.0;};  // Méthode pour réinitialiser le point à (0, 0)
    void set(int i, const double& a) {    
        if (i == 0) x = a;
        else if (i == 1) y = a;                    //  Méthode pour modifier une coordonnée
        else {std::cout<< "Index invalide !" << std::endl;}
    }
    const point& operator=(const point& p);     // Surcharge de l'opérateur d'affectation (point = point)
    const point& operator=(double xx);        // Surcharge de l'opérateur d'affectation (point = double)
   
    operator double() const{return this->x;}  //  inverse conversion
    friend const point operator-(const point& p); //10 opérateur -
    friend const point operator+(const point& p); //11 opérateur +
    const point& operator+=(const point& p);  //12  opérateur +=
    const point& operator-=(const point& p);  //13  opérateur -=
    const point& operator+=(double xx);
    const point& operator-=(double xx);
    friend const point operator+(const point& p, const point& q);
    friend const point operator-(const point& p, const point& q);
    friend const point operator+(const point& p, double xx);
    friend const point operator-(double xx, const point& p);
    friend std::ostream& operator<<(std::ostream& os, const point& p);
};

