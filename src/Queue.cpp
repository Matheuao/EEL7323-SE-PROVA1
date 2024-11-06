#include "Queue.h"


Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}


Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Função para adicionar um elemento à fila
void Queue::enqueue(log_data dat) {
    Node* newNode = new Node(dat, nullptr);  
    if (isEmpty()) {
        
        head = newNode;
        tail = newNode;
    } else {
      
        tail->setNext(newNode);
        tail = newNode;
    }
}

// Função para remover e retornar o primeiro elemento da fila
log_data Queue::dequeue() {
    if (isEmpty()) {
        cout << "A fila está vazia, não é possível remover elementos!" << endl;
        // Retorna um valor padrão
        return log_data{};
    }

    Node* temp = head;  
    log_data data = temp->getVal();  
    head = head->getNext();  

    
    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;  
    return data;  
}

// Função para verificar se a fila está vazia
bool Queue::isEmpty() {
    return head == nullptr;
}

// Função para exibir todos os elementos da fila
void Queue::display() {
    int i =0;
    if (isEmpty()) {
        cout << "A fila está vazia." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        i++;
        log_data data = current->getVal();
       
        cout << "Sale: " << i << " " << "Dev: " << data.dev << " " 
            << "MEET: " << data.MEET << " " 
            << "ETIRPS: " << data.ETIRPS << " " 
            << " | Data: " << data.dia << "/" 
            << data.mes << "/" << data.ano << " " 
            << data.h << ":" << data.m << ":" << data.s << endl;

        current = current->getNext();
    }
}
