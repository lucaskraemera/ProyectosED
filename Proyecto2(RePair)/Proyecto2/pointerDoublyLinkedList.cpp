#include "pointerDoublyLinkedList.h"
#include <iostream>

using namespace std;

pointerDoublyLinkedList::pointerDoublyLinkedList(){
	this->head = crearNodo(nullptr,nullptr,0);
	this->tail = crearNodo(nullptr,head,0);
	head->next = tail;	
}

pointerDoublyLinkedList::~pointerDoublyLinkedList(){
	pointerIntNode* toRemove = head->next;
	while(toRemove!=tail){
		pointerIntNode* auxRemove = toRemove;
		toRemove = toRemove->next;
		delete auxRemove;
	}
	delete this->head;
	delete this->tail;
}

pointerIntNode* pointerDoublyLinkedList::crearNodo(pointerIntNode* next,pointerIntNode* prev,int symbolo){
	pointerIntNode* aux= new pointerIntNode();
	aux->numero = symbolo;
	aux->next = next;
	aux->prev = prev;
	aux->anteriorIgual = nullptr;
	aux->siguienteIgual = nullptr;
	return aux;
}

void pointerDoublyLinkedList::insertFirst(int symbolo){
	pointerIntNode* aux = crearNodo(head->next,head,symbolo); // creas el nodo
	head->next = aux; // asignas al puntero de la cabeza next como aux
	aux->next->prev = aux;  // asignas al puntero prev de la ex primera posicion como el nodo creado 
}

void pointerDoublyLinkedList::insertLast(int symbolo){
	pointerIntNode* aux = crearNodo(tail,tail->prev,symbolo);
	tail->prev->next = aux;
	tail->prev = aux;
}

void pointerDoublyLinkedList::insertAfterNode(int symbolo, pointerIntNode* nodo){
	pointerIntNode* aux= new pointerIntNode();
	aux->numero = symbolo;
	aux->next = nodo->next;
	aux->prev = nodo;
	aux->anteriorIgual = nullptr;
	aux->siguienteIgual = nullptr;
	nodo->next->prev= aux;
	nodo->next = aux;
}

void pointerDoublyLinkedList::insertBeforeNode(int symbolo, pointerIntNode* nodo){
	pointerIntNode* aux= new pointerIntNode();
	aux->numero = symbolo;
	aux->next = nodo;
	aux->prev = nodo->prev;
	aux->anteriorIgual = nullptr;
	aux->siguienteIgual = nullptr;
	nodo->prev->next= aux;
	nodo->prev = aux;
}

void pointerDoublyLinkedList::remove(pointerIntNode* nodo){ 
	nodo->next->prev = nodo->prev;
	nodo->prev->next = nodo->next;
	delete nodo;
}

int pointerDoublyLinkedList::getElement(pointerIntNode* nodo){
	return nodo->numero;
}

int pointerDoublyLinkedList::size(){
	int i = 0;
	pointerIntNode* actual = head->next;
	for(actual;actual!=tail;actual = actual->next) i++;
	return i;
}

bool pointerDoublyLinkedList::empty(){
	if(head->next == tail) return true;
	else return false;
}

pointerIntNode* pointerDoublyLinkedList::getHead(){
	return head;
}

pointerIntNode* pointerDoublyLinkedList::getTail(){
	return tail;
}

pointerIterador pointerDoublyLinkedList::begin(){
	pointerIterador* it = new pointerIterador(head,tail);
	return *it;
}
