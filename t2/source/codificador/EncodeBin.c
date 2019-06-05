#include <hamming.h>

#include <stdlib.h>

char* EncodeBin( char *arq_tmp ){
    FILE* texto = NULL; FILE* texto_codificado = NULL;
    char message[11]; char codeword[15];
    int bitcount = 0; letra input; char c;
    input.caractere = 0;
  
    if (( texto = fopen( arq_tmp, "r" ) ) == NULL ) abort();
    printf( "lendo %s...\n", arq_tmp );    

    char *arq_bin_txt = "arq_bin.txt";
    if (( texto_codificado = fopen( arq_bin_txt, "w" ) ) == NULL ) abort();
    printf( "criando %s...\n", arq_bin_txt );    

    // Leio o arquivo temporário até o fim.
    while ( 1 ){ 
        c = fgetc( texto );
        if ( feof( texto ) ) break ;
        
        if ( c != ' ' ){
            if ( bitcount == 10 ){ // Eu codifico blocos de 11bits.
                if ( c == '1' )
                    input.caractere ^= 0x0f;
                message[bitcount] = c;
                // Preenche o bloco de 15 bits.
                switch ( input.bin.bit0 ){
                  case 0: codeword[0] = '0'; break;
                  case 1: codeword[0] = '1'; break;
                }
                switch ( input.bin.bit1 ){
                  case 0: codeword[1] = '0'; break;
                  case 1: codeword[1] = '1'; break;
                } 
                codeword[2] = message[0];
                switch ( input.bin.bit2 ){
                  case 0: codeword[3] = '0'; break;
                  case 1: codeword[3] = '1'; break;
                }
                codeword[4] = message[1]; 
                codeword[5] = message[2];
                codeword[6] = message[3];
                switch ( input.bin.bit3 ){
                  case 0: codeword[7] = '0'; break;
                  case 1: codeword[7] = '1'; break;
                }
                codeword[8] = message[4];
                codeword[9] = message[5];
                codeword[10] = message[6];
                codeword[11] = message[7];
                codeword[12] = message[8];
                codeword[13] = message[9];
                codeword[14] = message[10];
                //------------------------------
                // Imprime o bloco de 15 bits.
                for ( bitcount = 0; bitcount < 15; bitcount++ )
                    fputc( (int)codeword[bitcount], texto_codificado );
                fputc( (int)' ', texto_codificado );
                bitcount = 0; input.caractere = 0;
                //------------------------------
            }else{
                // XOR das posições da mensagem.
                switch ( bitcount ){
                  case 0: if ( c == '1') input.caractere ^= 0x03; message[bitcount] = c; break;
                  case 1: if ( c == '1') input.caractere ^= 0x05; message[bitcount] = c; break;
                  case 2: if ( c == '1') input.caractere ^= 0x06; message[bitcount] = c; break;
                  case 3: if ( c == '1') input.caractere ^= 0x07; message[bitcount] = c; break;
                  case 4: if ( c == '1') input.caractere ^= 0x09; message[bitcount] = c; break;
                  case 5: if ( c == '1') input.caractere ^= 0x0a; message[bitcount] = c; break;
                  case 6: if ( c == '1') input.caractere ^= 0x0b; message[bitcount] = c; break;
                  case 7: if ( c == '1') input.caractere ^= 0x0c; message[bitcount] = c; break;
                  case 8: if ( c == '1') input.caractere ^= 0x0d; message[bitcount] = c; break;
                  case 9: if ( c == '1') input.caractere ^= 0x0e; message[bitcount] = c; break;
                }
                bitcount++;
                //------------------------------
            }
        }
    }

    /*
    if ( c != ' ' ){
        if ( bitcount <= 10 ){ // Eu codifico blocos de 11bits.
            if ( c == '1' )
                input.caractere ^= 0x0f;
            message[bitcount] = c;
            // Preenche o bloco de 15 bits.
            switch ( input.bin.bit0 ){
              case 0: codeword[0] = '0'; break;
              case 1: codeword[0] = '1'; break;
            }
            switch ( input.bin.bit1 ){
              case 0: codeword[1] = '0'; break;
              case 1: codeword[1] = '1'; break;
            } 
            codeword[2] = message[0];
            switch ( input.bin.bit2 ){
              case 0: codeword[3] = '0'; break;
              case 1: codeword[3] = '1'; break;
            }
            codeword[4] = message[1]; 
            codeword[5] = message[2];
            codeword[6] = message[3];
            switch ( input.bin.bit3 ){
              case 0: codeword[7] = '0'; break;
              case 1: codeword[7] = '1'; break;
            }

            codeword[8] = message[4];
            codeword[9] = message[5];
            codeword[10] = message[6];
            codeword[11] = message[7];
            codeword[12] = message[8];
            codeword[13] = message[9];
            codeword[14] = message[10];
            //------------------------------
            // Imprime o bloco de 15 bits.
            for ( bitcount = 0; bitcount < 15; bitcount++ )
                fputc( (int)codeword[bitcount], texto_codificado );
            fputc( (int)' ', texto_codificado );
            bitcount = 0; input.caractere = 0;
            //------------------------------
        }else{
            // XOR das posições da mensagem.
            switch ( bitcount ){
              case 0: if ( c == '1') input.caractere ^= 0x03; message[bitcount] = c; break;
              case 1: if ( c == '1') input.caractere ^= 0x05; message[bitcount] = c; break;
              case 2: if ( c == '1') input.caractere ^= 0x06; message[bitcount] = c; break;
              case 3: if ( c == '1') input.caractere ^= 0x07; message[bitcount] = c; break;
              case 4: if ( c == '1') input.caractere ^= 0x09; message[bitcount] = c; break;
              case 5: if ( c == '1') input.caractere ^= 0x0a; message[bitcount] = c; break;
              case 6: if ( c == '1') input.caractere ^= 0x0b; message[bitcount] = c; break;
              case 7: if ( c == '1') input.caractere ^= 0x0c; message[bitcount] = c; break;
              case 8: if ( c == '1') input.caractere ^= 0x0d; message[bitcount] = c; break;
              case 9: if ( c == '1') input.caractere ^= 0x0e; message[bitcount] = c; break;
            }
            bitcount++;
            //------------------------------
        }
    }
    */


    if ( texto_codificado != NULL )
        fclose( texto_codificado );  

    if ( texto != NULL )
        fclose( texto );  

  return arq_bin_txt ;
}