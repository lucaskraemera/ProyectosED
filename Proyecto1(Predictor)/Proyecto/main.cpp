#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Controladora.h"
#include <time.h>

using namespace std;

int main(int argc, char **argv){
	//cerr << "hola" << endl;
	if (argc!=5)
    {
        printf("Debes entregar 4 parametros\n");
        return 0;
    }
    srand(time(NULL));
    //cerr << endl << "nombre de archivos entregados:" << endl;
    //cerr << argv[1] << endl;
    //cerr << argv[2] << endl;
    //cerr << argv[3] << endl;
    //cerr << argv[4] << endl << endl;
    
	ifstream entrada;
	ifstream busqueda;
	ofstream salida;
	
	
	//asegurarse de que vengan los archivos requeridos
	int k = stoi(argv[4]);
	if(k<=0){
		cout << "k debe ser mayor o igual a 1" << endl;
		return 0;
	}
	busqueda.open(argv[2]);
	if(!busqueda){
		cout << "falta archivo de cadanas a buscar" << endl;
		return 0;
	}
	entrada.open(argv[1]);
	if(!entrada){
		cout << "falta archivo de diccionario" << endl;
		return 0;
	}
	salida.open(argv[3]);
	
	Controladora* control = new Controladora(argv[1],argv[2],argv[3],k);
	control->lecturaDiccionario();
	control->busqueda();
	
	//cerr << "Pre delete control" << endl;
	delete control;
	//cerr << "Post delete control" << endl;
	
	entrada.close();
	busqueda.close();
	salida.close();
	
	//cerr << "El proceso termino correctamente" << endl << endl;
	
    return 0;   
} 
