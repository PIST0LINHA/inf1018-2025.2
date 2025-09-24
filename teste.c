#include <stdio.h>
#include "bigint.h"

int main()
{
  BigInt teste;
  long val = 0x0102030405060708;
  big_val(teste, val);

  BigInt teste2;
  big_comp2(teste2, teste);
  
  BigInt teste3;
  BigInt a, b;
  long val3 = 0x0F;
  long val4 = 0x01;
  big_val(a, val3);
  big_val(b , val4);
  big_sum(teste3, a, b);

  for(int i = 0; i < 128/8; i++)
  {
	printf("%02x ", teste3[i]);
  }
  printf("\n");
  return 0;
}
