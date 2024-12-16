double prod_scalaire(double *vect1,double *vect2, int n){
    double sum = 0.;
    for (int i =0; i<=n;++i){
        sum +=vect1[i]*vect2[i];
    } 
    return sum;
}