#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "Files.h"
using namespace std;



int main() {
	Files file;
	vector<string> aux = file.read();
    BinaryTree<const char*> bTree(aux[0].c_str());

    for(int i = 1 ; i < aux.size() ; i++ )
	{
		bTree.insert(aux[i].c_str());
	}
	bTree.postOrder();
	int height = bTree.treeHeight();
	cout<<"height: "<<height<<endl;
	cout << "" << endl;
    bTree.sheets();
    cout<<endl;
    cout<<"        ";
    bTree.showTree();
    return 0;
}
