#include <hamming.h>
#define ARQ_BIN argv[1]

int main( int argc, char* argv[] ){
    if ( argc == 2 ){
        char *corrigido_txt, *corrigido_tmp;

        corrigido_tmp = decodificar_texto( ARQ_BIN );

        corrigido_txt = BintoASCII( corrigido_tmp );
        printf( "Texto decodificado para %s...\n", corrigido_txt );
    
    }
    return 0 ;
}