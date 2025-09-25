#include <stdio.h>
#include "bigint.h"

void big_print(BigInt a)
{
	for(int i = 0; i < NUM_BITS/8; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void big_hexa(BigInt a)
{
	//big endian
	for(int i = NUM_BITS/8 - 1; i >= 0; i--)
	{
		printf("%x ", a[i]);
	}
	printf("\n");
}

void big_teste(BigInt a, const char* mensagem)
{
	printf("%s\n", mensagem);
	big_print(a);
	big_hexa(a);
	printf("\n");
}

int main()
{
  BigInt teste;
  long val = 0x0102030405060708;
  big_val(teste, val);
	
  big_teste(teste, "teste de extensao");

  BigInt teste2;
  big_comp2(teste2, teste);
   
  big_teste(teste2, "teste complemento a 2");

  BigInt teste3;
  BigInt a, b;
  long val3 = 0x0F;
  long val4 = 0x1a;
  big_val(a, val3);
  big_val(b , val4);
  big_sum(teste3, a, b);
  
  big_teste(teste3, "teste de soma");

  BigInt teste4;
  BigInt c,d;
  long val5 = 100;
  long val6 = 10;
  big_val(c, val5);
  big_val(d, val6);
  big_mul(teste4, c, d);

  big_teste(teste4, "teste de multiplicacao");

  BigInt teste5;
  BigInt e, f;
  long val7 = 10;
  long val8 = 12;
  big_val(e, val7);
  big_val(f, val8);
  big_sub(teste5, e, f);

  big_teste(teste5, "teste de subtracao");

  BigInt teste6;
  BigInt g;
  long val9 = 0xb1b2b3b4b5b6b7b8;
  big_val(g, val9);
  big_shr(teste6, g, 1);  

  big_print(g);
  big_teste(teste6, "teste de shift a direita");

  return 0;
}
