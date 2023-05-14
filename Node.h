//
// Created by admin on 25/11/2022.
//

#ifndef WET1_NODE_H
#define WET1_NODE_H


#include <iostream>

class Failure : public std::exception{};

template <class T>
class Node{
public:

    T* value;
    Node* parent;
    
    Node* right_son;
    Node* left_son;
    int height;
    int bf;

    //std::shared_ptr<Node<T>> two_sided; // double pointer from node to node (team-team // player-player)

public:
   // explicit Node(T& value) : value(value), parent(nullptr), right_son(nullptr), left_son(nullptr), height(0),bf(0)  {}
    //Node()=default; 
    explicit Node(): value(nullptr), parent(nullptr), right_son(nullptr), left_son(nullptr), height(0),bf(0)  {}
    ~Node(){
        delete value;
        value=nullptr;
    }
    Node(const Node& value) = delete;
    
    Node<T> *createNode(T val) {
        Node<T> *node = new Node<T>;
        /*if (node==nullptr)
        {
            return nullptr;
        }*/
        
        node->value = new T(val);
        /*if(node->value==nullptr)
        {
            return nullptr
        }*/
        node->height = 0;
        node->left_son = nullptr;
        node->right_son = nullptr;
        node->parent = nullptr;
        return node;
    }

    T& getValue()  {
        return *(this->value);
    }
    void setValue( T& new_val){
        if(this== nullptr)
            return;
        this->value=new_val;
    }
/*
    Node<T>* getRightSon()  {
        if(this==nullptr)
            return nullptr;
        return this->right_son;
    }
    void setRightSon( Node<T>*& new_right_son){ //should it be const?
        if(this== nullptr)
            return;
        this->right_son=new_right_son;
    }

    Node<T>* getLeftSon()  {
        if(this==nullptr)
            return nullptr;
        return this->left_son;
    }
    void setLeftSon( Node<T>*& new_left_son){ //should it be const?
        if(this== nullptr)
            return;
        this->left_son=new_left_son;
    }

    Node<T>* getParent()  {
        if(this==nullptr)
            return nullptr;
        return this->parent;
    }
    void setParent( Node<T>& p){ //should it be const?
        if(this== nullptr)
            return;
        this->parent=p;
    }
*/
    int getHeight()  {
        if(this==nullptr)
            return -1;
        return this->height;
    }
    /*void setHeight(const int new_h){
        if(this== nullptr)
            return;
        this->height=new_h;
    }*/

    void updateHeight() {
        if (this == nullptr) {
            return;
        }
        int rightH, leftH;
        //calc right son height
        if (this->right_son == nullptr) {
            rightH = -1;
        } else {
            rightH = right_son->height;
        }
        //calc left son height
        if (this->left_son == nullptr) {
            leftH = -1;
        } else {
            leftH = left_son->height;
        }
        //updates the height
        if (rightH > leftH) {
            this->height = rightH + 1;
        } else {
            this->height = leftH + 1;
        }
    }

    int getBF() const {
        if(this==nullptr)
            return -100;
        return this->bf;
    }
    void setBF(const int new_bf){
        if(this== nullptr)
            return;
        this->bf=new_bf;
    }

    bool isValidBF() {
        return (this->getBF() < 2 && this->getBF() > -2);
    }

    
    void calcBF() {
        if (this == nullptr){
            return;
        }
    
        if (this->left_son && this->right_son){
            bf= (left_son->height - right_son->height);
            return;
        }
            
        if (this->left_son && this->right_son == nullptr)
        {
            bf= this->left_son->height +1 ;
            return;
        }
            
        if (this->left_son == nullptr && this->right_son)
        {
            bf = -1 - (this->right_son->height);
            return;
        }
        bf= 0; 
    }
    Node &operator=(const Node &node) {
        if (this == &node) {
            return *this;
        }
        value= node.value;
        height = node.height;
        left_son = node.left_son;
        right_son = node->right_son;
        parent = node->parent;
        bf =node->bf;

        return *this;
    }
    bool operator!=(Node &node) {
        if (this == &node) {
            return true;
        }
        return false;
    }



    bool isLeftSon() {
        if (parent == nullptr) {
            return false;
        }
        return parent->left_son == this;
    }

    bool isRightSon() {
        if (parent == nullptr) {
            return false;
        }
        return parent->right_son == this;
    }



};

































#endif //WET1_DS_WINTER_NODE_H
