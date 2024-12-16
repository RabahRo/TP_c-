typedef double (*ptf)(double);
double rectangular(double a, double b, ptf f, int n){
    double h = (b-a)/(double) n;
    double integral = 0.;
    for(int i=0; i<n; ++i){
        double xi = a+i*h;
        integral += (f)(xi)*h;
    }
    return integral;

}