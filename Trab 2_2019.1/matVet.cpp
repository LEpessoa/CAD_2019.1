#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
int const n = 30000;
int A[n][n], B[n], C[n];

int main(){
  double t0, t1, dt;
  int i = 0, j = 0, m = 0, k = 0, l= 0, aux;
  k = 0;
  //n = 2000;
  srand((unsigned int)time(NULL));
  //int A[n][n], B[n], C[n];
  for(m =0; m<n;m++){
    for(k=0;k<n;k++){
      A[m][k] = rand() % 3 + 1;
    }
  }

  for(l =0; l<n; l++){
    B[l]= rand() % 3 + 1;
  }

  t0= omp_get_wtime();
  
  #pragma omp parallel num_threads(2) private(i, j, aux) shared(A,B,C)
  { 
    #pragma omp for
    for(i = 0; i < n; i++){
      aux = 0;
      for(j =0; j <n; j++){
        aux = aux + A[i][j]*B[j];
      }
      C[i] = aux;
    }
  }
  t1= omp_get_wtime();
  dt = t1 - t0;


  printf("tempo de execucao = %f\n", dt);
  return 0;
}
