SRC = ./source/
SRC_Cod = $(SRC)codificador/
SRC_Decod = $(SRC)decodificador/
INC = ./include/
FLGS = -Wall -g -I$(INC)
codificador_OBJS = ChartoBin.o ASCIItoBin.o EncodeBin.o codificar_texto.o
decodificador_OBJS = BintoASCII.o corr_DecodBloco.o lerBloco.o detectarErros.o decodificar_texto.o

all: codificador decodificador

#-------------------------------------------------------
# CODIFICADOR
codificador: codificar_texto
	gcc $(codificador_OBJS) $(SRC_Cod)codificador.c -o codificador $(FLGS)

codificar_texto: ASCIItoBin EncodeBin
	gcc -c $(SRC_Cod)codificar_texto.c $(FLGS)

EncodeBin:
	gcc -c $(SRC_Cod)EncodeBin.c $(FLGS)

ASCIItoBin: ChartoBin
	gcc -c $(SRC_Cod)ASCIItoBin.c $(FLGS)

ChartoBin:
	gcc -c $(SRC_Cod)ChartoBin.c $(FLGS)

clean_Cod: clean_CodOutput
	rm codificador ||true

clean_CodOutput:
	rm arq.bin arq.tmp ||true


#-------------------------------------------------------
# DECODIFICADOR
decodificador: lerBloco detectarErros corr_DecodBloco decodificar_texto
	gcc $(decodificador_OBJS) $(SRC_Decod)decodificador.c -o decodificador $(FLGS)

lerBloco:
	gcc -c $(SRC_Decod)lerBloco.c $(FLGS)

detectarErros:
	gcc -c $(SRC_Decod)detectarErros.c $(FLGS)

corr_DecodBloco:
	gcc -c $(SRC_Decod)corr_DecodBloco.c $(FLGS)

decodificar_texto: corr_DecodBloco BintoASCII
	gcc -c $(SRC_Decod)decodificar_texto.c $(FLGS)

BintoASCII:
	gcc -c $(SRC_Decod)BintoASCII.c $(FLGS)

clean_Decod: clean_DecodOutput
	rm decodificador ||true

clean_DecodOutput:
	rm corrigido.bin arq_bin.txt corrigido.txt ||true


#-------------------------------------------------------
# 
dist_clean: clean_Cod clean_Decod clean

clean:
	rm *.o ||true
	rm *~ ||true