typedef int (*TRecuperarDigitoChaveRS)(void *s1, int dig);  
static void rs(void* L[],  int  N, int dig, TRecuperarDigitoChaveRS recuperarDigito);
void radix(void* L[], int N, int nroDig, TRecuperarDigitoChaveRS recuperarDigito);
