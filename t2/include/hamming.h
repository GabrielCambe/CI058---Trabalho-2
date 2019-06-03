#ifndef HAMMING_H
#define HAMMING_H

#include <stdio.h>

int space_flag;

typedef struct{
  unsigned bit0:1;
  unsigned bit1:1;
  unsigned bit2:1;
  unsigned bit3:1;
  unsigned bit4:1;
  unsigned bit5:1;
  unsigned bit6:1;
  unsigned bit7:1;
}ASCIIcode; //ASCII Code
typedef union {
  ASCIIcode bin;
  unsigned char caractere; 
}letra;

//Codificação
char* EncodeBin( char *arq_tmp );
void ChartoBin( unsigned char c, int size, FILE* out );
char* ASCIItoBin( char* arq_txt );
char* codificar_texto( char *arq_texto );

//Decodificação
char* decodificar_texto( char *arq_bin );
char* lerBloco( FILE *texto_codificado, char *bloco );
int detectarErros( char* blocoDe15_bin );
char* BintoASCII( char *corrigido_tmp );
void corr_DecodBloco( char *blocoDe15_bin, int posicao, FILE* texto_corrigido);


#endif