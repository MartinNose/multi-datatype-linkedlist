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

void list::Destroy() {
    if (head == tail) {
        cout<<"list is empty" <<endl;
        return;
    }

    while(true) {
        node *nextNode = head->next()->next();
        delete head->next();
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
    while (head->next() != nullptr) {
        node *temp = head->next();
        head->setNext(temp->next());
        delete temp;
    }
}

void list::print() {
    node *p = head->next();
    while (p != nullptr) {
        switch(p->getType()) {
            case INT:cout<<p->getData<int>();break;
            case STRING:cout<<p->getData<string>();break;
            case DOUBLE:cout<<p->getData<double>();break;
        }
        if (p == tail) cout<<"\n";
        else cout<<" --> ";
        p = p->next();
    }
}