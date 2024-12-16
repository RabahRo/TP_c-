#include"coef_binomial.hpp"
template<int M>
class Binomial{
  private:
    double coeff[M][M] ;
  public:
    Binomial(); // populate the triangle
    double operator()(int nn, int kk) const;    // return the binomial coefficient "k among n"
};
template<int M>
Binomial<M>::Binomial(){
  for (int nn = 0; nn < M; ++nn) {
    for (int kk = 0; kk <= nn; ++kk) {
      coeff[nn][kk] = Coef_B(nn,kk);
    }
  }
}
template<int M>
double Binomial<M>::operator()(int nn, int kk) const {
        if (nn >= M || kk > nn) {
            // Return 0 for invalid indices
            return 0.0;
        }
        return coeff[nn][kk];
    }