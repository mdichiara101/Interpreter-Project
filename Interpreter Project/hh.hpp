//
//  src.hpp
//  Interpreter Project
//
//  Created by Michael Dichiara on 4/11/19.
//  Copyright © 2019 Michael Dichiara. All rights reserved.
//

#ifndef src_hpp
#define src_hpp
#include <string>
using namespace std;

string comm;

class Node
{
public:
    char  let,let2;
    int pos;
    Node* next;
    
    Node();
    
};
typedef class Node node;

class list
{
    node *head, *tail;
public:

    list();
    ~list();
    void createNode(char a, int value);
    void command();
    bool B();
    bool VA(node* temp);
    bool IT(node* temp);
    bool var(node* temp);
    bool CT(node* temp);
    bool IT_Tail(node* temp);
    bool CT_Tail(node* temp);
    bool L(node* temp);
    bool A(node* temp);
    void pop();
    void evaluate(node* temp);
    void varSearch(node* temp);
    
};


#include <stdio.h>

#endif /* src_hpp */
