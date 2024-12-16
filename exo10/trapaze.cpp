typedef double (*ptf)(double);
double trapese(double a, double b, ptf f, int n){
    double h = (b-a)/(double) n;
    double integral = 0.;
    for(int i=0; i<n; ++i){
        double xi = a+i*h;
        integral += ((f)(xi)+(f)(xi+h))*h/2;
    }
    return integral;

}