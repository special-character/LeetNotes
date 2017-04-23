#include "Node.hpp"
#include "BinarySearchTree.hpp"




#include <iostream>

int main(int argc, const char * argv[]) {
    
    std::cout << "Entering node creation\n";
    Node root {10};
    Node a {5};
    Node b {3};
    Node c {6};
    Node d {2};
    Node e {17};
    Node f {23};
    Node g {22};
    Node h {24};
    
    BinarySearchTree bst {&root};
    bst.addNode(&root, &root, a);
    bst.addNode(&root, &root, b);
    bst.addNode(&root, &root, c);
    bst.addNode(&root, &root, d);
    bst.addNode(&root, &root, e);
    bst.addNode(&root, &root, f);
    bst.addNode(&root, &root, g);
    bst.addNode(&root, &root, h);


    
    bst.printBST(&root);
    std::cout << "Finsihing up!";
    return 0;
}
