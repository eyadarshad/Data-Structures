#include <iostream>
using namespace std;
 class node{
    private:
    int elem;
    node* next_node;
    public:
    node():elem(0),next_node(nullptr){}
    node(int val, node* next=nullptr):elem(val), next_node(next){}
    int retrieve(){
        return elem;
    }
    void set_next(node* next){next_node=next;}
    node* next(){
        return next_node;
    }
    
 };
 class circular{
    private:
    node* head;
    node* tail;
    int sz;
    public:
    circular():head(nullptr), tail(nullptr), sz(0){}
    bool empty(){
        return (head==nullptr);
    }
    void push_front(int val){
        node* newN = new node(val);
        if(empty()){
            head = tail = newN;
            tail->set_next(newN);
            ++sz;
            return;
        }
        newN->set_next(head);
        
        head = newN;

        tail->set_next(newN);
        ++sz;

    }
    void push_back(int val){
        node* newN = new node(val);
        if(empty()){
            head = tail = newN;
            tail->set_next(newN);
            ++sz;
            return;
        }
        tail->set_next(newN);
        newN->set_next(head);
        tail = newN;
        ++sz;
    }
    int pop_front(){
        if(empty()){
            return;
        }
        int val = head->retrieve();
        if(head==tail){
            delete head;
            head = tail =nullptr;
            --sz;
            return val;
        }
        node* temp = head;
        head = head ->next();
        delete temp;
        tail->set_next(head);
        --sz;
        return val;
    }
    int pop_end(){
        if(empty()){
            return;
        }
        int val= tail->retrieve();
        if(head == tail){
            delete head;
            head = tail = nullptr;
            --sz;
            return val;
        }
        node* temp = head;
        while(temp->next()!= tail){
            temp =temp->next();
        }
        temp->set_next(head);
        delete tail;
        tail = temp;
        --sz;
        return val;
        
    }
    void display(){
        if(empty()){
            return;
        }
        node* temp = head;
        do{
            cout<< temp->retrieve() << "  ";
            temp = temp->next();

        }while(temp!=head);

    }
 };
