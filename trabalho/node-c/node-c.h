#include <mongoc.h>

typedef struct dado
{
  int id ;
  char chave[100];
  char valor[100];
}dados;

int exec(dados *,int);