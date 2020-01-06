#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include <string>
#include <node.h>
using namespace std;

class list {
    node *head;
    node *tail;
public:
    list():head(new node()){
        tail = head;
    };
    node* Head() const {return head;}
    node* Tail() const {return tail;}
    
    template <typename N>
    void Insert(N n, enum nodeType _type);

    void DeleteFirst();
    void DeleteLast();

    template <typename N>
    void Delete(bool (*cond)(N), enum nodeType _type) ;

    void Reverse();
    void Destroy();
    void Merge(list &l);
    void print();
};

template <typename N>
void list::Insert(N n, enum nodeType _type) {
    node *newNode = new node(n);
    newNode->setType(_type);
    if (head == tail) {
        head->setNext(newNode);
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <typename N>
void list::Delete(bool (*cond)(N), enum nodeType _type) {
    node *p = head;
    N t;
    while(p->next() != nullptr) {
        if (p->next()->getType() == _type && cond(p->next()->getData<N>())) {
            node *temp = p->next();
            p->setNext(temp->next());
            delete temp;
        } else {
            p = p->next();
        }
    }
}
#endif //_LIST_H_