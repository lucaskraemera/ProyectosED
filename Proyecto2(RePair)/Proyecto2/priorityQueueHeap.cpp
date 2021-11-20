#include <iostream>
#include "priorityQueueHeap.h"
#include <vector>

using namespace std;

priorityQueueHeap::priorityQueueHeap(){
}

priorityQueueHeap::~priorityQueueHeap(){
}

bool priorityQueueHeap::esMenor(int nodoPadre, int nodoHijo){ //Criterio de comparacion: Quien tenga mayor frecuencia, y en segundo plano, quien tenga menor pair
	if(_arr[nodoPadre].frecuencia < _arr[nodoHijo].frecuencia)
		return true;
	else if(_arr[nodoPadre].frecuencia == _arr[nodoHijo].frecuencia){
		if(_arr[nodoPadre].par.first > _arr[nodoHijo].par.first)
			return true;
		else if(_arr[nodoPadre].par.first == _arr[nodoHijo].par.first && _arr[nodoPadre].par.second > _arr[nodoHijo].par.second)
			return true;
	}
	return false;	
}

void priorityQueueHeap::upHeap(int rank){
	//cerr << "RANK: "<<rank <<endl;
	if(rank == 0) return; // si estoy en la raiz, no puedo volver a hacerlo
	int nivelPadre = (rank-1)/2;
	if(esMenor(nivelPadre,rank)){
		//cout << "upheap swap entre(nivel superior, nivel inferior) " << _arr[nivelMayor] << " y " << _arr[rank] << endl;
		nodoHeap aux = _arr[rank];
		_arr[rank] = _arr[nivelPadre];
		_arr[nivelPadre] = aux;
		_arr[rank].punteroMapa->posHeap = rank;
		_arr[nivelPadre].punteroMapa->posHeap = nivelPadre;
		upHeap(nivelPadre);
	}
	return;
}

void priorityQueueHeap::downHeap(int rank){
	int posHijo = 2*rank + 1; // posHijo es el hijo izquierdo del nodo
	int size = _arr.size();
	if(posHijo >= size) return; // el nodo no tiene hijo
	if(posHijo+1 < size && esMenor(posHijo,posHijo+1)) posHijo = posHijo + 1;
	if(esMenor(rank,posHijo)){
		nodoHeap aux = _arr[rank];
		_arr[rank] = _arr[posHijo];
		_arr[posHijo] = aux;
		_arr[rank].punteroMapa->posHeap = rank;
		_arr[posHijo].punteroMapa->posHeap = posHijo;
		downHeap(posHijo);
	}
	return;
}

bool priorityQueueHeap::empty(){
	return _arr.empty();
}

int priorityQueueHeap::size(){
	return _arr.size();
}

nodoHeap priorityQueueHeap::at(int rank){
	return _arr[rank];
}

nodoHeap priorityQueueHeap::top(){
	return _arr[0];
}

void priorityQueueHeap::push(pair<int,int> par, infoNodo* puntero){
	nodoHeap aux;
	aux.frecuencia = 1;
	aux.par = par;
	aux.punteroMapa = puntero;
	_arr.push_back(aux);
	upHeap(_arr.size()-1);
}

void priorityQueueHeap::pop(){
	//_arr[0].punteroMapa->posHeap = _arr.size()-1;
	_arr[0]=_arr[_arr.size()-1];
	_arr[0].punteroMapa->posHeap = 0;
	_arr.pop_back();
	downHeap(0);
}

void priorityQueueHeap::aumentarClave(int rank){ //cambiar frecuencia
	_arr[rank].frecuencia++;
	upHeap(rank);
}

void priorityQueueHeap::disminuirClave(int rank){ //cambiar frecuencia
	//cerr << "disminuyo frecuencia" << endl;
	_arr[rank].frecuencia--;
	//if(_arr[rank].frecuencia < 0) cout << "error de frecuencia en par: " << _arr[rank].par.first << " " << _arr[rank].par.second << endl;
	downHeap(rank);
}
void priorityQueueHeap::print(){
	for(int i=0; i<_arr.size(); i++){
		cout << _arr[i].frecuencia << " " << _arr[i].par.first << " " << _arr[i].par.second << "; puntero: " << _arr[i].punteroMapa << endl ;
	}
}
