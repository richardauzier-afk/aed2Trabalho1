#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "versao1.h"

#include "./ordenacao/nlogn/nlogn.h"
#include "./ordenacao/linear/v2/linear.h"
#include "./utilidades/utilidades.h"

//usada para os algoritmos de comparacao
int compararEnderecos(void *s1, void *s2){
  tipoEndereco *s1E = s1;
  tipoEndereco *s2E = s2;


  int ceps1 = atoi(s1E -> cep);
  int ceps2 = atoi(s2E -> cep);

  int numero1 = atoi(s1E -> numero);
  int numero2 = atoi(s2E -> numero);

  if(ceps1 != ceps2){
    return ceps1 - ceps2;
  }
  else{
    return numero1 - numero2;
  }
}
void imprimirEndereco(tipoEndereco *endereco){
  printf("%s;", endereco -> cep);
  printf("%s;", endereco -> logradouro);
  printf("%s;", endereco -> numero);
  printf("%s;", endereco -> bairro);
  printf("%s;", endereco -> cidade);
  printf("%s\n", endereco -> uf);
}

void popularArray(tipoEndereco *endereco, FILE *fp){
  for(int i = 0; i < TAM; i++){
    fscanf(fp, "%[^;];%[^;];%[^;];%[^;];%[^;];%2s\n",
        endereco[i].cep, endereco[i].logradouro,
        endereco[i].numero, endereco[i].bairro,
        endereco[i].cidade, endereco[i].uf);
    removeChar(endereco[i].cep, 45);
    //printf("%s\n", endereco -> cep);
  }
}

 int recuperarDigitoCep(void *s1, int dig){
   tipoEndereco *ss1 = s1;
   char sp[100];

   int cep = atoi(ss1 -> cep);
   int resultado = sprintf(sp,"%d",cep);


   // printf("%s\n", sp);
  char l = sp[strlen(sp)-dig];
  p  printf("%s\n", s);
   int d = atoi(&l);
   printf("%c\n", l);

   
   //printf("%d\n", d);
   return d;
}


int main(){
  FILE *fp;
  char buffer[TAM];

  tipoEndereco enderecos[TAM];

  fp = abrirArquivo();
  popularArray(enderecos, fp);



  void *entrada[TAM];

  for(int i = 0; i < TAM; i++){
    entrada[i] = &enderecos[i];
  }

  //quicksort(entrada, TAM, compararEnderecos);
  radix(entrada, TAM, 8, recuperarDigitoCep);

  /*
  for(int i = 0; i < 5; i++){
    imprimirEndereco(entrada[i]);

  }
  */

  return 0;
}

