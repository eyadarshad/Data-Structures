#include <iostream>
using namespace std;
#include <stdexcept>
 class node {
    private:
    int elem;
    node* next_node;
    public:
    node() : elem(0), next_node(nullptr){}
    node(int val, node* next=nullptr) : elem(val), next_node(next){}
    int retrieve(){
        return elem;
    }
    node* next(){
        return next_node;
    }
    void set_next(node* next){
        next_node = next;
    }
 };
 class queue{
    private:
    node* front;
    node* last;
    int sz=0;
    public:
    queue():front(nullptr), last(nullptr),sz(0){}
    bool empty(){
        return(front==nullptr);
    }
    void push_end(int val){
        node* newN = new node(val);
        if(empty()){
            front = last = newN;
            return;
        }
        last->set_next(newN);
        last = newN;
        ++sz;
    }
    int dequeue(){
        if(empty()){
            return 0;
        }
        int val = front->retrieve();
        node* temp = front;
        front=front->next();
        delete temp;
        --sz;

    }
 };