# EEL7323-SE-PROVA1

Este repositório contém a implementação de uma máquina de refrigerantes que pode ser executada tanto em um ambiente desktop quanto em um sistema microprocessado embarcado.

## Funcionalidades

A máquina de refrigerantes simula o funcionamento básico de uma vending machine que aceita moedas de diferentes valores e realiza a entrega de produtos. A implementação inclui:

- **Operação em Desktop**: Controle por teclado e exibição de saídas no console.
- **Operação em Sistema Embarcado**: Utilização de botões e switches como entrada e LEDs como saída.

## Estrutura do Projeto

- **src/**: Contém os arquivos `.cpp` com a implementação das classes e funções principais.
- **include/**: Contém os arquivos de cabeçalho `.h`.
- **main.cpp**: Arquivo principal que executa o programa.
  
## Compilação e Execução no Desktop

Para compilar o código no ambiente desktop, siga os comandos abaixo:

```bash
g++ -Iinclude -o my_program main.cpp src/*.cpp
