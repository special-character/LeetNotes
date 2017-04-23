//
//  BinarySearchTree.cpp
//  DS
//
//  Created by Christopher Workman on 9/25/16.
//  Copyright © 2016 Christopher Workman. All rights reserved.
//

#include "BinarySearchTree.hpp"
#include <iostream>

BinarySearchTree::BinarySearchTree(Node* _root): root(_root){
};

bool BinarySearchTree::addNode(Node* root, Node* parent, Node& newNode){
    
    if(root == NULL && parent->left == NULL && newNode.value <= parent->value){
        root = &newNode;
        parent->left = root;
        return true;
    }
    else if(root == NULL && parent->right == NULL && newNode.value > parent->value){
        root = &newNode;
        parent->right = root;
        return true;
        
    }
    else if(newNode.value <= root->value){
        addNode(root->left, root, newNode);
        return true;
    }
    else{
        addNode(root->right, root, newNode);
        return true; 
    }
    
    return false;
};

void BinarySearchTree::printBST(Node* root){

    
    if(root->left == NULL){
        std::cout << std::to_string(root->value) << std::endl;
    }
    else if(root->left == NULL && root->right != NULL){
        
        std::cout << std::to_string(root->value) << std::endl;
        printBST(root->right);
    }
    else if(root->left != NULL && root->right != NULL){
        printBST(root->left);
        std::cout << std::to_string(root->value) << std::endl;
        printBST(root->right);
    }
    else if(root->left != NULL && root->right == NULL){
        printBST(root->left);
        std::cout << std::to_string(root->value) << std::endl;
    }
    
};