#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"
using namespace std;

class Queue {
    Node* head;  // Ponteiro para o primeiro elemento da fila
    Node* tail;  // Ponteiro para o último elemento da fila

public:
    // Construtor
    Queue();

    // Destrutor
    ~Queue();

    // Adiciona um elemento à fila
    void enqueue(log_data dat);

    // Remove e retorna o primeiro elemento da fila
    log_data dequeue();

    // Verifica se a fila está vazia
    bool isEmpty();

    // Mostra todos os elementos da fila
    void display();
};

#endif
