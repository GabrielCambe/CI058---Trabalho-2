# CI058 - Trabalho2 - Codificador e Decodificador de Hamming (15, 11)
Codificador-Decodificador de Hamming( 15, 11 ).

O trabalho é composto de dois componentes principais. Um codificador e um Decodificador.
São dois programas em C que recebem um argumento com o caminho de um arquivo.

## Codificador
Esse programa recebe um arquivo de texto como argumento e cria dois arquivos, _"arq.tmp"_ e _"arq_bin.txt"_. O primeiro é um arquivo intermediário, um arquivo txt com '0's e '1's espaçados de 8 em 8. É a representação em bits da codificação em ASCII do arquivo de texto passado. Essa representação é criada pela função __ASCIItoBin__. Já _"arq_bin.txt"_ é criado pela função __codificar_texto__ e é um arquivo de texto com '0's e '1's, espaçados de 15 em 15, a codificação em hamming(15, 11) do arquivo _"arq.tmp"_.

## Decodificador
Esse programa recebe o arquivo de saída do codificador e cria dois arquivos, _"corrigido.tmp"_ e _"corrigido.txt"_. O primeiro é criado pela função __decodificar_texto__ que recebe um arquivo de texto com '0's e '1's, espaçados de 15 em 15 e cria esse arquivo de texto com '0's e '1's espaçados de 11 em 11, que é a decodiificação de hamming(15, 11) do arquivo de entrada. Como _"corrigido.tmp"_ está codifcado em ASCII mas separado em bits, o decodificador usa __BintoASCII__ para fazer a conversão, criando assim o arquivo _"corrigido.txt"_ que representa o arquivo original passado para o codificador.

# Observações
Já que estamos usando 4 bits de paridade, o código só consegue resolver 1 erro por bloco. Esse teste pode ser feito modificando _"arq_bin.txt"_ e introduzindo erros nos blocos.

# Testes
Os scripts _"teste_cod.sh"_ e _"teste_decod.sh"_ podem ser usados nos testes, _"teste_cod.sh"_ recebe como argumento o mesmo que o __codificador__, compila e executa o __codificador__ com esse argumento.
Já _"teste_decod.sh"_ pode ser executado com ou sem argumentos. Se for passado um argumento, ele compila o __codificador__ e o __decodificador__, chama o __codificador__ com o texto passado como argumento, chama o __codificador__ com _"arq_bin.txt"_ como argumento e depois faz um diff do arquivo passado e de _"corrigido.txt"_. Se _"teste_decod.sh"_ for chamado sem argumentos ele só executa o __decodificador__ com _"arq_bin.txt"_ como argumento.
