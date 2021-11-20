#include "mapRepair.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

mapRepair::mapRepair(){
	this->list = new doublyLinkedList();
	this->sigma;
	this->mapa;
}

mapRepair::~mapRepair(){
	delete list;
}

void mapRepair::setSequence(char* text, int range){
	delete this->list;
	this->list = new doublyLinkedList();
	this->sigma = range + 1;
	ifstream lectura;
	lectura.open(text);
	int symbolo;
	while(lectura >> symbolo){
		list->insertLast(symbolo);
	}
}

bool mapRepair::esMenor(pair<int,int> p1, pair<int,int> p2){
	if(p1.first < p2.first) return true;
	else if(p1.first==p2.first && p1.second < p2.second) return true;
	return false;
}

pair<int,int> mapRepair::firstRead(){
	mapa.clear();
	bool repetido = true;
	//hacer la lectura
	iterador it = list->begin();
	pair<int,int> actualPair;
	if(it.hasNext()) actualPair.second = it.next(); // inicializamos el second para el ciclo while
	
	//algoritmo de colocar los symbolos/enteros en el map y aumentar su frecuencia
	while(it.hasNext()){

		int siguientee = it.next();
		if(actualPair.first == actualPair.second && actualPair.second == siguientee && repetido){
			repetido = false;
    		continue;
		}
		actualPair.first = actualPair.second;
		actualPair.second = siguientee;
		
		mapa[actualPair] = mapa[actualPair] + 1; // aumenta la frecuencia del par, en caso de no existir lo crea y lo deja en 1
		repetido = true;
	}

	// se busca la clave con mayor frecuencia
	map<pair<int,int>,int>::iterator it2;
	int mayor=0;
	pair<int,int> pairMayor;
	pair<pair<int,int>,int> parActual;

	for(it2=mapa.begin(); it2!=mapa.end(); it2++){
		parActual = *it2;
		if(parActual.second > mayor || (parActual.second == mayor && esMenor(parActual.first, pairMayor))){
			mayor = parActual.second;
			pairMayor = parActual.first;
		}
	}

	// verificar si la frecuencia del par es mayor a 1 (criterio de detencion)
	if(mayor>1) return pairMayor;
	else{
		actualPair.first = 0;
		return actualPair;
	}
}

void mapRepair::replaceSequence(pair<int,int> par){
	pair<int,int> listPar;
	iterador it = list->begin();
	while(it.hasNext()){
		listPar.first = listPar.second;
		listPar.second = it.next();
		if(listPar == par){ //hay que reemplazar
			intNode* nodeAux = it.getNode();
			list->remove(nodeAux->prev);
			list->remove(nodeAux->prev);
			list->insertBeforeNode(sigma, nodeAux);
			listPar.second = sigma; // mantener el listPar actualizado correctamente
		}
	}
}

void mapRepair::rePair(char* text, int range){
	this->setSequence(text,range);
	pair<int,int> par;
	//print();
	par = this->firstRead();
	//ofstream salida;
	//salida.open("mapResultados.txt");
	//salida << "secuencia inicial: ";
	//guardarListaInicial(salida);
	while(par.first != 0){ // criterio de detencion
		replaceSequence(par);
		//guardarResultados(par,salida);
		sigma++;
		par = this->firstRead();
	}
	return;
}

void mapRepair::print(){
	iterador it = list->begin();
	while(it.hasNext()){
		cout << it.next() << " ";
	}
	cout << endl;
}

void mapRepair::guardarListaInicial(ofstream & salida){
	iterador it = list->begin();
	while(it.hasNext()){
		salida << it.next() << " ";
	}
	salida << endl;
}

void mapRepair::guardarResultados(pair<int,int> par, ofstream & salida){
	salida << "par a reemplazar: " << par.first << " " << par.second << "\n" << "Secuencia resultante:";
	iterador it = list->begin();
	while(it.hasNext()){
		salida << it.next() << " ";
	}
	salida << endl;
}
