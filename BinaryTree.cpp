#include <iostream>
#include <vector>
#include "BinaryTree.h"




template< typename T>
BinaryTree<T>::BinaryTree(const BinaryTree &bt) {
    if( NULL != bt.root ) {
        this->root = clone(bt.root);
    } else {
        root = NULL;
    }
};

template< typename T>
BinaryTree<T>::BinaryTree(const T &theElement) {
    root = new BinaryNode(theElement);
    root->element = theElement;
    root->leftNode = NULL;
    root->rightNode = NULL;
}

template< typename T>
BinaryTree<T>::~BinaryTree() {
    makeEmpty();
    /* root->~BinaryNode();*/
};

template< typename T>
void BinaryTree<T>::insert(const T &theElement) {
    insert(theElement, root );
};

template< typename T>
void BinaryTree<T>::remove(const T &theElement) {
    remove(theElement,root);
};

template< typename T>
void BinaryTree<T>::makeEmpty() {
    makeEmpty(root);
};

template< typename T>
bool BinaryTree<T>::isFind(const T &theElement) const {
    isFind(theElement,root);
};

template< typename T>
void BinaryTree<T>::preOrder() const {
    preOrder(root);
};

template< typename T>
void BinaryTree<T>::inOrder() const {
     inOrder(root);
};


template< typename T>
void BinaryTree<T>::postOrder() const {
    postOrder(root);
};

template< typename T>
int BinaryTree<T>::treeHeight() const {
    treeHeight(root);
};

template< typename T>
void BinaryTree<T>::sheets() const {
	sheets(root); 
}
template< typename T>
bool BinaryTree<T>::isBalanced() const {
	isBalanced(root);
};
template< typename T>
void BinaryTree<T>::showTree() const {
	showTree(root, 0); 
}

template< typename T>
typename BinaryTree<T>::BinaryNode*  BinaryTree<T>::clone(const BinaryNode *r) {
    if ( NULL == r ) {
        return NULL;
    } else {
        return  new BinaryNode(r->element, clone(r->leftNode), clone(r->rightNode));
    }
}

template< typename T>
void BinaryTree<T>::insert(const T &theElement, BinaryNode * &t ) {
    if ( NULL == t ){
        t = new BinaryNode (theElement);
    } else if ( numberOfWords(theElement) < numberOfWords(t->element) ) {
          insert( theElement, t->leftNode );
    } else if ( numberOfWords(theElement) > numberOfWords(t->element) ) {
          insert ( theElement, t->rightNode );
    } else {//???????????
    }
};

template< typename T>
void BinaryTree<T>::remove(const T &theElement, BinaryNode * &t ) {
    if( NULL == t ) {
        return;
    } else {
        if ( numberOfWords(theElement) < numberOfWords(t->element)) {
            remove(t->leftNode);
        } else if ( numberOfWords(theElement) > numberOfWords(t->element)) {
            remove (t->rightNode);
        } else if  (NULL != numberOfWords(t->leftNode) && NULL != numberOfWords(t->rightNode) ) {  //???????????
             t->element = findMin(numberOfWords(t->rightNode))->element;
            remove(t->element, t->rightNode);
        } else {
            BinaryNode * oldNode = t;
            t = ( NULL != t->leftNode) ? t->leftNode : t->rightNode;
            delete oldNode;
        }
    }
};

template< typename T>
void BinaryTree<T>::makeEmpty( BinaryNode * &t ) {
    if ( NULL !=t ) {
        makeEmpty(t->leftNode);
        makeEmpty(t->rightNode);
        delete t;
    }
    t = NULL;
};

template< typename T>
bool BinaryTree<T>::isFind(const T &theElement, BinaryNode * t ) const {
    if ( NULL == t ){
        return false;
    } else if ( theElement < t->element ) {
        return isFind( theElement, t->leftNode );
    } else if ( theElement > t->element ) {
         return isFind ( theElement, t->rightNode );
    } else { //??
        return true;
    }
};


template< typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::findMin(BinaryNode *bNode) const {
    if ( NULL!= bNode) {
        while( NULL != bNode->leftNode) {
            bNode = bNode->leftNode;
        }
    }
    return bNode;
}

template< typename T>
typename BinaryTree<T>::BinaryNode * BinaryTree<T>::findMax(BinaryNode *bNode) const {
    if ( NULL!= bNode) {
        while( NULL != bNode->rightNode) {
            bNode = bNode->rightNode;
        }
    }
    return bNode;
}


template< typename T>
void BinaryTree<T>::preOrder( BinaryNode *bNode ) const {
    if( NULL != bNode ) {
        std::cout << bNode->element << " " ;
        preOrder(bNode->leftNode);
        preOrder(bNode->rightNode);
    }

};

template< typename T>
void BinaryTree<T>::inOrder( BinaryNode *bNode ) const {
 
        inOrder(bNode->leftNode);
        std::cout << bNode->element << " " ;
        inOrder(bNode->rightNode);

};

template< typename T>
void BinaryTree<T>::postOrder( BinaryNode *bNode ) const {	
	if( NULL != bNode ) {
        postOrder(bNode->leftNode);
    	postOrder(bNode->rightNode);
    	std::cout << bNode->element << " " ;
    }  
};

template< typename T>
int BinaryTree<T>::treeHeight(BinaryNode *bNode) const {
    if (bNode == NULL) 
        return 0;
    else {
        int left_height = treeHeight(bNode->leftNode);
        int right_height = treeHeight(bNode->rightNode);
          
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
	}
}

template< typename T>
void BinaryTree<T>::sheets( BinaryNode *bNode  ) const {
	if( NULL != bNode ) {
		sheets(bNode->leftNode);
		sheets(bNode->rightNode);
       	if( bNode->leftNode == NULL && bNode->rightNode == NULL){
       		std::cout << bNode->element << " " ;
		}
    } 
}
template< typename T>
int BinaryTree<T>::height( BinaryNode *bNode ) const{
	if (bNode == NULL) {
        // Empty tree is always balanced
        return 0;
    }
    // Find the left height
    int lh = height(bNode->leftNode);
    if (lh == -1) {
        // Left subtree is unbalanced
        return -1;
    }
    // Find the right height
    int rh = height(bNode->rightNode);
    if (rh == -1) {
        // Right subtree is unbalanced
        return -1;
    }
    if (abs(lh - rh) <= 1) {
        // Balanced tree, return the height
        return 1 + std::max(height(bNode->leftNode), height(bNode->rightNode));
    }
    // Unbalanced tree
    return -1;
}
template< typename T>
bool BinaryTree<T>::isBalanced( BinaryNode *bNode  ) const {
	 // Call the modified height function
    int h = height(root);
    if (h == -1) {
        // Unbalanced tree
        return false;
    }
    // Balanced tree
    return true;
}
template< typename T>
void BinaryTree<T>::showTree( BinaryNode *bNode, int cont  ) const {
	if(bNode == NULL){
		return;
	} else {
		showTree(bNode->rightNode, cont + 1);
		for(int i=0; i<cont; i++){
			std::cout<<"    ";
		}
		std::cout<<bNode->element<<std::endl;
		showTree(bNode->leftNode, cont + 1);
	}
}
