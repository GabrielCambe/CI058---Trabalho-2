#include <hamming.h>

#include <string.h>
#include <stdlib.h>

char* ASCIItoBin( char* arq_txt ){
    FILE* arquivo_texto;
    FILE* arquivo_temporario;
    
    if (( arquivo_texto = fopen( arq_txt, "r" ) ) == NULL ) abort();
    printf( "lendo %s...\n", arq_txt );


    char *arq_tmp = "arq.tmp";
    if (( arquivo_temporario = fopen( arq_tmp, "w" ) ) == NULL ) abort();
    printf( "criando %s...\n", arq_tmp );    


    char c;

    // Leio o arquivo de texto inteiro e para cada
    // caractere eu converto o caractere com a função ChartoBin.
    while ( 1 ){
        c = fgetc( arquivo_texto );
        if ( feof( arquivo_texto ) ) break ;
        ChartoBin( c, 7, arquivo_temporario );
        fputs( " ", arquivo_temporario );
    }

    if ( c != EOF )
        ChartoBin( c, 7, arquivo_temporario );

    fclose( arquivo_temporario );
    fclose( arquivo_texto );

    return arq_tmp ;
}