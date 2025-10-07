#nome: Lucas Manoel Martisn de Souza matricula: 2320715
#nome: Thiago Hellal Bello matricula: 2211881

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
  int carry = 0;
  for(int i = 0; i < NUM_BITS/8; i++)
  {
	int tmp = (int)a[i] + (int)b[i]; 
	carry = (tmp >> 8) & 0x01;
	tmp = tmp + carry;
	res[i] = (unsigned char)(tmp & 0xFF);
  }
}

//subtrai a com b e poe o resultado em res
void big_sub(BigInt res, BigInt a, BigInt b)
{
  int tmp = 0;
  for(int i = 0; i < NUM_BITS/8; i++)
  {
	int dif = (int)a[i] - (int)b[i] - tmp;
	if (dif < 0)
	{
	  dif += 256;
	  tmp = 1;
	}
	else 
	{
	  tmp = 0;
	}
	res[i] = (unsigned char)(dif & 0xFF);
  }
}

//guarda em res o produto de a * b
void big_mul(BigInt res, BigInt a, BigInt b)
{
  int tmp[(NUM_BITS/8) * 2];
  
  for(int i = 0; i < NUM_BITS/8; i++)
  {
	int carry = 0;
	for(int j = 0; j < NUM_BITS/8; j++)
	{
	  int produto = (int)a[i] * (int)b[i] + carry;
	  tmp[i + j] = produto & 0xFF;
	  carry = produto >> 8;
	}
	tmp[i] += carry;
  }

  //ignora overflow 
  for(int i = 0; i < NUM_BITS/8; i++)
  {
	res[i] = (unsigned char)(tmp[i] & 0xFF);
  }
}

void big_shl(BigInt res, BigInt a, int n)
{
  unsigned char fill = 0x00;
  for(int i = NUM_BITS/8 - 1; i > n; i--) res[i] = fill;
  for(int i = 0; i < NUM_BITS/8 - n; i++) res[i] = a[i];
}

void big_shr(BigInt res, BigInt a, int n)
{
  unsigned char fill = 0x00;
  for(int i = 0; i < n - 1; i++) res[i] = fill;
  for(int i = n, j = 0; i < NUM_BITS/8; i++, j++) res[i] = a[j];
}

void big_sar(BigInt res, BigInt a, int n)
{
  unsigned char MSB = a[0] & 0xFF;
  for(int i = 0; i < n - 1; i++) res[i] = MSB;
  for(int i = n, j = 0; i < NUM_BITS/8; i++, j++) res[i] = a[j];
}
