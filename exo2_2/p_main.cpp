#include <iostream>
#include "point.hpp"

using namespace std;

int main(){

    double x[]={1., 1.};

    point P(x);
    point Q(2.);

    cout << "P= " << P <<endl;
    cout << "Q= " << Q <<endl;

    point R(P);
    cout << "R= " << R <<endl;

    Q.zero();
    cout << "Q= " << Q <<endl;

    double y[]={1., 2.};
    point W, V(y);
    W = V;
    cout << "W=V = " << W <<endl;
    //
    W = -P;
    cout << "W=-P = " << W <<endl;


    W = +P;
    cout << "W=+P = " << W <<endl;
    
    point s,n;
    s = W + P;
    cout << "s =W+P = " << s <<endl;

    n = W - P;
    cout << "n =W-P = " << n <<endl;

    return 0;
}