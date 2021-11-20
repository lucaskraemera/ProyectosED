#include "Controladora.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

Controladora::Controladora(char* diccionario,char* archivoBusqueda, char* resultados,int ka){
	//cout << "Controladora" << endl;
	this->pred = new Predictor();
	this->diccionario.open(diccionario);
	this->archivoBusqueda.open(archivoBusqueda);
	this->archivoSalida.open(resultados);
	this->k = ka;
}

Controladora::~Controladora(){
	delete pred;
}

void Controladora::lecturaDiccionario(){
	time_t t;
	t=clock();
	string palabra;
	int frecuencia;
	while(!diccionario.eof()){
		diccionario >> palabra;
		if(palabra[0]=='%') continue;
		frecuencia = rand()%1001;
		//cerr << palabra << frecuencia << endl;
		//cerr << endl;
		pred->insert(palabra,frecuencia);
		//cerr << "termino insert de controladora" << endl;
	}
	double time = double(clock()- t)/CLOCKS_PER_SEC;
	cerr << "time del insert " << time << " segundos" << endl;
}

void Controladora::busqueda(){
	time_t t;
	t=clock();
	string aBuscar;
	vector<string> resultados;
	while(!archivoBusqueda.eof()){
		archivoBusqueda >> aBuscar;
		resultados = pred->busqueda(aBuscar,k);
		imprimirResultados(resultados, aBuscar);	
	}
	double time = double(clock()- t)/CLOCKS_PER_SEC;
	cerr << "time de la busqueda " << time << " segundos" << endl;
}

void Controladora::imprimirResultados(vector<string> resultados,string aBuscar){
	archivoSalida << aBuscar << ":";
	for(int i=0; i < resultados.size(); i++){
		archivoSalida << " " << resultados[i];
	}
	archivoSalida << "\n";
}
