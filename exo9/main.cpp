#include<iostream>
#include"fonction.hpp"

using namespace std;
int main(){
    double(*p_fonction)(double x);
    p_fonction = &myFunction;
    cout<<"le resultat1 est :"<<(*p_fonction)(3.0)<<endl;
    p_fonction = &myOtherFunction;
    cout<<"le resultat2 est :"<<(*p_fonction)(3.0);
    return 0;
}