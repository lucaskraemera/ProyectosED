#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

	if(argc!=3){
		cout << "inserte el nombre del archivo diccionario y la cantidad de palabras del diccionario";
	}
	srand(time(NULL));
	int numero = stoi(argv[2]);
	ofstream salida;
	salida.open(argv[1]);
	
	for(int i=0;i<numero;i++){
		int cantLetras = 1 + rand()%10;
		string aInsertar;
		for(int j=0;j<cantLetras;j++){
			aInsertar+='a'+rand()%('z'-'a'+ 1);
		}
		salida << aInsertar << "\n";
	}
	return 0;
}
