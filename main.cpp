#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Files.h"
using namespace std;

// Adrian Alberto Fagilde Nava 27.638.256
// Jesus David Perez Chavez 27.989.248

int main() {
	 
	Files file; // llamo al archivos
	vector<string> aux = file.read(); // retorno el vector de las palabras
    BinaryTree<const char*> bTree(aux[0].c_str()); // inicializo Arbol Binario
    
    
    for(int i = 1 ; i < aux.size() ; i++ )
	{
		bTree.insert(aux[i].c_str());
	}
	
	cout << "PostOrder: " ;
	bTree.postOrder();
	cout << endl;
	int height = bTree.treeHeight();
	cout << "altura:" << height << endl;
	cout << "hojas:";
    bTree.sheets() ;
    cout <<endl;
    string cadena = (bTree.isBalanced())? "Si" : "No";
    cout << "Esta Balanceado: " << cadena  << endl;
    cout <<endl;
    cout << "      " ;
    
    bTree.showTree(); // mostramos el Arbol
    
    
    return 0;
}
