#include <iostream>
#include<cmath>


using namespace std;
// fonction factorial:
int factorial(int n){
	int fact = 1;
	for (int i = 1; i<=n; ++i){
		fact= i*fact;
      }
      return fact;
}
double power(double x,int a){//size_t a
    double r = 1.;
    for (int i = 1; i<=a;++i){
      r = r*x;
    }
    return r;
}
// fonction taylor exp :
double expTaylor(double x, int N){
	double sum = 0;
	
	for(int i = 0; i<=N; ++i){
		sum +=  (power(x,i)/factorial(i));	
	}
      
	return sum;         	
}
int main(){
	int N = 10;
	double x;
	cout<<"donner la valeur de x"<<"\n";
	cin>> x;
	
	
	if(abs(x)<=0.5){
	    cout<<"L\'approximation de exp(x) est :"<<expTaylor(x,N);
    }
      
    else{
      	int m = 0;
	    while (abs(x)>0.5)
	    {
		   x = x/2;
		   m++;
	    }
      	//double X = x/(power(2,m));
      	cout<<"L\'approximation de exp(x) est :"<<power((expTaylor(x,N)),power(2,m));
	}
	return 0; 
}
