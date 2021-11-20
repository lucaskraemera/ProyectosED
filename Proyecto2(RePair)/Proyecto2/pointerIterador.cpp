#include "pointerIterador.h"

pointerIterador::pointerIterador(pointerIntNode* begin, pointerIntNode* fin){
	this->actual = begin->next;
	this->end = fin;
}

pointerIterador::~pointerIterador(){
	
}

bool pointerIterador::hasNext(){
	if (actual == end) return false;
	return true;
}

int pointerIterador::next(){
	int elemento = actual->numero;
	actual = actual->next;
	return elemento;
}

pointerIntNode* pointerIterador::getNode(){
	return actual;
}
