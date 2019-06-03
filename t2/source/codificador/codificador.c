#include <hamming.h>
#define ARQ_TXT argv[1]

int main( int argc, char* argv[] ){
    char *arq_bin;

    if ( argc == 2 ){
        arq_bin = codificar_texto( ARQ_TXT );
        printf( "Texto codificado para %s...\n", arq_bin );
    }
    
    return 0 ;
}