#include<iostream>
#include"sum_template.hpp"

using namespace std;

int main(){
    double x[] = {1,2,3,4};
    int a = sizeof(x)/ sizeof(x[0]);
    cout<<"la somme des elément de vecteur x est : "<< somme_vect(x,a)<<endl;
    return 0;
}