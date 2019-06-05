#include <hamming.h>

#include <stdio.h>

void ChartoBin( unsigned char c, int tamanho, FILE* arquivo_temporario ){
  if ( c == 1 ){ 
    if ( tamanho == 0 ){
      // Se o ultimo bit for 1.
      fputs( "1", arquivo_temporario );
      return ;
    }else{
      // Se não chegamos ao final do caractere.
      ChartoBin( 0, tamanho-1, arquivo_temporario );
      fputs( "1", arquivo_temporario );
      return ;
    }
  }else{
    // Se ainda falta um pedaço do caractere.
    char char_output;
    // Pego o último bit.
    if (( c % 2 ) == 0 ){
      char_output = '0';
      c = c/2;
    }else{
      char_output = '1';
      c = c/2;
    }
    // Se eu não tiver chegado ao fim do caractere mesmo,
    // eu imprimo o último bit que retirei.
    if( tamanho > 0 ){
      ChartoBin( c, tamanho-1, arquivo_temporario );
      fputc( char_output, arquivo_temporario );
    }else
      fputc( char_output, arquivo_temporario );
  }
  return ;
}
