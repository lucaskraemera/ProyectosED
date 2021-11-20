#ifndef POINTERDOUBLYLINKEDLIST_H
#define POINTERDOUBLYLINKEDLIST_H

#include "pointerIterador.h"

class pointerDoublyLinkedList{
	private:
		pointerIntNode *head; // nodo auxiliar de comienzo de cadena
		pointerIntNode *tail; // nodo auxiliar de termino de cadena
		pointerIntNode* crearNodo(pointerIntNode* next, pointerIntNode* prev,int symbolo); // crea un nodo
		int size(); // entrega el tamaño de la cadena
		bool empty(); // indica si la cadena se encuentra vacia o no
	public:
		pointerDoublyLinkedList(); // constructor de la cadena, inicializa nodos clave head y tail
		~pointerDoublyLinkedList(); // borra los elementos de la cadena
		void insertFirst(int symbolo); // crea un nodo con el symbolo/entero entregado y lo inserta al comienzo de la cadena
		void insertLast(int symbolo);// crea un nodo con el symbolo/entero entregado y lo inserta al final de la cadena
		void insertAfterNode(int symbolo, pointerIntNode* nodo);// crea un nodo con el symbolo/entero entregado y lo inserta despues del nodo indicado
		void insertBeforeNode(int symbolo, pointerIntNode* nodo);// crea un nodo con el symbolo/entero entregado y lo inserta antes del nodo indicado
		void remove(pointerIntNode* nodo); // elimina el nodo indicado de la lista
		int getElement(pointerIntNode* nodo); // obtiene el symbolo/entero del nodo indicado
		pointerIntNode* getHead(); // obtiene el nodo cabeza de la lista
		pointerIntNode* getTail(); // obtiene el nodo cola de la lista
		pointerIterador begin(); // entrega un iterador de la lista
};

#endif
