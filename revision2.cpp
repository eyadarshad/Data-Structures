// #include <iostream>
// using namespace std;
// class node{
//     private:
//     node* next_node;
//     node* prev_node;
//     int elem;
//     public:
//     node(): elem(0),prev_node(nullptr), next_node(nullptr){}
//     node(int val, node* prev=nullptr, node* next=nullptr):next_node(next), elem(val), prev_node(prev){}
//     int retrieve(){
//         return elem;
//     }
//     node* prev(){
//         return prev_node;
//     }
//     node* next(){
//         return next_node;
//     }
//     void set_next(node* next){
//         next_node=next;
//     }
//     void set_prev(node* prev){
//         prev_node=prev;
//     }
// };
// class list{
//     private:
//     node* head;
//     node* tail;
//     int sz;
//     public:
//     list():head(nullptr), tail(nullptr), sz(0){}
//     bool empty(){
//         return(head==nullptr);
//     }
//     void push_front(int val){
//         node* newN= new node(val);
//         if(empty()){
//             head = tail = newN;
//             ++sz;
//         }
//         else{
//             node* temp = head;
//             newN->set_next(temp);
//             temp->set_prev(newN);
//             head = newN;
//             head->set_prev(nullptr);
//             ++sz;
//         }
//     }
//     void push_back(int val){
//         node* newN = new node(val);
//         if(empty()){
//             head = tail = newN;
//             ++sz;
//         }
//         else{
//             node* temp= tail;
//             tail->set_next(newN);
//             newN->set_prev(tail);
//             tail=newN;
//             tail->set_next(nullptr);
//             ++sz;
//         }
//     }
//     void push_mid(int val){
//         node* newN = new node(val);
//         if (empty()){
//             head = tail = newN;
//             ++sz;
//         }
//         else{
            
//             int mid= (sz/2);
//             if(mid==0){
//                 push_front(val);
//             }
//             else if(mid ==sz){
//                 push_back(val);
//             }
//             int index = 0;
//             node* temp = head;

//             while((temp->next()!=nullptr) && index < mid-1){
//                 temp = temp -> next();
//                 ++index;
//             }
//             node* current = temp->next();
//             current->set_prev(newN);
//             temp->set_next(newN);
//             newN->set_next(current);
//             newN->set_prev(temp);
//             ++sz;
//         }
//     }
//     void insert_at(int pos, int val){
//         node* newN = new node(val);
//         if(empty()){
//             pos=0;
//             head=tail=newN;
//             ++sz;
//         }
//         else{
//             if((pos<=0)&& (!empty())){
//                 pos=0;
//                 push_front(val);
//                 return;
//             }
//             if(pos>=sz){
//                 newN->set_prev(tail);
//                 tail->set_next(newN);
//                 tail = newN;
//                 tail->set_next(nullptr);
//                 ++sz;
//                 return;
//             }
//             int index=0;
//             node* temp = head;
//             while((temp->next()!=nullptr)&&index<pos-1){
//                 temp = temp->next();
//                 ++index;
//             }
//             node* current = temp->next();
//             current->set_prev(newN);
//             temp->set_next(newN);
//             newN->set_next(current);
//             newN->set_prev(temp);
//             ++sz;
//         }
//     }
//     int pop_front(){
//         if(empty()){
//             return 0;
//         }
//         if(head ==tail){
//             head = tail = nullptr;
//             sz=0;
//             return 0;
//         }
//         int val= head ->retrieve();
//         node* temp = head;
//         head = head ->next();
//         head->set_prev(nullptr);
//         delete temp;
//         --sz;
//         return val;
//     }
//     int pop_end(){
//         if(empty()){
//             return 0;
//         }
//         if(head == tail){
//             int val= tail ->retrieve();
//             head = tail = nullptr;
//             sz=0;
//             return val;
//         }
//         else{
//             int val= tail ->retrieve();
//             node* temp = tail;
//             tail = tail ->prev();
//             tail->set_next(nullptr);
//             delete temp;
//             --sz;
//             return val;

