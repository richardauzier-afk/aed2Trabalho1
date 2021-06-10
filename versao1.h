#include <stdio.h>
#define TAM 1000
typedef struct tipoEndereco{
  char cep[100];
  char logradouro[TAM];
  char numero[100];
  char bairro[TAM];
  char cidade[TAM];
  char uf[TAM];
}tipoEndereco;


int compararEnderecos(void *s1, void *s2);
void imprimirEndereco(tipoEndereco *endereco);
void removeChar(char *p, char c);
FILE *abrirArquivo();
void popularArray(tipoEndereco *endereco, FILE *fp);
