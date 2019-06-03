#include <hamming.h>

void corr_DecodBloco( char *blocoDe15_bin, int posicao, FILE* texto_corrigido){
    if ( posicao >= 0 ){
        switch ( blocoDe15_bin[posicao] ){
        case '0':
            blocoDe15_bin[posicao] = '1';
            break;
        case '1':
            blocoDe15_bin[posicao] = '0';
            break;
        }
    }
    fputc( (int)blocoDe15_bin[2], texto_corrigido );
    fputc( (int)blocoDe15_bin[4], texto_corrigido );
    fputc( (int)blocoDe15_bin[5], texto_corrigido );
    fputc( (int)blocoDe15_bin[6], texto_corrigido );
    fputc( (int)blocoDe15_bin[8], texto_corrigido );
    fputc( (int)blocoDe15_bin[9], texto_corrigido );
    fputc( (int)blocoDe15_bin[10], texto_corrigido );
    fputc( (int)blocoDe15_bin[11], texto_corrigido );
    fputc( (int)blocoDe15_bin[12], texto_corrigido );
    fputc( (int)blocoDe15_bin[13], texto_corrigido );
    fputc( (int)blocoDe15_bin[14], texto_corrigido );
    
    fputc( (int)' ', texto_corrigido );
}