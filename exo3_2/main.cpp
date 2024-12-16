#include <iostream>
#include "class_dynamicVector.hpp"

using namespace std;

int main(){

double x[]={1., 1.};

dynamicVector P(2, x);
dynamicVector Q(2, 2.);

cout << "P" << P;
cout << "Q" << Q;

 dynamicVector R(P);
 cout << "R" << R;
 cout << endl;

 Q.zero();
 cout << "Q" << Q;
 cout << endl;

 double y[]={1., 2.};
 dynamicVector W(2), V(2, y);
 W = V;
 cout << "W=V" << W;
 cout << endl;
 //
 W = -P;
 cout << "W=-P" << W;
 cout << endl;

 W = +P;
 cout << "W=+P" << W;
 cout << endl;
 //
 W += V;
 cout << "W+=V" << W;
 
 W -= V;
 cout << "W-=V" << W;
 
 P = W + Q;  //  the same as P=operator+(W,Q);
 cout << "P" << P;
 double k = 2;
 P= P*k;
 cout << "P = P*k =" << P;
 
 P = W - W;  //  the same as P=operator+(W,Q);
 cout << "P" << P;

 return 0;

}
