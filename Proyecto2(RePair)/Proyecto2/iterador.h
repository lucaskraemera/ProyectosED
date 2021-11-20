#ifndef ITERADOR_H
#define ITERADOR_H

struct intNode{
	int numero;
	intNode* prev;
	intNode* next;
};

class iterador{
	private:
		intNode* actual; // puntero al nodo en el cual se encuentra el iterador
		intNode* end; // puntero que indica el fin del iterador
	public:	
		iterador(intNode* begin, intNode* fin);
		~iterador();
		bool hasNext(); // verifica si existe un siguiente elemento en la lista
		int next(); // entrega el symbolo/entero del nodo indicado por el iterador
		intNode* getNode(); // entrega el nodo del elemento del iterador
};

#endif
