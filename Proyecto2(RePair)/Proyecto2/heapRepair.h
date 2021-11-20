#include "priorityQueueHeap.h"
#include <map>
#include <fstream>

using namespace std;

class heapRepair{
	private:
		pointerDoublyLinkedList* list; //lista doblemente enlazada especial
		priorityQueueHeap* heap; // heap utilizado para saber cual es el elemento con mayor frecuencia
		map<pair<int,int>, infoNodo*> mapa; // mapa utilizado para almacenar la primera ocurrencia y ultima del par a reemplazar
		int sigma; // valor que es utilizado como entero(/char) extra para reemplazar los pares
		void destructorHeapyMap(); // borra la informacion que queda tanto en el heap como en el mapa
		void setSequence(char* text, int range); // construye la linked list con la informacion entregada en el fichero
		void firstRead(); // inicializa el mapa y el heap, se tiene que leer toda la lista de numeros 
		void replaceSequence(); // algoritmo que reemplaza el par de mayor frecuencia con el nuevo symbolo(sigma)
		void aumentarFrecuencia(pair<int,int> par, pointerIntNode* puntero); // actualiza la informacion del mapa y el heap, en caso de que no exista se crea
		bool compresible(); // bool que nos indica si se puede seguir comprimiendo la lista
		void actualizarPunteros(pointerIntNode* puntero); // metodo que actualiza los punteros en caso de que se considere el par a borrar
		bool verSiEsPar(pointerIntNode* actual); // metodo que verifica si el par a insertar es considerado par,
		bool verSiEsPar2(pointerIntNode* actual); // metodo que verifica si el par en la secuencia es considerado par
		void guardarListaInicial(ofstream & salida); // almacena la lista inicial en el archivo de salida
		void guardarResultados(ofstream & salida); // se guarda la lista comprimida en el archivo mapRepair.txt
		void reversePrint(); // metodo que imprime la lista en inverso(incluye punteros cabeza y cola)
	public:
		heapRepair(); // constructor
		~heapRepair(); // destructor
		void rePair(char* text, int range); // metodo encargado de comprimir los enteros entregados por el fichero text
		void print(); // imprime lo que hay en la lista
};
