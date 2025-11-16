#include <iostream>
using namespace std;
class node{
    private:
    int elem;
    node* next_node;
    node* prev_node;
    public:
    node():elem(0),next_node(nullptr),prev_node(nullptr){}
    node(int val, node* next=nullptr , node* prev=nullptr): elem(val), next_node(next), prev_node(prev){}
    int retrieve(){
        return elem;
    }
    node* next() const{
        return next_node;
    }
    node* prev() const{
        return prev_node;
    }
    void set_next(node* next){
        next_node=next;
    }
    void set_prev(node* prev){
        prev_node=prev;
    }
};
class list{
    private:
    node* head;
    node* tail;
    int sz;
    public:
    list():head(nullptr), tail(nullptr), sz(0){}
    list(int size, node* h, node* t):sz(size), head(h), tail(t){}
    bool empty(){
        return (head==nullptr);
    }
    void push_front(int val){
        node* newN = new   node(val);
        if(empty()){
            head = tail = newN;
            ++sz;
            return;
        }
        head->set_prev(newN);
        newN->set_next(head);
        newN->set_prev(nullptr);
        head = newN;
        ++sz;
    }
    void push_back(int val){
        node* newN= new node(val);
        if(empty()){
            head = tail = newN;
            ++sz;
            return;
        }
        tail->set_next(newN);
        newN->set_prev(tail);
        newN->set_next(nullptr);
        tail = newN;
        ++sz;
    }
    int pop_front(){
        if(empty()){
            return;
        }
        if(head == tail){
            head = tail = nullptr;
            --sz;
            return;
        }
        int val= head->retrieve();
        node* temp = head;
        temp->next()->set_prev(nullptr);
        head=head->next();
        temp->set_next(nullptr);
        delete temp;
        --sz;
        return val;
    }
    int pop_back(){
        if(empty()){
            return;
        }
        if(head == tail){
            head = tail = nullptr;
            --sz;
            return;
        }
        int val = tail->retrieve();
        node* temp = tail;
        temp->prev()->set_next(nullptr);
        tail=temp->prev();
        temp->set_prev(nullptr);
        delete temp;
        --sz;
        return val;
    }
    int erase(int val){
        if(empty()){
            return;
        }
        node* temp = head;
        int count =0;
        while(temp->next()!=nullptr){
            if(temp->retrieve()==val){
                node* cur= head;
                
                if(head==temp){
                    head = head->next();
                    if(head!=nullptr){
                        head->set_prev(nullptr);
                    }  
                }
                else if(tail==temp){
                    tail = tail->prev();
                    if(tail->prev()!=nullptr){
                        tail->set_next(nullptr);
                    }
                }
                else{
                    temp->prev() ->set_next(temp->next());
                    temp->next() ->set_prev(temp->prev());
                }
                temp= temp->next();
                delete cur;
                --sz;
                ++count;

            }
            else{
                temp = temp->next();
            }

        }
        return count;
    }
    void clear(){
        if(empty()){
            return;
        }
        node* temp =head;
        while(temp->next()!=nullptr){
            node* cur = temp;
            temp=temp->next();
            delete cur;
        }
        sz=0;
        head = tail =nullptr;
    }
    void insert_at(int val, int pos){
        if(pos<=0){
            push_front(val);
            return ;
        }
        if(pos>=sz){
            push_back(val);
            return ;
        }
        node* temp =head;
        int index=0;
        while((temp != nullptr)&& index<pos-1){
            temp = temp->next();
            index++;
        }
        node* newN = new node(val);
        temp->next()->set_prev(newN);
        newN->set_next(temp->next());
        temp->set_next(newN);
        newN->set_prev(temp);
        ++sz;
        
    }
    int pop_at (int pos){
        if(empty()){
            return;
        }
        if(pos<0||pos>=sz){
            return;
        }
        if(pos==0){
            int val = head->retrieve();
            if(head==tail){
                delete head;
                head = tail = nullptr;
                --sz;
                return val;
            }
            else{
                node* temp =head;
                head=head->next();
                head->set_prev(nullptr);
                delete temp;
                --sz;
                return val;
            }
        }
        node* temp = head;
        
        int index = 0;
        for(int i =0 ; i<pos; ++i){
            temp = temp->next();
        }
        int val = temp->retrieve();
        if(temp == tail){
            tail = tail->prev();
            tail->set_next(nullptr);
            delete temp;
            --sz;
            return val;
        }
        else{
            temp->next()->set_prev(temp->prev());
            temp->prev()->set_next(temp->next());
            --sz;
            return val;
        }

    }
    void insert_mid(int val){
        node *newN = new node(val);
        if(empty()){
            head = tail = newN;
            ++sz;
            return;
        }
        int mid = sz/2;
        node* temp = head;
        for(int i =0; i<mid;++i){
            temp =temp->next();
        }
        newN->set_prev(temp);
        temp->next()->set_prev(newN);
        if(temp->prev()!= nullptr){
            temp->prev()->set_next(newN);
        }
        else{
            head=newN;

        }
        newN->set_next(temp);
        ++sz;

    }
    int pop_mid(){
        if(empty()){
            return;
        }
        if(head == tail){
            int val = head->retrieve();
            delete head;
            head = tail = nullptr;
            sz=0;
            return val;
        }
        int mid = (sz-1)/2;
        node* temp = head;
        for(int i=0; i<mid;++i ){
            temp = temp->next();
        }
        if(temp == head ){
            int val = temp->retrieve();
            head = head ->next();
            head->set_prev(nullptr);
            delete temp;
            --sz;
            return val;
        }
        if(temp==tail){
            int val = temp->retrieve();
            tail = tail->prev();
            tail->set_next(nullptr);
            delete temp;
            --sz;
            return val;
        }
        else{
            int val = temp->retrieve();
            temp->prev()->set_next(temp->next());
            temp->next()->set_prev(temp->prev());
            delete temp;
            --sz;
            return val;
        }
            
        }
    }
};
