#include <hamming.h>

char* lerBloco( FILE *texto_codificado, char *bloco ){
    int bitcount = 0, c = 0;

    c = fgetc( texto_codificado );    
    while( bitcount <= 14 ){
        if ( (char)c != ' ' ){
            if ( feof( texto_codificado ) ){
                if ( bitcount <= 14 ){
                   printf( "Existem blocos < 15 bits...\n" );
                    while ( bitcount <= 14 ){
                        bloco[bitcount] = (char)'0';
                        bitcount++;
                    }
                }
                break ;
            }
            bloco[bitcount++] = (char)c;
            c = fgetc( texto_codificado );
        }
    }

    return bloco ;
}