//         }
//     }
//     int pop_mid(){
//         if (empty()){
//             return 0;
//         }
//         if(head == tail){
//             int val= tail ->retrieve();
//             head = tail = nullptr;
//             sz=0;
//             return val;
//         }
//         else{
//         node* temp=head;
//         int mid = sz/2;
//         if(mid==0){
//             pop_front();
//         }
//         else if(mid==sz-1){
//             pop_end();
//         }
//         else{
//         int index =0;
//         while(temp->next()!=nullptr && index<mid-1){
//             temp= temp->next();
//             ++index;
//         }
//         int val = temp->next()->retrieve();
//         node* current = temp->next();
//         current->next()->set_prev(temp);
//         temp->set_next(current->next());
//         delete current;
//         --sz;
//         return val;
//         }
//     }
//     }
//     int pop_at(int pos){
//         if(empty()){
//             return 0;
//         }
//         if(pos<=0){
//             int val = head->retrieve();
//             pop_front();
//             return val;
//         }
//         if(pos>=sz-1){
//             int val = tail->retrieve();
//             pop_end();
//             return val;
//         }
//         node* temp = head;
//         int index =0;
//         while(temp->next()!=nullptr && index<pos-1){
//             temp= temp->next();
//             ++index;
//         }
//         int val = temp->next()->retrieve();
//         node* current = temp->next();
//         current->next()->set_prev(temp);
//         temp->set_next(current->next());
//         delete current;
//         --sz;
//         return val;
//     }
//     int erase(int val){
//         if(empty()){
//             return 0;
//         }
//         int count =0;
//         while((head!=nullptr)&& head->retrieve()==val){
//             pop_front();
//             ++count;
//         }
//          if (head == nullptr) {
//         tail = nullptr;
//         return count;
//     }
//         while( tail!= nullptr && tail->retrieve()==val){
//             pop_end();
//             ++count;
//         }
//         node* temp = head;
//         while(temp->next()!=nullptr){
//             if(temp->next()->retrieve()==val){
//                 node* current = temp->next();
//                 if (current->next() != nullptr){
//                 current->next()->set_prev(temp);}
//                 temp->set_next(current->next());
//                 delete current;
//                 --sz;
//                 ++count;
//             }
//             else{
//                 temp= temp->next();
//             }
//         }
//         if (head == nullptr) {
//         tail = nullptr;
//         return count;
//         }
//         else{
//             node* t = head;
//             while(t->next()!=nullptr){
//                 t=t->next();
//             }
//             tail = t;
//             return count;
//         }
//     }
//         void display(){
            
//            for(node* ptr = head;ptr!=nullptr;ptr=ptr->next()){
//                 cout<<ptr->retrieve()<<"  ";
//            }
//         }
//         void reverse(){
//             if(head==nullptr||head ==tail){
//                 return;
//             }
//             node* current = head;
//             node* temp = nullptr;
//             while(current!=nullptr){
//                 temp = current->prev();
//                 current->set_prev(current->next());
//                 current->set_next(temp);
//                 current = current->prev();
//             }
//             if(temp!=nullptr){
//                 head=temp->prev();
//             }
//             node* t = head;
//             head = tail;
//             tail =t;
//         }
        
//     };

//     int main(){
//         list ls;
//         ls.push_front(13);
//         ls.push_front(13);
//         ls.push_back(13);
//         ls.push_back(13);
//         ls.push_mid(13);
//         ls.push_mid(13);
//         ls.push_mid(13);
//         ls.insert_at(7, 12);
//         // int result = ls.pop_front();
//         // int r = ls.pop_end();
//         // int e = ls.pop_mid();
        
//         // int o=ls.pop_at(2);
//         // int p=ls.pop_at(9);
//         // int q=ls.pop_at(-23132);
        
//         int c= ls.erase(13);
//         cout<<" "<<c<<endl;
//         // ls.insert_at(9,33);
//         ls.display();
       
//     }

// int fact(int n){
//     if(n==1 || n==0){
//         return 1;
//     }
//     return n*fact(n-1);
// }
// void print(int n){
//     if(n==0){return;}
//     cout<<n << " ";
//     print(n-1);
// }
// int fi(int n ){
//     if(n<=1){
//         return;
//     }
//     return fi(n-1)+fi(n-2);
// }
// int print(int (*arr)[3],int rows,int i =0 ){
//     if(i==n){
//         return;
//     }
//     cout<<arr[i];
//     print(arr, n, i+1);
// }

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatching(string opening, string closing) {
    return closing == "</" + opening.substr(1);
}

int main() {
    string tags[] = {"<html>", "<body>", "<p>", "</p>", "</body>", "</html>"};
    stack<string> s;

    for (string tag : tags) {
        if (tag[1] != '/') { // opening tag
            s.push(tag);
        } else {
            if (s.empty() || !isMatching(s.top(), tag)) {
                cout << "Error: Tag mismatch -> " << tag << endl;
                return 0;
            }
            s.pop();
        }
    }

    if (s.empty())
        cout << "Tags properly nested ✅" << endl;
    else
        cout << "Error: Unclosed tags remain ❌" << endl;
}


#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main() {
    string expr = "{[()]}";
    stack<char> s;

    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') s.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty() || !isMatching(s.top(), c)) {
                cout << "Mismatch found ❌" << endl;
                return 0;
            }
            s.pop();
        }
    }

    if (s.empty()) cout << "Balanced ✅" << endl;
    else cout << "Unbalanced ❌" << endl;
}

int