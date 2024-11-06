# EEL7323-SE-PROVA1

Este repositório contém a implementação de uma máquina de refrigerantes que pode ser executada tanto em um ambiente desktop quanto em um sistema microprocessado embarcado.

## Diagrama do projeto

![Diagrama de Classe](images/diagrama_de_classes.png)

O projeto é estruturado em duas classes principais: **machinePC**, que será executada em um desktop, e **machineSE**, projetada para um sistema embarcado. Ambas as classes herdam classes abstratas responsáveis pela entrada e saída de dados, bem como pela exibição da data e hora. Cada uma delas implementa o método `run`, que contém um loop infinito `while(1)`, responsável por iniciar o funcionamento da máquina de refrigerantes.

Tanto a classe **machinePC** quanto a **machineSE** utilizam os objetos **Log** e **FSM**, sendo o primeiro responsável pelo sistema de log da máquina e o segundo pela implementação da máquina de estados. Vale ressaltar que a funcionalidade de log depende de duas classes auxiliares: **Nodo** e **Queue**, que gerenciam a estrutura de dados utilizada para armazenar os registros de log.

Além disso, o projeto faz uso de dois arquivos utilitários que são empregados em várias partes do código. O primeiro é o **utils.h**, que contém funções de controle de tempo, como o delay. O segundo é o **data_types.h**, que define as estruturas e tipos de dados utilizados na implementação da máquina de refrigerantes.

### Diagrama FSM:

| Current state | Noting | C025 | C050 | C100 | DEV | MEET | ETIRPS |
|----------|----------|----------|----------|----------|----------|----------|----------|
| s000  | s000   | s025  | s050  | s100   | s000, dev = 0  | s000, meet = false   | s000, etirps = false   |
| s025  | s025   | s050   | s075   | s125   | s000, dev = 25   | s025, meet = false   | s025, etirps = false  |
| s050  | s050  | s075   | s100   | s150   | s000, dev = 50   | s050, meet = false   | s050, etirps = false   |
| s075  | s075   | s100   | s125  | s150, dev = 25   | s000, dev = 75   | s075, meet = false    | s075, etirps = false   |
| s100 | s100  | s125   | s150   | s150, dev = 50  |s000, dev = 100   | s100, meet = false    | s100, etirps = false  |
| s125  | s125   | s150   | s150 dev = 25   | s150, dev = 75   | s000, dev = 125  | s125, meet = false   | s125, etirps = false  |
| s150  | s150   | s150, dev = 25   | s150 dev = 50   | s150, dev = 100   | s000, dev = 150   | s000, meet = true    | s000, etirps = true  |


## Funcionalidades

A máquina de refrigerantes simula o funcionamento básico de uma vending machine que aceita moedas de diferentes valores e realiza a entrega de produtos. A implementação inclui:

- **Operação em Desktop**: Controle por teclado e exibição de saídas no console.
- **Operação em Sistema Embarcado**: Utilização de botões e switches como entrada e LEDs como saída.

## Interação de Entrada/Saída no PC

Para a implementação deste projeto, foi necessário utilizar comandos de teclado no terminal como entrada. Os seguintes comandos podem ser utilizados para interagir com a máquina de refrigerantes:

- **Valores numéricos**: 
  - 25
  - 50
  - 100
  
  Esses valores representam as quantias de moedas inseridas na máquina.

- **Comandos de texto**: 
  - `meet`
  - `etirps`
  - `dev`
  - `log`
  
Cada um desses comandos é utilizado para executar uma ação específica na máquina, como selecionar opções ou visualizar o log de operações.

Esses comandos devem ser inseridos diretamente no terminal para simular a interação com a máquina de refrigerantes.


## Estrutura do Projeto

- **src/**: Contém os arquivos `.cpp` com a implementação das classes e funções principais.
- **include/**: Contém os arquivos de cabeçalho `.h`.
- **main.cpp**: Arquivo principal que executa o programa.
  
## Compilação e Execução no Desktop

Para compilar o código no ambiente desktop, siga os comandos abaixo:

### Linux

No Linux, execute os seguintes comandos no terminal:

```bash
g++ -Iinclude -o programa main.cpp src/*.cpp

