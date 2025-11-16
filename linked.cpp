#include <iostream>
using namespace std;
class node {
    private :
    int val;
    node* next_node;
    public:
    node () : val (0), next_node (nullptr)  {

    }
    node ( int e, node* next) : val(e), next_node(next){

    }
    int retrieve() const{
        return val;
    }
    node* next() const {
        return next_node;
    }

    void set_next(node* i){
        next_node = i;
    }

};
class List{
    private :
    node *list_head;
    public:

    List () : list_head(nullptr){

    }
    
    //Mutators
    void push_front(int n){
        list_head = new node(n,head());
        
    }
    void display(){
        for(node* ptr = head();ptr != nullptr; ptr = ptr->next()){
            cout<<ptr->retrieve()<< " ";
        }
    }
    void push_end(int value){
            node* newN= new node(value, nullptr);
            if(empty()){
            list_head = newN;
            return;
            }
            node* temp = list_head;
            while(temp->next() != nullptr)
            {
                temp = temp->next();
            } 
            temp-> set_next(newN) ;    
    }
   
    void pop_front(){
        node* old_head=head();
        list_head=old_head->next();
        delete old_head;
        
    }
    int pop_end(){
           if(!empty){
            if(list_head->next()==nullptr){
                delete list_head;
                list_head=nullptr;
            }
            else{
                node* temp = list_head;
                while(temp->next()->next() != nullptr){
                    temp = temp->next();
                }
                delete temp->next();
                temp->set_next(nullptr);
            }
           }
    }
    int erase(int val){
        int count = 0;
        if(list_head!=nullptr && list_head->retrieve()==val){
            list_head = list_head->next();
            ++count;
        }
        node* current = head();
        while(current!=nullptr && current->next() != nullptr ){
            if(current->next()->retrieve()==val){
                node* temp = current->next();
                current->set_next(temp->next());
                delete temp;
                ++count;
            }
            else{
                current = current->next();
            }
        }

    }

    //Accessors
    int size(){
        int count=0;
        for(node *ptr = head(); ptr != nullptr;ptr->next() ){
            ptr->retrieve();
            count++;
        }
        return count;
    }
    bool empty()const{

        return (list_head == nullptr);
    }
    int front() const{
        return head()->retrieve();
    }
    int end() const{
        node* temp = list_head;
        while(temp->next()!= nullptr){
            temp = temp->next();
        }
        return temp->retrieve();
    }
    node* head ()const{
        return list_head;
    }
    int count(int x){
        int count=0;
        for(node* ptr = head();ptr!=nullptr; ptr->next() ){
            if(ptr->retrieve()== x){
                ++count;
            }
            
        }
        return count;
    }

    
};
int main() {
    // node a(12,nullptr);
    List ls;
    ls.push_front(0);
    ls.push_front(14);
    ls.push_front(16);
    ls.push_end(23);
    ls.pop_front();
    ls.display();
    // int size;
    // size = ls.size();
    // cout<<"\n"<< size;
}