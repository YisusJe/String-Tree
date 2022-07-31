#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Files.h"
using namespace std;




int main() {
	Files file;
	vector<string> aux = file.read();
    BinaryTree<const char*> bTree(aux[0].c_str());
    bTree.insert("zorro");
    bTree.insert("manzana");
    bTree.insert("hilo");
    bTree.insert("casa");
    bTree.postOrder();
    int height = bTree.treeHeight();
    cout<<"height: "<<height<<endl;
    
    for(int i = 1 ; i < aux.size() ; i++ )
	{
		bTree.insert(aux[i].c_str());
	}
	bTree.postOrder();
	
	cout << "" << endl;
    bTree.sheets();
    return 0;
}
