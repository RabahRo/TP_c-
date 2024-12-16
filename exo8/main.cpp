#include<iostream>
#include"prod.hpp"
using namespace std;
int main(){
    int k;
    cout<<"la taille de vecteur est :";
    cin>> k;
    double *u = new double[k];
    double *v = new double[k];
    for(int i = 0;i< k;++i){
        cout<<"choisir les valeur de u"<<endl;
        cin>> u[i];
    }    
    for(int i = 0;i< k;++i){    
        cout<<"choisir les valeur de v"<<endl;
        cin>> v[i]; 
    }
    cout<<"le produit scalaire de u et v est:"<<prod_scalaire(u,v,k);
    delete[]u;
    delete[]v;
    return 0;
}