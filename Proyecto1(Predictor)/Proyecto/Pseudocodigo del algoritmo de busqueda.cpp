Algorithm:busqueda(aBuscar, k):
Input:    A string aBuscar to search in the Trie and an integer k that contains the number
          of words that should be printed in the output file
Output:   A string vector resultados that contains the strings that are going to be printed 
          in the output file.

	aux <- aBuscar.size()+1
	resultado <- an empty vector that contains stringConFrecuencia
	scf <- an empty vector that contains stringConFrecuencia
	scfAux <- an empty vector that contains stringConFrecuencia;
	resultados <- an empty vector that contains strings;
	do
		scfAux <- scf
		aux <- aux-1
		scf  <- t->obtenerStrings(aBuscar,&aux);
	while k > scf.size()
	ordenarArr(&scf);
	resultado <- priorizarPalabras(&scfAux,&scf,k);
	ordenarArr(&resultado);
	
	for i = 0 to k-1 do 
		resultados.push_back(resultado[i].s);
		t->aumentarFrecuencia(resultado[i].s);	
	return resultados;




