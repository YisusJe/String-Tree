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
    return 0;
}
