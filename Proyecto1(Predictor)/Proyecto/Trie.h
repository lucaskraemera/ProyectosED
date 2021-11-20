#include <vector>
#include <string>
#ifndef TRIE_H
#define TRIE_H
struct node {
    std::vector<struct node*> hijos;
    char letras;
    int tam;
};

struct stringConFrecuencia {
    std::string s;
    int frecuencia;
};
#endif

using namespace std;

class Trie{
	private:
		node* arbol;
		node* crearNodo(char caracter);
		node* obtenerNodo(int pos, node* nivel);
		void borrarArbol(node* nivel);
		void revisarTrie(node* nivel,string aux); //metodo Auxiliar para verTrie
		void imprimirLetras(node* nivel); //metodo Auxiliar para verTrie
	public:
		Trie();
		~Trie();
		void insert(string s,int frecuencia);
		node* nodoMasCercano(string abuscar,int* aux); // entrega el nodo mas cercano a la palabra entregada
		vector<stringConFrecuencia> obtenerStrings(string aBuscar,int *aux); // obtiene strings de la palabra a buscar segun su nodo
		void aumentarFrecuencia(string s); // aumenta la frecuencia de la palabra seleccionada
		void verTrie(); // metodo para visualizar lo que hay en el trie (metodo auxiliar)
		
};
