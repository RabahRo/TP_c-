#include<iostream>
#include"point.hpp"
#include"class_derived_point.hpp"
using namespace std;

int main(){
    colorPoint<2> cp1(1.0, 55); // Point avec x=y=1.0 et couleur 55
    colorPoint<2> cp2;

    cp2.set(0, 3.0); // Définir x=3.0
    cp2.set(1, 4.0); // Définir y=4.0
    cp2.setColor(66); // Changer la couleur

    std::cout << "cp1: " << cp1 << std::endl;
    std::cout << "cp2: " << cp2 << std::endl;

    cp2.zero(); // Réinitialiser cp2
    std::cout << "cp2 after zero(): " << cp2 << std::endl;

    return 0;
}