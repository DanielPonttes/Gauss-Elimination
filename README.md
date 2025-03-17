# Gauss-Elimination

Este repositório contém implementações do algoritmo de Eliminação de Gauss em três linguagens de programação: C, Go e Rust. O objetivo é comparar o desempenho e as características dessas linguagens ao resolver sistemas lineares usando o método de eliminação gaussiana.

## Como Utilizar

### **Implementação em C**
**Requisitos**:

* Compilador GCC instalado.
* Biblioteca padrão do C.

**Passos**:
1. Navegue até a pasta `c`:

`cd c`

2. Compile o código:

`gcc -o gauss gauss.c -lm`

3. Execute o programa:

`./gauss`

**Saída Esperada**
O programa exibirá o tempo de execução para matrizes de tamanhos 50x50, 500x500 e 1000x1000.


### **Implementação em Go**
**Requisitos**:

* Go instalado (versão 1.16 ou superior).


**Passos**:
1. Navegue até a pasta `go`:

`cd go`

2. Execute o código:

`go run gauss.go`

**Saída Esperada**
O programa exibirá o tempo de execução para matrizes de tamanhos 50x50, 500x500 e 1000x1000.


### **Implementação em Rust**
**Requisitos**:

* Rust instalado `(usando rustup)`.


**Passos**:
1. Navegue até a pasta `rust`:

`cd rust`

2. Execute o programa:

`cargo run`

**Saída Esperada**
O programa exibirá o tempo de execução para matrizes de tamanhos 50x50, 500x500 e 1000x1000.

## Integrantes 

Daniel Henrique da Silva Pontes Barretos

Karen Satie Ono 

## Comparação de Linguagens 

Veja o PDF para comparações de desempenho.


## Conclusão
**C**: Melhor desempenho bruto, mas requer gerenciamento manual de memória.

**Go**: Código simples e legível, com desempenho aceitável.

**Rust**: Equilíbrio entre desempenho e segurança de memória.

Escolha a linguagem com base nas necessidades do seu projeto: desempenho máximo (C), simplicidade (Go) ou segurança e desempenho (Rust).






