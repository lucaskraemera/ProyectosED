#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "iterador.h"

class doublyLinkedList{
	private:
		intNode *head; // puntero cabeza de la lista, indica el comienzo de esta
		intNode *tail; // puntero cola de la lista, indica el final de esta
		intNode* crearNodo(intNode* next, intNode* prev,int symbolo); // crea un nodo
		int size(); // indica el tamaño de la lista
		bool empty(); // indica si la lista se encuentra vacia o no
	public:
		doublyLinkedList();
		~doublyLinkedList();
		void insertFirst(int symbolo); // crear un nodo con el symbolo/entero y insertarlo al inicio de la lista
		void insertLast(int symbolo); // crear un nodo con el symbolo/entero y insertarlo al final de la lista
		void insertAfterNode(int symbolo, intNode* nodo); // crear un nodo con el symbolo/entero y insertarlo antes del nodo indicado
		void insertBeforeNode(int symbolo, intNode* nodo); // crear un nodo con el symbolo/entero y insertarlo despues del nodo indicado
		void remove(intNode* nodo); // elimina el nodo indicado
		int getElement(intNode* nodo); // obtiene el symbolo/entero del nodo indicado
		intNode* getHead(); // obtiene el nodo cabeza de la lista
		intNode* getTail(); // obtiene el nodo cola de la lista
		iterador begin(); // iterador de la lista
};

#endif
