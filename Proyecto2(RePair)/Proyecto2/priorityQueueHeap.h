#include <vector>
#include "pointerDoublyLinkedList.h"

using namespace std;

struct infoNodo{
	pointerIntNode* primerIgual;
	pointerIntNode* ultimoIgual;
	int posHeap;
};

struct nodoHeap{
	int frecuencia;
	pair<int, int> par;
	infoNodo* punteroMapa;	
};

class priorityQueueHeap{

private:
	vector<nodoHeap> _arr;  //Almacena la frecuencia como clave, y los pares
	void upHeap(int rank); // verifica si se necesita mantener el orden del nodo entregado respecto a su padre
	void downHeap(int rank); // verifica si se mantieene el orden del nodo entregado respecto a sus hijos
	bool esMenor(int nodoPadre,int nodoHijo); // criterio de comparacion para saber que nodo es mayor/menor
public:
	priorityQueueHeap();
	~priorityQueueHeap();
	bool empty(); // indica si el heap se encuentra vacio o no
	int size(); // entrega el tamaño del heap
	nodoHeap top(); // entrega el nodo de mayor frecuencia
	void push(pair<int,int> par, infoNodo* pointer); // crea un nodo, lo inserta en el heap y hace upheap
	void pop(); // elimina el nodo de mayor frecuencia
	void aumentarClave(int rank); // aumenta la frecuencia del par ubicado en rank y hace upheap
	void disminuirClave(int rank); // disminuye la frecuencia del par ubicado en rank y hace downheap
	nodoHeap at(int rank); // metodo que permite acceder a la ubicacion especifica de un nodo en el heap 
	void print(); // imprime todos los elementos del heap en el orden frecuecia, par, puntero a ubicacion en el mapa
};
