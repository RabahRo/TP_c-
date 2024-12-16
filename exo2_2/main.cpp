#include <iostream>
#include "class_point.hpp"

using namespace std;

int main(){

double x[]={1., 1.};

point P(x);
point Q(2.);

cout << "P" << P;
cout << "Q" << Q;

 point R(P);
 cout << "R" << R;
 cout << endl;

 Q.zero();
 cout << "Q" << Q;
 cout << endl;

 double y[]={1., 2.};
 point W, V(y);
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
 // W += V;
 // cout << "W+=V" << W;
 //
 // W -= V;
 // cout << "W-=V" << W;
 //
 // P = W + Q;  //  the same as P=operator+(W,Q);
 // cout << "P" << P;
 //
 // P = W - W;  //  the same as P=operator+(W,Q);
 // cout << "P" << P;
 //
 // W = P + 1.0;
 // cout << "W=P+1" << W;
 //
 // point K = 1.0;
 // cout << "K= " << K;
 //
 // W = 1.0 + W;
 // cout << "W=1+W" << W;
 //
 // W = W - 1.0;
 // cout << "W=W-1" << W;
 //
 //
 // W += 1.0;
 // cout << "W+=1" << W;
 //
 // W -= 1.0;
 // cout << "W-=1" << W;


 return 0;

}
