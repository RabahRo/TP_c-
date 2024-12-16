

template <typename T>
T lagrange(T* z, T* y, T xx, const int nn){
    T result = 0;
    for(int ii =0; ii<nn; ii++){
        T L_i = 1;
        for(int jj=0; jj<nn; jj++){
            if (jj != ii){
                L_i *= (xx-z[ii])/(z[jj]-z[ii]);
            }
        }
        result += y[ii]*L_i;
    }
    return result;
}