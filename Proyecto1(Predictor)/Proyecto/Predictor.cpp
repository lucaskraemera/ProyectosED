#include "Predictor.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Predictor::Predictor(){
	//cerr << "Predictor" << endl;
	t = new Trie();
}
Predictor::~Predictor(){
	delete t;
}

void Predictor::insert(string s,int frecuencia){
	//cerr << "insert del predictor" << endl;
	s+='$';
	//cerr << s << endl;
	t->insert(s,frecuencia);
	//cerr << "termino insert del predictor" << endl;
	/*
	cerr << "VER TRIE:" << endl << endl;
	t->verTrie();
	*/
}

vector<stringConFrecuencia> Predictor::priorizarPalabras(vector<stringConFrecuencia> *scfAux,vector<stringConFrecuencia> *scf,int k){
	vector<stringConFrecuencia> resultado;
	if(scfAux->size()==0){
		for(int i=0;i<k;i++){
			resultado.push_back(scf->at(i));
		}
	}
	else{
		/*
		cerr << "BUFFER: ";
		for(int i=0;i<scfAux->size();i++){
			cerr << scfAux->at(i).s << " ";
		}
		cerr << endl;
		*/
		for(int i=0;i<scfAux->size();i++){ //agregar el buffer
			resultado.push_back(scfAux->at(i));
			//cerr << scfAux->at(i).s << endl;
		}
		//cerr << "paso primer for pp"<< endl;
		
		for(int i=0;resultado.size()<k;i++){
			string comp;
			bool noEsta=true;
			int ka;
			comp=scf->at(i).s;
			ka = 0;
			for(ka;ka<scfAux->size();ka++){
				if(comp==scfAux->at(ka).s){
					//cerr << comp << "SE REPITE" << endl;
					break;
				}
			}
			if(ka==scfAux->size()){
				//cerr << comp << " no se encuentra en el arreglo" << endl;
				noEsta=false;
			} 
			if(!noEsta){
				resultado.push_back(scf->at(i));
			} 
		}
		
		//cerr << "paso segundo for pp"<< endl;
	}
		
	return resultado;
}

void Predictor::ordenarArr(vector<stringConFrecuencia>* scf){
	if(scf->size()==0) return;
	for(int i=0;i<scf->size();i++){ //ordenar
		int menor = i;
		for(int j = i+1;j<scf->size();j++){
			if (scf->at(menor).frecuencia < scf->at(j).frecuencia) menor = j;
			else if(scf->at(menor).frecuencia == scf->at(j).frecuencia && scf->at(menor).s.compare(scf->at(j).s) > 0){
				menor = j;
				//cerr << "menor" << menor << " j" << j << endl;
			} 
		}
		stringConFrecuencia aux;
		aux=scf->at(i);
		scf->at(i) = scf->at(menor);
		scf->at(menor) = aux;
	}
}

vector<string> Predictor::busqueda(string aBuscar,int k){
	int aux= aBuscar.size()+1;
	vector<stringConFrecuencia> resultado;
	vector<stringConFrecuencia> scf;
	vector<stringConFrecuencia> scfAux;
	vector<string> resultados;
	do{
		scfAux=scf;
		aux--;
		scf = t->obtenerStrings(aBuscar,&aux);
	}while(k>scf.size());
	//cerr << "pre priorizarPalabras" << endl;
	//hacer pin de las palabras de scfAux y agregar las de scf
	ordenarArr(&scf);
	resultado = priorizarPalabras(&scfAux,&scf,k);
	ordenarArr(&resultado);
	
	//cerr << "post priorizarPalabras" << endl;
	
	//cerr << "scf: " << aBuscar << endl;
	//for(int i=0;i<scf.size();i++){
	//	cerr << scf[i].s << scf[i].frecuencia << " ";
	//}
	//cerr << endl;
	
	for(int i = 0; i<k;i++){ // insertar los datos en el vector resultado y aumentar las frecuencias seleccionadas
		resultados.push_back(resultado[i].s);
		t->aumentarFrecuencia(resultado[i].s);
	}
	
	//for(int i = 0; i< resultado.size();i++){
	//	cerr << resultados[i] << " ";
	//}
	//cerr << " RESULTADOS I" << endl << endl << endl<< endl << endl<< endl << endl<< endl << endl;
	
	return resultados;
}

