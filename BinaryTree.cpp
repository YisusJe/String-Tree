#include <iostream>
#include <vector>
#include "BinaryTree.h"

template< typename T>
// Constructores
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

// Desctructor
template< typename T>
BinaryTree<T>::~BinaryTree() {
    makeEmpty();
    /* root->~BinaryNode();*/
};


// Funcion encargada de insertar los elementos
template< typename T>
void BinaryTree<T>::insert(const T &theElement) {
    insert(theElement, root );
};


// Funcion encargada de remover los elementos
template< typename T>
void BinaryTree<T>::remove(const T &theElement) {
    remove(theElement,root);
};

// Funcion se usa en el destructor
template< typename T>
void BinaryTree<T>::makeEmpty() {
    makeEmpty(root);
};

// isFind retorna si el elemento existe en el arbol
template< typename T>
bool BinaryTree<T>::isFind(const T &theElement) const {
    isFind(theElement,root);
};


// Recorrido de preOrder 
template< typename T>
void BinaryTree<T>::preOrder() const {
    preOrder(root);
};

// Recorrido de inOrder 
template< typename T>
void BinaryTree<T>::inOrder() const {
     inOrder(root);
};


// Recorrido de postOrder
template< typename T>
void BinaryTree<T>::postOrder() const {
    postOrder(root);
};

// treeHeight nos retorna la altura del Arbol
template< typename T>
int BinaryTree<T>::treeHeight() const {
    treeHeight(root);
};

// sheets se usa para contar las hojas 
template< typename T>
void BinaryTree<T>::sheets() const {
	sheets(root); 
}
// isBalanced se usa para revisar si esta balanceado o no el Arbol
template< typename T>
bool BinaryTree<T>::isBalanced() const {
	isBalanced(root);
};

// funcion para mostrar el Arbol
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

// Funcion encargada de insertar los elementos
template< typename T>
void BinaryTree<T>::insert(const T &theElement, BinaryNode * &t ) {
    if ( NULL == t ){
        t = new BinaryNode (theElement);
    } else if ( numberOfWords(theElement) < numberOfWords(t->element) ) {
          insert( theElement, t->leftNode );
    } else if ( numberOfWords(theElement) > numberOfWords(t->element) ) {
          insert ( theElement, t->rightNode );
    } else {
    }
};

// Funcion encargada de remover los elementos
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

// isFind retorna si el elemento existe en el arbol
template< typename T>
bool BinaryTree<T>::isFind(const T &theElement, BinaryNode * t ) const {
    if ( NULL == t ){
        return false;
    } else if ( theElement < t->element ) {
        return isFind( theElement, t->leftNode );
    } else if ( theElement > t->element ) {
         return isFind ( theElement, t->rightNode );
    } else {
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

// sheets se usa para contar las hojas 
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
        // Vacio siempre balanceado
        return 0;
    }
    // Buscar la altura de left
    int lh = height(bNode->leftNode);
    if (lh == -1) {
        // left esta desvalanceado
        return -1;
    }
    // Buscar la Altura de right
    int rh = height(bNode->rightNode);
    if (rh == -1) {
        // SubArbol No balanceado
        return -1;
    }
    if (abs(lh - rh) <= 1) {
        // Arbol Balanceado retorna la Altura
        return 1 + std::max(height(bNode->leftNode), height(bNode->rightNode));
    }
    // no Balanceado
    return -1;
}

// isBalanced se usa para revisar si esta balanceado o no el Arbol
template< typename T>
bool BinaryTree<T>::isBalanced( BinaryNode *bNode  ) const {
	 // llamo a la funcion height
    int h = height(root);
    if (h == -1) {
        // no balanceado
        return false;
    }
    // Balanced verdadero
    return true;
}


// funcion para mostrar el Arbol
template< typename T>
void BinaryTree<T>::showTree( BinaryNode *bNode, int cont  ) const {
	if(bNode == NULL){
		return;
	} else {
		showTree(bNode->leftNode, cont + 1);
		std::cout<<bNode->element<<std::endl;
		for(int i=0; i<cont; i++){
			std::cout<<"    ";
		}
		showTree(bNode->rightNode, cont + 1);
	}
}
