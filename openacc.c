#include <stdio.h>


void main(){


    #pragma acc data copy(A, Anew)
        while ( error > tol && iter < iter_max )
        {
      error = 0.f;
     
    #pragma omp parallel for shared(m, n, Anew, A)
    #pragma acc kernels
      for( int j = 1; j < n-1; j++)
      {
    for( int i = 1; i < m-1; i++ )
    {
        Anew[j][i] = 0.25f * ( A[j][i+1] + A[j][i-1]
     + A[j-1][i] + A[j+1][i]);
        error = fmaxf( error, fabsf(Anew[j][i]-A[j][i]));
    }
      }
     
    #pragma omp parallel for shared(m, n, Anew, A)
    #pragma acc kernels
      for( int j = 1; j < n-1; j++)
      {
    for( int i = 1; i < m-1; i++ )
    {
        A[j][i] = Anew[j][i];    
    }
      }
     
      if(iter % 100 == 0) printf("%5d, %0.6fn", iter, error);
     
      iter++;
        }
     
        double runtime = GetTimer();
     
        printf(" total: %f sn", runtime / 1000.f);
    }
    



}