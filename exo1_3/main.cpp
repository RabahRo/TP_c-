#include<iostream>
#include"fonction_template.hpp"


using namespace std;

int main(){
    int a = 2;
    double b = 2.5;
    float c = 3.2f;
    cout<<"le carré de a est : "<<func_carre(a)<<endl;
    cout<<"le carré de b est : "<<func_carre(b)<<endl;
    cout<<"le carré de c est : "<<func_carre(c)<<endl;

    return 0;
}