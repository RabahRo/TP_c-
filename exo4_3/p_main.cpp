#include <iostream>
#include "point.hpp"

using namespace std;

int main(){

    double x[]={1., 1.};
    double y[]={3., 1., 2.};

    point<2> P(x);
    point<3> Q(2.);

    cout << "P= " << P <<endl;
    cout << "Q= " << Q <<endl;

    point<2> R(P);
    cout << "R= " << R <<endl;

    Q.zero();
    cout << "Q= " << Q <<endl;


    point<3> W, V(y);
    W = V;
    cout << "W=V = " << W <<endl;
    //
    W = -Q;
    cout << "W=-Q = " << W <<endl;


    W = +Q;
    cout << "W=+P = " << W <<endl;
    
    point<2> s;
    s = R + P;
    cout << "s =R+P = " << s <<endl;
    point<3> n;
    n = W - Q;
    cout << "n =W-Q = " << n <<endl;

    return 0;
}