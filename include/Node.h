/*
   File Node.h

   Class Node

   Class Node stores integer values for a linked list.
   
   This file has the Node's interface (header file).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Data_types.h"
using namespace std;


class Node {

    log_data val;
    Node* next;

  public:
         
    Node(log_data dat, Node* nxt);
    log_data getVal();
    Node* getNext();
    void setVal(log_data dat);
    void setNext(Node* nxt);
};

#endif