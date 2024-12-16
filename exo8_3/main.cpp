#include <iostream>
#include "dynamic_vector.hpp"

using namespace std;

int main(){

   dynamic_vector<2, double> P(2, 2.0); // Initialisation correcte
    dynamic_vector<2, double> Q(2, 1.0); // Initialisation correcte
    cout << "P" << P;
    cout << "Q" << Q;

    dynamic_vector<2, double> R(P);
    cout << "R" << R << endl;

    dynamic_vector<2, double> W(2, 2.0);  // Initialisation correcte
    dynamic_vector<2, double> V = W;
    cout << "W=V" << W << endl;

    W = -P;
    cout << "W=-P" << W << endl;

    W = +P;
    cout << "W=+P" << W << endl;

    W += V;
    cout << "W+=V" << W << endl;

    W -= V;
    cout << "W-=V" << W << endl;

    P = W + Q;
    cout << "P" << P << endl;

    double k = 2;
    dynamic_vector<2, double> S = P * k;
    cout << "S = P*k =" << S << endl;

    dynamic_vector<2, double> T = W - W;
    cout << "T = W-W =" << T << endl;


    return 0;

}