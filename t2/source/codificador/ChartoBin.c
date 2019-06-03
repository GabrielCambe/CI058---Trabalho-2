#include <hamming.h>

#include <stdio.h>

void ChartoBin( unsigned char c, int size, FILE* out ){
  if ( c == 1 ){ //base
    if ( size == 0 ){
      fputs( "1", out );
      return ;
    }else{
      ChartoBin( 0, size-1, out );
      fputs( "1", out );
      return ;
    }
  }else{
    char char_out;
    if (( c % 2 ) == 0 ){
      char_out = '0';
      c = c/2;
    }else{
      char_out = '1';
      c = c/2;
    }
    if( size > 0 ){
      ChartoBin( c, size-1, out );
      fputc( char_out, out );
    }else
      fputc( char_out, out );
  }
  return ;
}
