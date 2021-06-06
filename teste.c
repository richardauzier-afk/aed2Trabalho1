#include <stdio.h>
#include <string.h>
#define TAMVLINHA 300

typedef struct tipoEndereco{
  int cep;
  char *logradouro;
  int numero;
  char *bairro;
  char *cidade;
  char *siglaEstado;
}tipoEndereco;

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
FILE *abrirArquivo(FILE *fp){
  int opcao;

  printf("Voce deseja usar qual mode para abrir o arquivo?\n");
  printf("Digite 1 para 'r'\n"); printf("Digite 2 para 'w\n"); printf("Digite 3 para 'a'\n\n");

  scanf("%d", &opcao);
  switch(opcao){
  case 1:
    return fp = fopen("../../dados/datasetCEP/curto10e2.txt", "rt");
  case 2:
    fp = fopen("../../dados/datasetCEP/curto10e2.txt", "wt");
    break;
  case 3:
    fp = fopen("../../dados/datasetCEP/curto10e2.txt", "at");
    break;
  }
}

char *lerArquivo(FILE *fp, char c[]){
  //FILE *resultadoP;
  char *resultado;

  if(fp == NULL){
    perror("Error: ");
  }

  //resultadoP = fopen("resultado.txt", "w+");

  while(fgets(c, TAMVLINHA, fp)){
    removeChar(c, 45);
    //fprintf(resultadoP, "%s", c);
    resultado = c;
    //printf("%s\n", resultado);
    printf("%p\n", resultado);
    resultado++;
    resultado++;
    printf("%p\n", resultado);
  }
  //printf("%s",resultado);
  return resultado;
  //return resultadoP;
}

int main(){
  FILE *fp, *rs;
  char buffer[TAMVLINHA];

  rs = abrirArquivo(fp);
  lerArquivo(rs, buffer);
  //printf("%s\n",buffer);

  
}
