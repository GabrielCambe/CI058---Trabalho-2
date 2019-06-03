#include <hamming.h>

int detectarErros( char* blocoDe15_bin ){
    letra input;
    input.caractere = 0;

    if ( blocoDe15_bin[0] == '1' )
        input.caractere ^= 0x01;
    
    if ( blocoDe15_bin[1] == '1' )
        input.caractere ^= 0x02;
    
    if ( blocoDe15_bin[2] == '1' )
        input.caractere ^= 0x03;   

    if ( blocoDe15_bin[3] == '1' )
        input.caractere ^= 0x04;
    
    if ( blocoDe15_bin[4] == '1' )
        input.caractere ^= 0x05;
    
    if ( blocoDe15_bin[5] == '1' )
        input.caractere ^= 0x06;
    
    if ( blocoDe15_bin[6] == '1' )
        input.caractere ^= 0x07;
    
    if ( blocoDe15_bin[7] == '1' )
        input.caractere ^= 0x08;
    
    if ( blocoDe15_bin[8] == '1' )
        input.caractere ^= 0x09;
    
    if ( blocoDe15_bin[9] == '1' )
        input.caractere ^= 0x0a;
    
    if ( blocoDe15_bin[10] == '1' )
        input.caractere ^= 0x0b;
    
    if ( blocoDe15_bin[11] == '1' )
        input.caractere ^= 0x0c;
    
    if ( blocoDe15_bin[12] == '1' )
        input.caractere ^= 0x0d;
    
    if ( blocoDe15_bin[13] == '1' )
        input.caractere ^= 0x0e;
    
    if ( blocoDe15_bin[14] == '1' )
        input.caractere ^= 0x0f;

    if( input.caractere != 0 )
        return (int)(input.caractere - 1) ;
    
    return -1;
}