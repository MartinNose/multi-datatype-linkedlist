#include <list.h>

void list::DeleteFirst() {
    if (head != tail) {
        head->setNext(head->next()->next());
    } else {
        cout << "The list has been already empty" << endl;
    }
}

void list::DeleteLast() {
    if (head != tail) {
        node *p = head->next();
        while(p->next() != tail) {
            p = p->next();
        }
        tail = p;
        delete p->next();
        p->setNext(nullptr);
    } else {
        cout << "The list has been already empty" << endl;
    }
}

void list::Reverse() {
    if (head == tail) {
        cout<<"list is empty" <<endl;
        return;
    }
    node *temp = nullptr;
    tail = head->next();
    while(true) {
        node *nextNode = head->next()->next();
        head->next()->setNext(temp);
        temp = head->next();
        if (nextNode == nullptr) break;
        head->setNext(nextNode);
    }
}

void list::Merge(list &l) {
    if (head==tail) {
        head = l.Head();
        tail = l.Tail();
        return;
    }
    tail->setNext(l.Head()->next());
    tail = l.Tail();
}

void list::Destroy() {
    if (head == tail) {
        cout<<"list is empty" <<endl;
        return;
    }
    
    while (head->next() != nullptr) {
        node *temp = head->next();
        head->setNext(temp->next());
        delete temp;
    }
}

void list::print() {
    node *p = head->next();
    while (p != nullptr) {
        p->printNode();
        if (p == tail) cout<<"\n";
        else cout<<" --> ";
        p = p->next();
    }
}