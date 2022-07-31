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
            t = ( NULL!= t->leftNode) ? t->leftNode : t->rightNode;
            delete oldNode;
        }
    }
};

template< typename T>
void BinaryTree<T>::makeEmpty( BinaryNode * &t ) {
    if ( NULL !=t ) {
        makeEmpty(t->leftNode);
        makeEmpty(t->rightNode);
        std::cout << "delete: " << t->element << std::endl;
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
    if( NULL != bNode ) {
        inOrder(bNode->leftNode);
        std::cout << bNode->element << " " ;
        inOrder(bNode->rightNode);
    }
};

template< typename T>
void BinaryTree<T>::postOrder( BinaryNode *bNode ) const {
	
	if( NULL != bNode ) {
        postOrder(bNode->leftNode);
    	postOrder(bNode->rightNode);
    	std::cout << bNode->element << " " ;
    }  
};
