//
//  three.cpp
//  Interpreter Project
//
//  Created by Michael Dichiara on 4/14/19.
//  Copyright © 2019 Michael Dichiara. All rights reserved.
//
//Input Method:User Input

#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;
bool result=false;
int z=0;
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
    bool evaluate(node* temp);
    void varSearch(node* temp);
    char PSearch(node*temp);
    
};


node::Node()
{
    this->let=0;
    this->let2=0;
    this->pos=0;
    this->next=0;
}
list::list()
{
    head=NULL;
    tail=NULL;
}
list::~list()
{
    node* ptr= head;
    node* temp;
    while(ptr!=NULL)
    {
        temp=ptr->next;
        delete(ptr);
        ptr=temp;
    }
}
void list::createNode(char a, int value)
{
    node *tem=new node;
    tem->pos=value;
    tem->let=a;
    tem->next=NULL;
    if(head==NULL)
    {
        head=tem;
        tail=tem;
        tem=NULL;
    }
    else
    {
        tail->next=tem;
        tail=tem;
    }
}
void list::command()
{
    char input[1000];
    cout<<"Enter your command:"<<endl;
    cin>>input;
    int size= (int)strlen(input);
    printf ("The command entered is %u characters long.\n",(unsigned)strlen(input));
    for(int i=0; i<size;i++)
    {   if(input[i]=='#'|| input[i]=='T' ||input[i]=='F' ||input[i]=='^' ||input[i]=='V' ||islower(input[i])||input[i]=='('||input[i]==')'||input[i]=='~'||(input[i]=='-'&&input[i+1]=='>')||input[i]==' '||input[i]=='.'||input[i]==';'||(input[i]==':'&&input[i+1]=='=')||(input[i-1]==':'&&input[i]=='=')){
        createNode(input[i], i);
        
    }
    else
    {
        cout<<"Error Unknown variable"<<endl;
        return;
    }
    }
    return;
}
bool list::B()
{
    node *temp= head;
    if(tail->let=='.')
    {
        if(VA(temp))
        {
            temp=head;
            cout<<temp->let<<endl;
            if(IT(temp))
            {
                cout<<"The command you entered is valid"<<endl;
                return true;
            }
            else
            {
                cout<<temp->let<<endl;
                cout<<"The command you entered is not valid"<<endl;
                return false;
            }
        }
        else if(IT(temp))
        {
            cout<<"The command you entered is valid2"<<endl;
            return true;
        }
        else
        {
            cout<<"The command you entered is not valid2"<<endl;
            return false;
        }
    }
    else
    {
        cout<<"Error:Input must end with a period"<<endl;
        return false;
    }
}
bool list::VA(node *temp)
{
    if(temp==tail&&temp->let=='.')
    {
        pop();
        return true;
    }
    if(temp->let=='#')
    {
        cout<<"1."<<temp->let<<endl;
        temp=temp->next;
        pop();
        if(islower(temp->let))
        {
            cout<<"2."<<temp->let<<endl;
            temp=temp->next;
            pop();

            cout<<"3."<<temp->let<<endl;
            if(temp->let==':'&&temp->next->let=='=')
            {
                if(temp->next->next->let=='T')
                {
                    temp->let2='T';
                    varSearch(temp);
                }
                else if(temp->next->next->let=='F')
                {
                    temp->let2='F';
                    varSearch(temp);
                }
                else if(temp->next->next->let=='~'&&temp->next->next->next->let=='F')
                {
                    temp->let2='T';
                    varSearch(temp);
                }
                else if(temp->next->next->let=='~'&&temp->next->next->next->let=='T')
                {
                    temp->let2='F';
                    varSearch(temp);
                }
                cout<<"4."<<temp->let<<endl;
                temp=temp->next;
                temp=temp->next;
                pop();
                pop();
                cout<<"5."<<temp->let<<endl;
                if(IT(temp))
                {
                    cout<<"6."<<temp->let<<endl;
                    temp=head;
                    if(temp->let==';')
                    {
                        cout<<"7."<<temp->let<<endl;
                        pop();
                        if(VA(temp))
                        {
                            cout<<"8."<<temp->let<<endl;
                            return true;
                        }
                        else
                        {
                            return true;
                        }
                    }
                    else
                    {
                        return false;
                    }
                
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
}




bool list::IT(node *temp)
{
    if(temp==tail&&temp->let=='.')
    {
        pop();
        return true;
    }
    if(CT(temp))
    {
        if(IT_Tail(temp))
        {
            return true;
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
    
    
}

bool list::CT(node *temp)
{
    if(temp==tail&&temp->let=='.')
    {
        pop();
        return true;
    }
    if(L(temp))
    {
        if(CT_Tail(temp))
        {
            return true;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
    
}
bool list::IT_Tail(node* temp)
{
    if(temp==tail&&temp->let=='.')
    {
        pop();
        return true;
    }
    if(temp->let=='-'&& temp->next->let=='>')
    {
        temp=temp->next;
        temp=temp->next;
        pop();
        pop();
        if(CT(temp))
        {
            if(IT_Tail(temp))
            {
                return true;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool list::CT_Tail(node* temp)
{
    if(temp==tail&&temp->let=='.')
    {
        pop();
        return true;
    }
    if(temp->let=='V')
    {
        temp=temp->next;
        pop();
        if(L(temp))
        {
            if(CT_Tail(temp))
            {
                return true;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
        
    }
    else if(temp->let=='^')
    {
        temp=temp->next;
        pop();
        if(L(temp))
        {
            if(CT_Tail(temp))
            {
                
                return true;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return false;
        }
        
    }
    else
    {
        return false;
    }
    
}
bool list::L(node *temp)
{
    if(temp==tail&&temp->let=='.')
    {
        pop();
        return true;
    }
    if(A(temp))
    {
        return true;
    }
    else if(temp->let=='~')
    {
        result=evaluate(temp);
        temp=temp->next;
        pop();
        if(L(temp))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool list::A(node *temp)
{
    if(temp==tail&&temp->let=='.')
    {
        pop();
        return true;
    }
    if(temp->let=='T'||temp->let=='F')
    {
        result=evaluate(temp);
        temp=temp->next;
        pop();
        return true;
    }
    else if(islower(temp->let))
    {
        if(temp->let2!=0)
        {
        result=evaluate(temp);
        temp=temp->next;
        pop();
            return true;
        }
        else
        {
            cout<<"Error: Undefined Variable"<<endl;
            return false;
        }
    }
    else if(temp->let=='(')
    {
        result=evaluate(temp);
        temp=temp->next;
        pop();
        if(IT(temp))
        {
            if(temp->let==')')
            {
                temp=temp->next;
                pop();
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
void list::pop()
{
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
        return;
    }
    else{
        node* temp=head;
        head=head->next;
        delete(temp);
        temp=head;
        return;
    }
    
}
int x = 1;
bool list::evaluate(node *temp)
{
    
  if(x==1){
    if(temp->let!='~'){
        if((temp->let2=='F'||temp->let=='F')&&(temp->next->let=='^'||temp->next->let=='V')&&((temp->next->next->let=='F'||temp->next->next->let2=='F')||(temp->next->next->let=='~'&&((temp->next->next->next->let=='T'||temp->next->next->next->let2=='T')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='T')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='F')))
        {
            x++;
            return false;
            
            
        }
       else if((temp->let2=='T'||temp->let=='T')&&(temp->next->let=='^'||temp->next->let=='V')&&((temp->next->next->let=='T'||temp->next->next->let2=='T')||(temp->next->next->let=='~'&&((temp->next->next->next->let=='F'||temp->next->next->next->let2=='F')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='F')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='T')))
        {
            x++;
            return true;
        }
       else if(((temp->let2=='T'||temp->let=='T')||(temp->let2=='F'||temp->let=='F'))&&temp->next->let=='^'&&(((temp->next->next->let2=='T'||temp->next->next->let=='T')||((temp->next->next->let2=='F'||temp->next->next->let=='F'))||(((temp->next->next->let=='~'&&(temp->next->next->next->let=='F'||temp->next->next->next->let2=='F')))||(temp->next->next->let=='~'&&(temp->next->next->next->let=='T'||temp->next->next->next->let2=='T'))||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='F'))||(temp->next->next->let=='('&&PSearch(temp->next->next->next)=='T'))||((temp->next->next->next->let=='('&&PSearch(temp->next->next)=='F'))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='T')))
       {
           x++;
           return false;
       }
       else if((((temp->let2=='T'||temp->let=='T')||(temp->let2=='F'||temp->let=='F'))&&temp->next->let=='V'&&(((temp->next->next->let2=='T'||temp->next->next->let=='T')||(temp->next->next->let2=='F'||temp->next->next->let=='F'))||(((temp->next->next->let=='~'&&(temp->next->next->next->let=='F'||temp->next->next->next->let2=='F'))||((temp->next->next->let=='~'&&(((temp->next->next->next->let=='T'||temp->next->next->next->let2=='T'))||(temp->next->next->let=='('&&PSearch(temp->next->next->next)=='T')))||((temp->next->next->next->let=='('&&PSearch(temp->next->next)=='F')))))))||((temp->next->next->let=='('&&PSearch(temp->next->next)=='F'))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='T'))
       {
           x++;
           return true;
       }
       else
       {
           return false;
       }
    }
    else if(temp->let=='~')
    {
        temp=temp->next;
        if((temp->let2=='F'||temp->let=='F')&&temp->next->let=='^'&&((temp->next->next->let=='F'||temp->next->next->let2=='F')||(temp->next->next->let=='~'&&((temp->next->next->next->let=='T'||temp->next->next->next->let2=='T')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='T')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='F')))
        {
            x++;
            return false;
        }
        else if((temp->let2=='F'||temp->let=='F')&&temp->next->let=='V'&&((temp->next->next->let=='F'||temp->next->next->let2=='F'||(temp->next->next->let=='~'&&((temp->next->next->next->let=='T'||temp->next->next->next->let2=='T')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='F')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='T'))))
        {
            x++;
            return true;
        }
        else if((temp->let2=='T'||temp->let=='T')&&temp->next->let=='^'&&((temp->next->next->let=='T'||temp->next->next->let2=='T'||(temp->next->next->let=='~'&&((temp->next->next->next->let=='F'||temp->next->next->next->let2=='F')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='F')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='T'))))
        {
            x++;
            return false;
        }
        else if((temp->let2=='T'||temp->let=='T')&&temp->next->let=='V'&&((temp->next->next->let=='T'||temp->next->next->let2=='T'||(temp->next->next->let=='~'&&((temp->next->next->next->let=='F'||temp->next->next->next->let2=='F')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='F')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='T'))))
        {
            x++;
            return true;
        }
        else if((temp->let2=='F'||temp->let=='F')&&temp->next->let=='V'&&((temp->next->next->let=='F'||temp->next->next->let2=='F'||(temp->next->next->let=='~'&&((temp->next->next->next->let=='T'||temp->next->next->next->let2=='F')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='T')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='F'))))
        {
            x++;
            return true;
        }
        else if((temp->let2=='T'||temp->let=='T')&&temp->next->let=='V'&&((temp->next->next->let=='F'||temp->next->next->let2=='F'||(temp->next->next->let=='~'&&((temp->next->next->next->let=='T'||temp->next->next->next->let2=='T')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='T')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='F'))))
        {
            x++;
            return false;
        }
        else if((temp->let2=='F'||temp->let=='F')&&temp->next->let=='^'&&((temp->next->next->let=='T'||temp->next->next->let2=='T'||(temp->next->next->let=='~'&&((temp->next->next->next->let=='F'||temp->next->next->next->let2=='F')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='F')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='T'))))
        {
            x++;
            return true;
        }
        else if((temp->let2=='T'||temp->let=='T')&&temp->next->let=='^'&&((temp->next->next->let=='F'||temp->next->next->let2=='F'||(temp->next->next->let=='~'&&((temp->next->next->next->let=='T'||temp->next->next->next->let2=='T')||(temp->next->next->next->let=='('&&PSearch(temp->next->next->next)=='T')))||(temp->next->next->let=='('&&PSearch(temp->next->next)=='F'))))
        {
            x++;
            return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    
  }
  else if(z==1)
  {
    if((temp->let=='^'||temp->let=='V')&&(temp->next->let=='('))
    {
        x=1;
        return PSearch(temp);
    }
    else
    {
        return false;
    }
  }
else
{
    return false;
}
}

void list::varSearch(node* temp)
{
    node* temp2= temp->next;
    while(temp2!=tail)
    {
        if(temp->let==temp2->let&&temp->let2!=0)
        {
            temp->let2=temp2->let2;
        }
        temp2=temp2->next;
        
    }
    
}

char list::PSearch(node* temp)
{

    z=1;
    while(temp!=tail)
    {
       
        temp=temp->next;
        if(evaluate(temp))
        {
            return 'T';
        }
        else
        {
            return 'F';
        }
            
        }
    z++;
    
    return 0;
}
int main()
{
    
    list test;
    
    test.command();
    
    test.B();
    if(result){
        cout<<"The result is true."<<endl;}
    else
    {
        cout<<"The result is false."<<endl;
    }
    return 0;
}

