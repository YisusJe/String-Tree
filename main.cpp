#include <iostream>
#include <vector>
using namespace std;
#include "BinaryTree.h"
#include "BinaryTree.cpp"


//void numDePalabras(string palabra){
//    vector<int> numeros;
//    const char* palabraAux = palabra.c_str();
//    
//    for(int i = 0; i < palabra.size() ; i++){
//        
//        numeros.push_back((int)palabraAux[i]);
//        
//        cout << numeros[i] << endl; 
//    }    
//}
int main() {
    struct BinaryNode *nodo;
    BinaryTree<const char*> bTree("zorro");
    bTree.insert("perro");
    bTree.insert("manzana");
    bTree.insert("hilo");
    bTree.insert("casa");
    bTree.preOrder();
    return 0;
}
