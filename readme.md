# Criptografia - Decodificação / EDB1

## O que é?

Esse projeto é referente ao projeto de segunda unidade de Estrutura de dados I da UFRN.

O professor Einstein sugeriu um projeto que envolve criptografia, onde poderemos utilizar alguns tipos de dados como Pilhas, Deques e Tabelas Hash.

A ideia é criptografar e decodificar palavras com até 1M de caracteres e utilizar as estruturas de dados citadas anteriormente para isso.

## Função hash

Os possíveis caracteres (K) serão esses:

K = "abcdefghijklmnopqrstuvwxyz0123456789, .?:"

Logo, o max de caracteres aceitos é de 41.

Já o tamanho max de uma mensagem é de 1M de caracteres, logo, a quantidade max de repetições de um caractere assumindo que todo o texto tenha o mesmo é de 1M.

### Isso nos deixa com a seguinte função hash:

Cada caractere dentro da string de possíveis caracteres detém um índice que representa sua posição nessa string. Esse índice será também o nosso índice do array da tabela hash. Já o valor, será um objeto contendo a quantidade de repetições daquele caractere juntamente do próprio caractere.

### Descrição:

Array hash = h

Caractere = c

Array de possíveis caracteres = K

### h[c] = K[c]

### Exemplo:

O caractere "c" em nosso array de possíveis caracteres (K) tem o índice 2. Esse também será nosso índice no array da tabela hash.

## Como rodar?

### GCC

Você precisa ter o compilador GCC para C instalado na sua máquina.

### MAKEFILE

Utilizando o makefile você pode compilar a aplicação usando apenas o comando: "make criptografia".

Podemos utilizar o "make clean" para limpar as compilações.

### RODANDO A APP

Depois de instalar o GCC, compilar com o make, agora você pode abrir o arquivo executável gerado pelo comando make. Nesse caso o nome do arquivo é "criptografia". Basta rodar o comando "./criptografia" em OSs como MacOS e Linux.