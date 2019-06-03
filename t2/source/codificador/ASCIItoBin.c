#include <hamming.h>

#include <string.h>
#include <stdlib.h>

char* ASCIItoBin( char* arq_txt ){
    FILE* texto;
    FILE* output;
    
    if (( texto = fopen(arq_txt, "r") ) == NULL ) abort();
    printf( "lendo %s...\n", arq_txt );


    char *arq_tmp = "arq.tmp";

    if (( output = fopen(arq_tmp, "w" ) ) == NULL ) abort();
    printf( "criando %s...\n", arq_tmp );    


    char c;

    while ( 1 ){
        c = fgetc( texto );
        if ( feof( texto ) ) break ;
        ChartoBin( c, 7, output );
        fputs( " ", output );
    }

    fclose( output );
    fclose( texto );

    return arq_tmp ;
}