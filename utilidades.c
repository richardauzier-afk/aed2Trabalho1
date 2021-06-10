#include <stdio.h>
void removeChar(char *p, char c){

  if(p == NULL){
    return ;
  }
  char *pDestino = p;

  while(*p){
    if(*p != c){
      *pDestino++ = *p;
    }
    p++;
  }
  *pDestino = '\0';
}


FILE *abrirArquivo(){
  FILE *fp;
  fp = fopen("../../dados/datasetCEP/curto10e2.txt", "r");
  return fp;
}

