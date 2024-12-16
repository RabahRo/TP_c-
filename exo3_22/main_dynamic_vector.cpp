#include <iostream>
#include "dynamic_vector.hpp"

using namespace std;

int main(){

    double x[]={1., 1.};

    dynamic_vector P(2, x);
    dynamic_vector Q(2, 2.);

    cout << "P" << P;
    cout << "Q" << Q;

    dynamic_vector R(P);
    cout << "R" << R << endl;

    Q.zero();
    cout << "Q" << Q << endl;


    double y[]={1., 2.};
    dynamic_vector W(2), V(2, y);
    W = V;
    cout << "W=V" << W << endl;

    //
    W = -P;
    cout << "W=-P" << W << endl;

    W = +P;
    cout << "W=+P" << W << endl;
 
     //
    W += V;
    cout << "W+=V" << W << endl;
 
    W -= V;
    cout << "W-=V" << W << endl;
 
    P = W + Q;  
    cout << "P" << P << endl;
    double k = 2;
    P= P*k;
    cout << "P = P*k =" << P << endl;
 
    P = W - W; 
    cout << "P = W-W =" << P << endl;

    return 0;

}