#include <hamming.h>

char* codificar_texto( char *arq_texto ){
    char *arq_bin_txt,//
    *arq_tmp;//arquivo de caracteres '0' e '1' espaçados de 8 em 8

    arq_tmp = ASCIItoBin( arq_texto );

    arq_bin_txt = EncodeBin( arq_tmp );

    return arq_bin_txt;
}