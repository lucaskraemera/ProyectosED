#include "heapRepair.h"
#include <iostream>
#include <fstream>

using namespace std;

heapRepair::heapRepair(){
	this->list = new pointerDoublyLinkedList();
	//this.mapa;
	//this->heap;
	//this.sigma;
}

heapRepair::~heapRepair(){
	delete list;
}

void heapRepair::destructorHeapyMap(){
	delete heap;
	map<pair<int,int>, infoNodo*>::iterator it = mapa.begin();
	for(it;it!=mapa.end();it++){
		delete it->second;
	}
}

void heapRepair::setSequence(char* text, int range){
	delete this->list;
	this->list = new pointerDoublyLinkedList();
	this->sigma = range + 1;
	ifstream lectura;
	lectura.open(text);
	int symbolo;
	while(lectura >> symbolo){
		list->insertLast(symbolo);
	}
}

void heapRepair::aumentarFrecuencia(pair<int,int> actualPair, pointerIntNode* puntero){
	map<pair<int,int>,infoNodo*>::iterator iterar = mapa.find(actualPair);

	if(iterar!=mapa.end()){ // si find retorna un iterador en mapa.end() significa que no encontro la clave
		infoNodo* aux = iterar->second;
		if(aux->primerIgual!=nullptr || aux->ultimoIgual!=nullptr){
			puntero->siguienteIgual = nullptr;
			puntero->anteriorIgual = aux->ultimoIgual;
			if(aux->ultimoIgual!=nullptr) aux->ultimoIgual->siguienteIgual = puntero;
			aux->ultimoIgual = puntero;
		}else{	
			aux->primerIgual = puntero;
			aux->ultimoIgual = puntero;
			puntero->anteriorIgual=nullptr;
			puntero->siguienteIgual=nullptr;
		}
		heap->aumentarClave(aux->posHeap);
	}else{
		infoNodo* aInsertar = new infoNodo();
		aInsertar->primerIgual = puntero;
		aInsertar->ultimoIgual = puntero;
		puntero->anteriorIgual=nullptr;
		puntero->siguienteIgual=nullptr;
		aInsertar->posHeap = heap->size();
		heap->push(actualPair,aInsertar);
		mapa.insert(make_pair(actualPair,aInsertar));
	}
}

void heapRepair::firstRead(){
    //nos aseguramos de tener las variables "limpias" antes de comenzar el proceso
    this->heap = new priorityQueueHeap();
    pointerIterador it = list->begin();
    bool repetido = true;
    pair<int,int> actualPair;
    actualPair.first = 0;
    if(it.hasNext()) actualPair.second = it.next();
    while(it.hasNext()){
    	int siguientee = it.next();
    	if(actualPair.first == actualPair.second && actualPair.second == siguientee && repetido){
			repetido = false;
    		continue;
		}
        actualPair.first = actualPair.second;
        actualPair.second = siguientee;
        aumentarFrecuencia(actualPair,it.getNode()->prev);
        repetido = true;
    }
    //print();
    //heap->print();
}

bool heapRepair::verSiEsPar(pointerIntNode* actual){
	if(actual->numero == actual->prev->numero){
		if(actual->prev->prev->numero == actual->numero){
			if(actual->prev->anteriorIgual == nullptr){
				if(actual->prev->prev->prev->numero == actual->numero){
					return true;
				}else
					return false;
			}else 
				return false;
		}else
			return true;
	}else
		return true;
}

bool heapRepair::verSiEsPar2(pointerIntNode* actual){
	if(actual->numero == actual->prev->numero){
        if(actual->anteriorIgual == nullptr){
            if(actual->prev->prev->numero == actual->numero){
                return false;
            }
            else return true;
        }
        else return true;
    }
    else return true;
}

