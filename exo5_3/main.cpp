#include<iostream>
#include"coef_binomial.hpp"
#include"binomial_template.hpp"

using namespace std;


const int M=11;
const Binomial<M> triangle ;
int main(){
    cout << " triangle (9,5) " << triangle(9,5) << endl ;
    return 0;
}