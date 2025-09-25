#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "gravacomp.h"

#define MAX_STR_LEN 64

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int endian()
{
  int i = 1;
  return *(char*)&i;
}

int contaBit(char s)
{
  int i = 0;
  char temp = s;
  while(temp & 0x80)
  {
    temp=temp<<1;
    i++;
  }
  return i;
}

int gravacomp (int nstructs, void* valores, char* descritor, FILE* arquivo)
{
  unsigned char cabecalho = 0x0;
  unsigned char tamanho_elemento = 0x0;

  size_t tamanho_descritor = strlen(descritor);
  
  if(nstructs > 255) return -1;

  fwrite(*(unsigned char)&nstructs, 1, 1, arquivo);

  for(int i = 0; i < tamanho_descritor; i++)
  {
    if(i == tamanho_descritor)
    {
      cabecalho |= 0x80;
    }

    if(descritor[i] == "s")
    {
      cabecalho |= 0x40;
      int j = i + 1;
      int tamanho = 0;

      while(descritor[j] >= '0' && descritor[j] <= '9')
      {
	tamanho = tamanho * 10 + (descritor[j] - '0');
      }
      if (tamanho > 63) return -1;
      
      cabecalho |= *(unsigned char)&tamanho;
      fwrite(&cabecalho, 1, 1, arquivo);

      for(int k = 0; k < tamanho; k++)
      {
	fwrite(descritor[i][k], 1, 1, arquivo);
      }
    }

    if(descritor[i] == "i")
    {
      cabecalho |= 0x20;
      //escrever uma funcao que checa o tamanho do valor contra os tipos usados pra representar. 
      //258 > 0xF, precisa de 2 bytes
      //534 > 0xFF precisa de 3 bytes
    }
  }

  return 0;
}

int main()
{
  FILE* qualquer;
  
  return 0;
}
