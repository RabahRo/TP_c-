#include<iostream>
typedef double (*ptf)(double); // Type pour les pointeurs de fonctions

class integral {
 private:
    double a, b;    // Bornes d'intégration
    ptf f;          // Pointeur vers la fonction intégrande

 public:
    integral(double a, double b, ptf f);
    double lowbd() const { return a; };
    double upbd() const { return b; };
    void change_bounds(double new_a, double new_b);
    double rectangular(int n) const;
    double trapezoidal(int n) const;

};