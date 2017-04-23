//
//  Node.hpp
//  DS
//
//  Created by Christopher Workman on 9/25/16.
//  Copyright © 2016 Christopher Workman. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>


class Node {
public:
    Node(const int& val);
    const int value;
    Node* left;
    Node* right;
};

#endif /* Node_hpp */
