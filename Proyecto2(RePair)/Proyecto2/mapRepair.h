#include "doublyLinkedList.h"
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <map>

using namespace std;

class mapRepair{
	private:
		doublyLinkedList* list; // lista que guarda los symbolos/enteros que son comprimidos
		map<pair<int,int>,int> mapa; // mapa utilizado para determinar cual es el elemento con mayor frecuencia
		int sigma; // valor utilizado para reemplazar por un par
		void setSequence(char* text, int range); // inicializa la lista con los numeros del fichero entregado 
		pair<int,int> firstRead(); // indica el par de mayor frecuencia(el que se va a reemplazar)
		void replaceSequence(pair<int,int> par); // se reemplaza el par entregado en la lista por el nuevo symbolo/entero
		bool esMenor(pair<int,int> p1, pair<int,int> p2); // criterio utilizado para verificar si un par es menor que otro
		void guardarResultados(pair<int,int> par, ofstream & salida); // se guarda la lista comprimida en el archivo mapRepair.txt
		void guardarListaInicial(ofstream & salida); // se guarda la lista inicial en el archivo mapRepair.txt
	public:
		mapRepair();
		~mapRepair();
		void rePair(char* text, int range); // metodo que comprime el archivo de enteros entregado
		void print(); // metodo que imprime los elementos de la lista (sirve para imprimir la cadena inicial y la final)
};
