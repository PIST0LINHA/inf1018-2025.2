#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

//copia o conteudo de val para res respeitando o sinal de val
void big_val(BigInt res, long val)
{
  memcpy(res, &val, sizeof(long));
  unsigned char fill = (val < 0) ? 0xFF : 0x00;
  
  for(int i = sizeof(long); i < NUM_BITS/8; i++) res[i] = fill;
}


//envia o valor de a invertido e respeitando o complemento a 2 para res
void big_comp2(BigInt res, BigInt a)
{
  memcpy(res, a, NUM_BITS/8);

  for(int i = 0; i < NUM_BITS/8; i++) res[i] = ~res[i];

  int carry = 1;
  for(int i = 0; i < NUM_BITS/8; i++)
  {
	int tmp = (int)res[i];
	res[i] = (unsigned char)(tmp & 0xFF);
	carry = (tmp >> 8) & 0x01;
	if(!carry) break;
  }
}


//soma a com b e poe o resultado em res
void big_sum(BigInt res, BigInt a, BigInt b)
{
  int carry = 1;
  for(int i = 0; i < NUM_BITS/8; i++)
  {
	int tmp = (int)a[i] + (int)b[i]; 
	carry = (tmp >> 8) & 0x01;
	tmp = tmp + carry;
	res[i] = (unsigned char)(tmp & 0xFF);
	if(!carry) break;
  }
}

//subtrai a com b e poe o resultado em res
void big_sub(BigInt res, BigInt a, BigInt b)
{
  for(int i = 0; i < NUM_BITS/8; i++)
  {
	int tmp = (int)a[i] - (int)b[i];
	if(tmp < 0)
	{
	  tmp = 0;
	  res[i] = 0xFF;
	}
	res[i] = (unsigned char)(tmp & 0xFF);
  }
}
