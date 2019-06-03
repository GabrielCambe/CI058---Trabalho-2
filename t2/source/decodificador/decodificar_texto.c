#include <hamming.h>
#include <stdlib.h>

char* decodificar_texto( char *arq_bin ){
    char *blocoDe15_bin, *corrigido_bin; int posicao;
    FILE* texto_codificado, *texto_corrigido;
    
    if (( texto_codificado = fopen( arq_bin, "r" ) ) == NULL ) abort();
    printf( "lendo %s...\n", arq_bin );

    corrigido_bin = "corrigido.bin";
    if (( texto_corrigido = fopen( corrigido_bin, "w" ) ) == NULL ) abort();
    printf( "lendo %s...\n", corrigido_bin );

    blocoDe15_bin = malloc( 15 * sizeof( char ) );
    if ( blocoDe15_bin == NULL ) abort();

    do{
        blocoDe15_bin = lerBloco( texto_codificado, blocoDe15_bin );

        if ( blocoDe15_bin != NULL ){
            posicao = detectarErros( blocoDe15_bin );
            corr_DecodBloco( blocoDe15_bin, posicao, texto_corrigido );
        }//else{ }

    }while( !feof( texto_codificado ) );

    if ( blocoDe15_bin != NULL )
        free( blocoDe15_bin );

    if ( texto_corrigido != NULL )
    fclose( texto_corrigido );

    if ( texto_codificado != NULL )
        fclose( texto_codificado );

    return corrigido_bin ;

}