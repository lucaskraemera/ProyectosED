#include "doublyLinkedList.h"
#include <iostream>

using namespace std;

doublyLinkedList::doublyLinkedList(){
	this->head = crearNodo(nullptr,nullptr,0);
	this->tail = crearNodo(nullptr,head,0);
	head->next = tail;	
}

doublyLinkedList::~doublyLinkedList(){
	intNode* toRemove = head->next;
	while(toRemove!=tail){
		intNode* auxRemove = toRemove;
		toRemove = toRemove->next;
		delete auxRemove;
	}
	delete this->head;
	delete this->tail;
}

intNode* doublyLinkedList::crearNodo(intNode* next,intNode* prev,int symbolo){
	intNode* aux= new intNode();
	aux->numero = symbolo;
	aux->next=next;
	aux->prev=prev;
}

void doublyLinkedList::insertFirst(int symbolo){
	intNode* aux = crearNodo(head->next,head,symbolo); // creas el nodo
	head->next = aux; // asignas al puntero de la cabeza next como aux
	aux->next->prev = aux;  // asignas al puntero prev de la ex primera posicion como el nodo creado 
}

void doublyLinkedList::insertLast(int symbolo){
	//cerr << "sym: "<<symbolo << endl;
	intNode* aux = crearNodo(tail,tail->prev,symbolo);
	tail->prev = aux;
	aux->prev->next = aux; 
}

void doublyLinkedList::insertAfterNode(int symbolo, intNode* nodo){
	intNode* aux = crearNodo(nodo->next,nodo,symbolo);
	nodo->next = aux;
	aux->next->prev= aux;
}

void doublyLinkedList::insertBeforeNode(int symbolo, intNode* nodo){
	intNode* aux = crearNodo(nodo,nodo->prev,symbolo);
	nodo->prev = aux;
	aux->prev->next= aux;
}

void doublyLinkedList::remove(intNode* nodo){ 
	//if(nodo== head || nodo == tail) return; // asegurarse de no poder eliminar punteros esenciales
	nodo->next->prev = nodo->prev;
	nodo->prev->next = nodo->next;
	delete nodo;
}

int doublyLinkedList::getElement(intNode* nodo){
	return nodo->numero;
}

int doublyLinkedList::size(){
	int i = 0;
	intNode* actual = head->next;
	for(actual;actual!=tail;actual = actual->next) i++;
	return i;
}

bool doublyLinkedList::empty(){
	if(head->next == tail) return true;
	else return false;
}

intNode* doublyLinkedList::getHead(){
	return head;
}

intNode* doublyLinkedList::getTail(){
	return tail;
}

iterador doublyLinkedList::begin(){
	iterador* it = new iterador(head,tail);
	return *it;
}
