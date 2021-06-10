#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linear.h"


static void rs(void* L[],  int  N, int dig, TRecuperarDigitoChaveRS recuperarDigito){
  void* B[N];
  int K =10;
  int contagem[K];
  memset(contagem,0,K*sizeof(int));

  for(int n=0;n<N;n++){
    int d = recuperarDigito(L[n],dig);
    contagem[d]++;
  }

  for(int k=1;k<K;k++){
    contagem[k] = contagem[k] + contagem[k-1];
  }

  for(int n=N-1;n>=0;n--){
    int d = recuperarDigito(L[n],dig);
    B[contagem[d]-1] = L[n];
    contagem[d]--;
  }

  printf("Parcial ==== %d\n",dig);
  for(int n=0;n<N;n++){
    L[n] = B[n];
  }
}

void radix(void* L[], int N, int nroDig, TRecuperarDigitoChaveRS recuperarDigito){

  for(int i=1; i<=nroDig; i++){
    rs(L, N, i, recuperarDigito);
  }

}

