#include<iostream>
#include"vector.hpp"

using namespace std;

int main(){

    //double x[]={1., 1.};
    vector<2, double> P = (1.,2.);
    vector<2, double> Q;
    Q = -P;
    point2d S = -P;

    vector<3, int> N = (1,2,3);
    point3d K = +N;

    cout << "N= " << N<<endl;
    cout << "P= " << P<<endl;
    cout << "Q= " << Q<<endl;
    cout << "P-Q= " << P-Q<<endl;
    cout << "S+Q= " << S+Q<<endl;
    cout << "K*N= " << K*N<<endl;
    cout << "La norme euclidien de P est : " << P.norm2()<<endl;
    return 0;
}