void heapRepair::actualizarPunteros(pointerIntNode* actual){
	pair<int,int> parActual = make_pair(actual->prev->numero,actual->numero);
	//cerr << "actualizar Punteros" << parActual.first << " " << parActual.second << endl;

	if(verSiEsPar2(actual)){
		heap->disminuirClave(mapa[parActual]->posHeap);
		//cerr << "aAI " << actual->anteriorIgual << " aSI " << actual->siguienteIgual << endl;
		if(actual->siguienteIgual==nullptr){
			mapa[parActual]->ultimoIgual = actual->anteriorIgual;
			//if(actual->anteriorIgual != nullptr) actual->anteriorIgual->siguienteIgual = nullptr;
		}
		else{
			actual->siguienteIgual->anteriorIgual = actual->anteriorIgual;
		}
		if(actual->anteriorIgual==nullptr){
			mapa[parActual]->primerIgual = actual->siguienteIgual;
			if(actual->siguienteIgual != nullptr) actual->siguienteIgual->anteriorIgual = nullptr;
		}
		else{
			actual->anteriorIgual->siguienteIgual = actual->siguienteIgual;
		}
	}
	return;
}

void heapRepair::replaceSequence(){
	//cerr << "replace" << endl;
	pointerIntNode* actual = heap->top().punteroMapa->primerIgual;
	pair<int,int> parActual = heap->top().par;
	//cerr << "PAR ACTUAL: " << parActual.first << " " << parActual.second << " CON FRECUENCIA: " << heap->top().frecuencia << endl;
	heap->pop();
	bool esCabeza = false;
	bool esCola = false;

	while(actual!=nullptr){
		//cerr <<actual->prev->prev->numero<<" "<<actual->prev->numero<<" "<<actual->numero <<endl;
		pointerIntNode* nextReplace = actual->siguienteIgual;
		
		if(make_pair(actual->prev->numero,actual->numero) != parActual){
			actual = nextReplace;
			continue;
		}
		if(actual->prev->prev == list->getHead()) esCabeza = true;
		if(actual->next == list->getTail()) esCola = true;
		if(!esCabeza) actualizarPunteros(actual->prev);
		if(!esCola) actualizarPunteros(actual->next);
		esCabeza = false;
		list->insertAfterNode(sigma,actual);
		actual = actual->next;
		list->remove(actual->prev->prev);
		list->remove(actual->prev);
		//cerr << "punteros: " << actual->prev->numero << " " << actual->numero << " " << actual->next->numero << endl;
		if(!esCabeza && verSiEsPar(actual)) aumentarFrecuencia(make_pair(actual->prev->numero,actual->numero),actual);
		if(!esCola && verSiEsPar(actual->next)) aumentarFrecuencia(make_pair(actual->numero,actual->next->numero),actual->next);
		actual = nextReplace;
		//heap->print();
		//print();
		//cerr<<"-----------------"<<endl;
	}
	sigma++;
}

void heapRepair::rePair(char* text, int range){
	setSequence(text,range);
	firstRead();
	//ofstream salida;
	//salida.open("heapResultados.txt");
	//guardarListaInicial(salida);
	//cerr << "paso first read" << endl;
	while(compresible()){
		//guardarResultados(salida);
		replaceSequence();
	}
	//heap->print();
	destructorHeapyMap();

	return;
}

bool heapRepair::compresible(){
	//cerr << heap->top().frecuencia << " frecuencia y " << heap->top().par.first << heap->top().par.second << " de par" << endl;
	if(!heap->empty() && heap->top().frecuencia > 1)
		return true;
	else
		return false;
}

void heapRepair::reversePrint(){
	pointerIntNode* act = list->getTail();
	while(act!=nullptr){
		cerr << act->numero << " ";
		act = act->prev;
	}
	cerr << endl;
}

void heapRepair::print(){
	pointerIterador it = list->begin();
	while(it.hasNext()){
		cout << it.next() << " ";
	}
	cout << endl;
}

void heapRepair::guardarListaInicial(ofstream & salida){
	salida << "lista inicial: " << endl;
	pointerIterador it = list->begin();
	while(it.hasNext()){
		salida << it.next() << " ";
	}
	salida << endl;
}

void heapRepair::guardarResultados(ofstream & salida){
	salida << "lista comprimida: " << heap->top().par.first << " " << heap->top().par.second << "sigma" << sigma << endl;
	pointerIterador it = list->begin();
	while(it.hasNext()){
		salida << it.next() << " ";
	}
	salida << endl;
}

