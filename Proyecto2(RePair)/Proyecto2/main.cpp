#include <iostream>
#include <fstream>
#include <time.h>
#include "mapRepair.h"
#include "heapRepair.h"
#include "pointerDoublyLinkedList.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc!=3){ // asegurarse que entregue un fichero de texto
        cout << "Debes entregar 2 parametros, el archivo de texto con numeros y el rango de los numeros (entre 1 y el rango que tu entreges)" << endl;
        return 0;
    }
	time_t t;
	cout << "map re-pair:" << endl;
	mapRepair* mapRe = new mapRepair();
	t=clock();
	mapRe->rePair(argv[1], stoi(argv[2]));
	double time = double(clock()- t)/CLOCKS_PER_SEC;
    cerr << "Tiempo MapRepair: " << time << " segundos" << endl;
	mapRe->print();

	

	cout << endl << endl << "heap re-pair: " << endl;
	heapRepair* heapRe = new heapRepair();
	t=clock();
	heapRe->rePair(argv[1], stoi(argv[2]));
	time = double(clock()- t)/CLOCKS_PER_SEC;
    cerr << "Tiempo HeapRepair: " << time << " segundos" << endl;
	heapRe->print();
	
	delete mapRe;
	delete heapRe;
	
	cout << "El proceso termino correctamente" << endl;
	return 0;
}
