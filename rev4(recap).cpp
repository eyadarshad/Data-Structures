// #include <iostream>
// using namespace std;
// #include <stdexcept>
//  class node {
//     private:
//     int elem;
//     node* next_node;
//     public:
//     node() : elem(0), next_node(nullptr){}
//     node(int val, node* next=nullptr) : elem(val), next_node(next){}
//     int retrieve(){
//         return elem;
//     }
//     node* next(){
//         return next_node;
//     }
//     void set_next(node* next){
//         next_node = next;
//     }
//  };
//  class stack{
//     private:
//     node* top;
//     int sz;
//     public:
//     stack():top(nullptr), sz(0){}
//     bool empty(){
//         return(top==nullptr);
//     }
//     void push_top(int val){
//         node* newN= new node(val);
//         newN->set_next(top);
//         top = newN;
//         ++sz;
//     }
//     int pop(){
//         if(empty()){
//             return 0;
//         }
//         int val = top->retrieve();
//         node* temp = top;
//         top = top->next();
//         delete temp;
//         --sz;
//     }

//  };
#include <iostream>
using namespace std;
class stack{
    private:
    int capacity;
    int *arr;
    int sz;
    public:
    stack(int n=10){
        capacity =n;
        sz=0;
        if(capacity<1){
            capacity=1;
        }
        arr = new int[capacity];
    }
    ~stack(){
        delete[] arr;
    }

    bool empty(){
        return (sz==0);
    }
    bool full(){
        return(sz==capacity);
    }
    void push(int val){
        if(full()){
            double_capacity();
        }
        arr[sz]=val;
        ++sz;
    }
    int pop(){
        if(empty()){
            return -1;
        }
        --sz;
        return arr[sz];
    }
    void double_capacity(){
        int* temp = new int[capacity*2];
        for(int i =0; i<capacity; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr= temp;
        capacity *= 2;
    }
    int top(){
        if(empty()){
            return -1;
        }
        return arr[sz-1];
    }
    
};