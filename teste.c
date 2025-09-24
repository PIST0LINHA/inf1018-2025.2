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


  BigInt teste4;
  BigInt c,d;
  long val5 = 2;
  long val6 = 3;
  big_val(c, val5);
  big_val(d, val6);
  big_mul(teste4, c, d);


  for(int i = 0; i < 128/8; i++)
  {
	printf("%d ", teste4[i]);
  }
  printf("\n");
  return 0;
}
