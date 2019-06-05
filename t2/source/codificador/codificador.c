#include <hamming.h>
#define ARQ_TXT argv[1]

int main( int argc, char* argv[] ){
    char *arq_bin_txt;

    if ( argc == 2 ){
        arq_bin_txt = codificar_texto( ARQ_TXT );
        printf( "Texto codificado para %s...\n", arq_bin_txt );
    }
    
    return 0 ;
}