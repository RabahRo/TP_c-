#include<iostream>
#include<cmath>
using namespace std;
double factorial(int n){
	double fact = 1.0;
	for (int i = 1; i<=n; ++i){
		fact= i*fact;
      }
      return fact;
}
double Coef_B(int n, int k){
	return factorial(n)/(factorial(k)*factorial(n-k));
		}
int main(){
	int n;
	cout<<"donner la valeur de n :";
	cin>> n;
	int triangle[n][n];
	for(int i = 0; i<n; ++i){
		for (int j = 0; j<=i; ++j){
			triangle[i][j] = Coef_B(i,j) ;
		}
	}
	cout<<"le triangle de pascal est :"<<"\n";
	for(int i = 0; i<n; ++i){
		for(int j = 0;j<=i;++j)
		      cout<<triangle[i][j]<<"";
		cout<<endl;
	}
	return 0;
}      

