//
//  BinarySearchTree.hpp
//  DS
//
//  Created by Christopher Workman on 9/25/16.
//  Copyright © 2016 Christopher Workman. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include "Node.hpp"
#include <string>

class BinarySearchTree{
public:
    BinarySearchTree(Node* root);
    Node* bst;
    
    Node* root;
    bool addNode(Node* root, Node* parent, Node& newNode);
    void printBST(Node* root);
};

#endif /* BinarySearchTree_hpp */
