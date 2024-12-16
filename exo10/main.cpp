#include<iostream>
#include"rect.hpp"
#include"trapaze.hpp"
#include"fonction.hpp"

using namespace std;
int main(){
    double result = rectangular (0. , 5. , Function1, 100);
    cout << " Integral_using_rectangular_with_n_=_100_is : " << result << endl;
    result = trapese(0. , 5. , Function1, 100);
    cout << " Integral_using_trapezoidal_with_n_=100_is : " << result <<endl;
    result = trapese(0. , 5. , Function2 , 100);
    cout << " Integral_using_trapezoidal_with_n_=100_is : " << result <<endl ;
    return 0;
}