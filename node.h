#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;

enum nodeType {INT, STRING, DOUBLE};

//定义node元素基类，使用该基类指针来储存不同类型的数据
class baseData {
public:
    virtual ~baseData() {};
};

//定义baseData的模版派生类
template <typename T>
class data: public baseData {
public:
    T value;
    data():value(0) {}
    data(const T& _value): value(_value) {}
    ~data() {}
};

//定义节点类，包含一个数据的类型、元素、和一个指向下个地址的node类型指针
class node {
    enum nodeType type;
    baseData *pdata;
    node* nextNode;
public:
    node():nextNode(nullptr),type(INT),pdata(nullptr) {} 
    //实现一个模版类构造函数
    template <typename T>
    node(const T& _value): pdata(new data<T>(_value)){};

    //返回当前节点数据
    template <typename T>
    T& getData();

    //设置节点值
    template <typename T>
    void setData(const T& _value) {pdata = data<T>(_value);}

    //返回下个节点地址
    node* next() const {return nextNode;}
    void setNext(node *_nextNode) {nextNode = _nextNode;}

    //返回当前接待类型
    enum nodeType getType() const {return type;}
    void setType(nodeType _type) {type = _type;}
};

//模版类实现节点值获取。
template <typename T>
T& node::getData() {
    auto pderived = dynamic_cast<data<T>*>(pdata);
    if(nullptr == pderived){
        throw std::invalid_argument("The type to dynamic_cast is wrong");
    }
    return pderived->value;
}
#endif //_NODE_H_