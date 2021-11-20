#ifndef POINTERITERADOR_H
#define POINTERITERADOR_H

struct pointerIntNode{
	int numero;
	pointerIntNode* prev; // puntero al nodo anterior en la lista
	pointerIntNode* next; // puntero al nodo siguiente en la lista
	pointerIntNode* anteriorIgual; // puntero al nodo del par anterior igual en la lista
	pointerIntNode* siguienteIgual; // puntero al nodo del par siguiente igual en la lista
};

class pointerIterador{
	private:
		pointerIntNode* actual; // nodo sobre el cual se encuentra el iterador
		pointerIntNode* end; // nodo sobre el cual el iterador se tiene que detener
	public:	
		pointerIterador(pointerIntNode* begin, pointerIntNode* fin); // inicializa los nodos del iterador
		~pointerIterador();
		bool hasNext(); // indica si existe siguiente elemento en el iterador
		int next(); // entrega el siguiente symbolo/entero de la lista
		pointerIntNode* getNode(); // entrega el nodo del symbolo/entero entregado en la ultima ocasion
};

#endif
