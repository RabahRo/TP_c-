

template <typename T>
T somme_vect(T xx[], int nn){
    T sum = 0;
    for(int ii=0; ii<nn; ++ii){
        sum +=xx[ii];
    }
    return sum;
}