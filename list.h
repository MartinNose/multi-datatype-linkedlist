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
    //构造函数。
    list():head(new node()){
        tail = head;
    };
    //返回头指针
    node* Head() const {return head;}
    //返回尾指针
    node* Tail() const {return tail;}
    
    //插入操作
    template <typename N>
    void Insert(N n, enum nodeType _type);

    //删除第一个节点
    void DeleteFirst();
    //删除最后一个节点
    void DeleteLast();

    //模版类实现符合特定条件的节点删除。
    template <typename N>
    void Delete(bool (*cond)(N), enum nodeType _type) ;

    //实现链表逆序
    void Reverse();
    //实现链表清空
    void Destroy();
    //实现链表合并
    void Merge(list &l);
    //链表输出
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