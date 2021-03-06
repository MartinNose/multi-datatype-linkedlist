#include <iostream>
#include "list.h"
using namespace std;

inline bool isEqual3(int c) {
    return c == 3;
}

inline void line() {
    cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
}

void ConstructTestList(list& M){
    M.Insert((string)"MListMember1", STRING);
    M.Insert(2,INT);
    M.Insert(3,INT);
    M.Insert(3.02, DOUBLE);
    M.Insert((string)"MListMember4", STRING);
    cout<<"List for testing is constructed as follow"<<endl;
    line();
    M.print();
    line();
}

void ConstructMainList(list& L) {
    L.Insert(1, INT);
    L.Insert(2, INT);
    L.Insert(3, INT);
    L.Insert(3, INT);
    L.Insert(2.9, DOUBLE);
    L.Insert(3, INT);
    L.Insert((string)"Test!@#String123", STRING);
    L.Insert((string)"HelloWorld", STRING);
     cout<<"Original LinkedList member:\n";
    cout<<"1 --> 2 --> 3 --> 3 --> 2.9 --> 3 --> Test!@#String123 --> HelloWorld"<<endl;
}

int main() {
    line();
    cout<<"Linked List Test\n";
    line();

    list L;
    ConstructMainList(L);
    line();

    cout<<"list::print() output:"<<endl;
    L.print();
    line();

    cout<<"list::Reverse() output:"<<endl;
    L.Reverse();
    L.print();
    cout<<"Recovering to origin List"<<endl;
    L.Reverse();
    line();

    cout<<"list::DeleteFirst() output:"<<endl;
    L.DeleteFirst();
    L.print();
    line();

    cout<<"list::DeleteLast() output:"<<endl;
    L.DeleteLast();
    L.print();
    line();

    cout<<"Unmerged List M's initializing"<<endl;
    list M;
    ConstructTestList(M);

    cout<<"list::Merge() output:"<<endl;
    L.Merge(M);
    L.print();
    line();

    cout<<"Testing list::Delete<T>(bool (*cond)(T), enum nodeType)"<<endl;
    cout<<"Passing bool isEqual3(int) to this method, delete all nodes that has a int node with value 3 \nOutput:"<<endl;
    L.Delete<int>(isEqual3, INT);
    L.print();
    line();

    cout<<"done"<<endl;
    line();
}