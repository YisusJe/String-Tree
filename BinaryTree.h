#ifndef BINARYTREE_BINARYTREE_H_H
#define BINARYTREE_BINARYTREE_H_H

#include <iostream>
#include <vector>
#include <cmath>
template< typename T = const char*>
class BinaryTree  {
public:
    BinaryTree () =  default;
    BinaryTree ( const BinaryTree &bt );
    BinaryTree ( const T &theElement );
    ~BinaryTree();

    void insert ( const T &theElement );
    void remove ( const T &theElement );
    void makeEmpty ();
    bool isFind ( const T &theElement )  const;
    void preOrder () const;
    void inOrder () const;
    void postOrder () const;
    void sheets () const;
    int treeHeight () const; 
    bool isBalanced() const;
	void showTree () const;
    int numberOfWords(const char* word)  {
    	
    	std::vector<int> numbers;
    	int sum = 0;
    	std::string wordAux = word;
    	
    	for(int i = 0; i < wordAux.size() ; i++){
        	numbers.push_back((int)word[i]);
        	sum += numbers[i];
    	} 
		return sum;  
	}
    


private:

    struct BinaryNode {
        T element;
        BinaryNode *leftNode;
        BinaryNode *rightNode;
        BinaryNode (const T &ele, BinaryNode *left, BinaryNode *right)
                : element(ele), leftNode(left), rightNode(right) {};

        BinaryNode (const T &ele)
                : element(ele), leftNode(NULL), rightNode(NULL) {};

        BinaryNode (const BinaryNode *bNode)
                : element(bNode->element), leftNode(bNode->leftNode), rightNode(bNode->rightNode){
        }

    };

    BinaryNode *root;
    BinaryNode * clone (const BinaryNode *bNode ) ;
    void insert ( const T &theElement, BinaryNode * &t );
    void remove ( const T &theElement, BinaryNode * &t );
    void makeEmpty (BinaryNode * &t );
    bool isFind ( const T &theElement, BinaryNode *t )  const;
    BinaryNode * findMin (BinaryNode *bNode) const;
    BinaryNode * findMax (BinaryNode *bNode) const;
    void preOrder ( BinaryNode *bNode ) const;
    void inOrder ( BinaryNode *bNode ) const;
    void postOrder ( BinaryNode *bNode) const;
    int treeHeight (BinaryNode *bNode) const; 
    void sheets ( BinaryNode *bNode  ) const;
    int height( BinaryNode *bNode ) const;
    bool isBalanced( BinaryNode *bNode ) const;
    void showTree (BinaryNode *bNode, int cont) const;
};



#endif
