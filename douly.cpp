#include <iostream>
using namespace std;
#include <stdexcept>

class node{
    private:
    int elem;
    node* next_node;
    node* prev_node;
    public:
    node(): elem(0), next_node(nullptr), prev_node(nullptr){}
    node(int val, node* next=nullptr, node* prev=nullptr): elem(val), next_node(next), prev_node(prev){}
    int retrieve(){
        return elem;
    }
    node* next(){
        return next_node;
    }
    node* prev(){
        return prev_node;
    }
    void set_next(node* next){
        next_node=next;
    }
    void set_prev(node* prev){
        prev_node=prev;
    }
    void set_elem(int val){
        elem = val;
    }
};
class list{
    private:
    node* head;
    node* tail;
    int sz;
    public:
    list(): head(nullptr), tail(nullptr), sz(0){}
    bool empty() const{
        return(head==nullptr);
    }
    int size() const{
        return sz;
    }
    void push_front(int val){
        node* newNode = new node(val);
        if(empty()){
            head = tail = newNode;
        }
        else{            
            newNode->set_next(head);
            head->set_prev(newNode);
            head=newNode;
        }
        ++sz;
    }
    void push_back(int val){
        node* newNode = new node(val);
        if(empty()){
            head = tail = newNode;
        }
        else{
            newNode->set_next(nullptr);
            newNode->set_prev(tail);
            tail->set_next(newNode);
            tail = newNode;
        }
        ++sz;
    }
    int pop_front(){
        if(empty()){
            throw runtime_error("list is empty");
        }
        else{
            int val = head->retrieve();
            if(head == tail){    
                head = tail = nullptr;
                return val;
            }
            node* temp = head;
            head = head->next();
            head->set_prev(nullptr);
            delete temp;
            --sz;
            return val;
        }
    }
    int pop_back(){
        if(empty()){
            throw runtime_error("list is empty");
        }
        else{
            int val = tail->retrieve();
            if(head == tail){
                head = tail = nullptr;
                return val;
            }
            else{
                node* temp = tail;
                tail = tail->prev();
                tail->set_next(nullptr);
                delete temp;
                --sz;
                return val;
            }
        }
    }
    void display_forward(){
        for(node* ptr = head; ptr!=nullptr; ptr =ptr->next()){
            cout<< "Doubly Linked List : "<< ptr<< "  ";
        }
        cout<<endl;
    }
    void display_backward(){
        for(node* ptr = tail; ptr!=nullptr; ptr =ptr->prev()){
            cout<< "Doubly Linked List : "<< ptr<< "  ";
        }
        cout<<endl;
    }
    int count(int val){
        int count = 0;
        for(node* ptr = tail; ptr!=nullptr; ptr =ptr->prev()){
            if(ptr->retrieve()==val){
                ++count;
            }
        }
        return count;
    }
    void insert_at(int val, int pos){
        if(empty()||pos<=0){
            push_front(val);
            return;
        }
        if(sz<=pos){
            push_back(val);
            return;
        }
        node *newNode = new node (val);
        node* temp = head;
        int index = 0;
        while(temp->next()!=nullptr && index<pos-1 ){
            temp= temp->next();
            ++index;
        }
        temp->next()->set_prev(newNode);
        newNode->set_next(temp->next());
        temp->set_next(newNode);
        newNode->set_prev(temp);
        ++sz;
    }
    ~list(){
        while(!empty()){
            pop_front();
        }
    }
    void clear(){
        node* ptr = head;
        while(ptr->next()!=nullptr)
        {
            node* temp = ptr;
            ptr =ptr->next();
            delete temp;
        }
        head = tail = nullptr;    
        sz=0;   
    }
    int erase(int val){
        if(empty()){
            throw runtime_error("list is empty");
        }
        node* temp = head;
        int count =0;
        while(temp->next()!=nullptr)
        {
            if(temp->retrieve()== val){
                node* toDel= temp;
                if(temp==head){
                    head = head->next();
                    if(head->next()!=nullptr){
                        head->set_prev(nullptr);
                    }
                }
                else if(temp==tail){
                    tail= tail->prev();
                    if(tail->prev()!= nullptr){
                        tail->set_next(nullptr);
                    }
                }
                else{
                    temp->prev()->set_next(temp->next());
                    temp->next()->set_prev(temp->prev());
                }
                temp= temp->next();
                delete toDel;
                --sz;
                ++count;
            }
            else{
                temp= temp->next();
            }
            
        }
        return count;
    }
    
};