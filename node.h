#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;

enum nodeType {INT, STRING, DOUBLE};

class baseData {
public:
    virtual ~baseData() {};
};

template <typename T>
class data: public baseData {
public:
    T value;
    data():value(0) {}
    data(const T& _value): value(_value) {}
    ~data() {}
};

class node {
    enum nodeType type;
    baseData *pdata;
    node* nextNode;
public:
    node():nextNode(nullptr),type(INT),pdata(nullptr) {} 
    template <typename T>
    node(const T& _value): pdata(new data<T>(_value)){};

    template <typename T>
    T& getData();

    template <typename T>
    void setData(const T& _value) {pdata = data<T>(_value);}

    node* next() const {return nextNode;}
    void setNext(node *_nextNode) {nextNode = _nextNode;}

    enum nodeType getType() const {return type;}
    void setType(nodeType _type) {type = _type;}
};

template <typename T>
T& node::getData() {
    auto pderived = dynamic_cast<data<T>*>(pdata);
    if(nullptr == pderived){
        throw std::invalid_argument("The type to dynamic_cast is wrong");
    }
    return pderived->value;
}
#endif //_NODE_H_