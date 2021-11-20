#include "iterador.h"

iterador::iterador(intNode* begin, intNode* fin){
	this->actual = begin->next;
	this->end = fin;
}

iterador::~iterador(){
}

bool iterador::hasNext(){
	if (actual == end) return false;
	return true;
}

int iterador::next(){
	int elemento = actual->numero;
	actual = actual->next;
	return elemento;
}

intNode* iterador::getNode(){
	return actual;
}
