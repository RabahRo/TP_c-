#include <iostream>
#include<cmath>
#include"power.hpp"
using namespace std;
int main(){
	double x,a;
	cout<<"la valeur de x est :";
      cin>> x;
      cout<<"la valeur de a est :";
      cin>> a;
      cout<<"le resultat est :"<<power(x, a);
      return 0;
}
