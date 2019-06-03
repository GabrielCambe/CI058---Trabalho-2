#include <hamming.h>
#include <stdlib.h>

char* BintoASCII( char *corrigido_tmp ){
    FILE* texto = NULL; FILE* output = NULL;
    int bitcount; letra input;
    bitcount = 0; input.caractere = 0;
    char c;
    if (( texto = fopen( corrigido_tmp, "r" )) == NULL ) abort();
    printf( "lendo %s...\n", corrigido_tmp );//

    char *corrigido_txt = "corrigido.txt";
    if (( output = fopen( corrigido_txt, "w" ) ) == NULL ) abort();
    printf( "criando %s...\n", corrigido_txt );//
    
    int bit;
    while ( 1 ){
        c = (char)getc( texto );
        if( feof(  texto ) ) break;
        
        if( c != ' ' ){
            if(c == '1')
                bit = 1;
            else
                bit = 0;              
            switch(bitcount % 8){
                case 0: input.bin.bit7 = bit; break;
                case 1: input.bin.bit6 = bit; break;
                case 2: input.bin.bit5 = bit; break;
                case 3: input.bin.bit4 = bit; break;
                case 4: input.bin.bit3 = bit; break;
                case 5: input.bin.bit2 = bit; break;
                case 6: input.bin.bit1 = bit; break;
                case 7: input.bin.bit0 = bit; break;  
            }
            ++bitcount;
            if(bitcount % 8 == 0)
                fputc( (int)input.caractere, output );
        }
    }

    //fputc( (int)'\n', output );/////////completar o bloco em lerBloco

    if ( output != NULL )
        fclose(output);  
    if ( texto != NULL )
        fclose(texto);

    return corrigido_txt ;
}