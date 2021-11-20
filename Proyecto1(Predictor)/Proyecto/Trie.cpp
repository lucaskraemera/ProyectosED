#include "Trie.h"
#include <string>
#include <iostream>

using namespace std;

Trie::Trie(){
	this->arbol = new node();
	arbol->hijos.assign('z'-'a'+2,NULL);
	arbol->letras = '&';
	arbol->tam=0;
}

Trie::~Trie(){
	if(arbol!=NULL){
		borrarArbol(arbol);	
	}
	delete arbol;
}

void Trie::borrarArbol(node* nivel){
	//cerr << nivel->letras;
	for(int i=0; i<nivel->hijos.size(); i++){
		if(nivel->hijos[i]!=NULL){
			borrarArbol(nivel->hijos[i]);
			delete nivel->hijos[i];	
		} 
	}
}

node* Trie::crearNodo(char caracter){
	// contar nodos creados
	node* puntero= new node();
	puntero->hijos.assign('z'-'a'+2,NULL);
	//cerr << endl << "crea nodo con letra: " << caracter << endl;
	puntero->letras =  caracter;
	puntero->tam=0;
	return puntero;
}

node* Trie::obtenerNodo(int pos,node* nivel){
	node* puntero = nivel->hijos[pos];
	if(puntero==NULL) return NULL;
	else return puntero;
}

void Trie::insert(string s,int frecuencia){
	node* aux; // nodo auxiliar de comparacion
	node* nivel = arbol; // nivel del vector en el que nos encontramos
	//cerr << "paso declaracion de variables del insert del trie" << endl;
	
	for(int i=0;i<s.size();i++){ // vector contiene en 0 '$' y de 1-26 a-z
		int pos = s[i] - 'a' + 1; // para saber la ubicacion en donde se encuentra la letra
		if(s[i] == '$') pos = 0;
		//cerr << "pos: " << pos << endl;
		aux = obtenerNodo(pos,nivel); // revisa si hay un nodo en la pos 
		//cerr << "nivel: " << i+1 << " caracter a insertar: " << s[i] << endl;
		//cerr << "arreglo: ";
		if(aux==NULL) nivel->hijos[pos] = crearNodo(s[i]); // caso que no habia un nodo se crea uno
		else nivel->hijos[pos]=aux; // caso contrario, se aprovecha de que el nodo ya existe (no lo sobreescribe)
		//cerr << endl;
		nivel=nivel->hijos[pos]; // asignar el siguiente nivel de la letra
	}
	nivel->tam = frecuencia; // asignarle la frecuencia adecuada
	//cerr << "se inserto correctamente la palabra" << endl;
}

node* Trie::nodoMasCercano(string s,int* aux){
	node* nivel = arbol;
	node* auxNodo;
	int nivelActual=0;
	for(int i=0;i<*aux;i++){
		int pos = s[i] - 'a' + 1;
		auxNodo = obtenerNodo(pos,nivel);
		if(auxNodo == NULL){
			*aux = nivelActual;
			return nivel;	
		} 
		nivelActual++;
		nivel = auxNodo;
	}
	return nivel;
}

void insertarStringsConFrecuencia(node* nivel, vector<stringConFrecuencia> *scf,string sActual){
	for(int i=0; i<nivel->hijos.size(); i++){
		if(nivel->hijos[i] != NULL){
			string sl = string(1,nivel->hijos[i]->letras);
			if(sl[0]=='$'){ // es un fin de palabra
				stringConFrecuencia insertar;
				insertar.s=sActual;
				insertar.frecuencia = nivel->hijos[i]->tam;
				scf->push_back(insertar);
				//cerr<< "se inserto en scf";
			}
			sActual += sl;	
			insertarStringsConFrecuencia(nivel->hijos[i],scf,sActual);
			sActual.pop_back();
		} 
	}
	return;
}

vector<stringConFrecuencia> Trie::obtenerStrings(string aBuscar,int *aux){
	node* nivel = nodoMasCercano(aBuscar,aux);
	string stringAuxiliar;
	for(int i=0; i<*aux; i++){
		stringAuxiliar+=aBuscar[i];
	}
	vector<stringConFrecuencia> scf;
	insertarStringsConFrecuencia(nivel,&scf,stringAuxiliar);
	
	return scf;
}

void Trie::aumentarFrecuencia(string s){
	node* nivel = arbol;
	for(int i=0;i<s.size();i++){
		int pos = s[i] - 'a' + 1;
		nivel = obtenerNodo(pos,nivel);
	}
	nivel = obtenerNodo(0,nivel);
	nivel->tam++;
}

//Metodos Auxiliares para imprimir el trie en caso de querer hacerlo
//para ser utilizados debe descomentarse el verTrie del insert del predictor.
void Trie::imprimirLetras(node* nivel){
	for(int i=0; i<nivel->hijos.size(); i++){
		if(nivel->hijos[i] != NULL) cout << nivel->hijos[i]->letras << " ";
	}
	cout << endl;
}

void Trie::revisarTrie(node* nivel,string aux){
	cout << "nivel " << aux.size() << endl << "string ahora: " << aux << ":" << endl;
	for(int i=0; i<nivel->hijos.size(); i++){
		if(nivel->hijos[i] != NULL){
			imprimirLetras(nivel);
			string sl = string(1,nivel->hijos[i]->letras);
			aux += sl;	
			revisarTrie(nivel->hijos[i],aux);
			aux.pop_back();
		} 
	}
}

void Trie::verTrie(){
	string aux;
	revisarTrie(arbol,aux);
}
