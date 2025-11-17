// #include <iostream>
// using namespace std;
// class node{
//     private:
//     node* next_node;
//     int elem;
//     public:
//     node():next_node(nullptr), elem(0){}
//     node(int val, node* next=nullptr): next_node(next), elem(val){}
//     int retrieve(){
//         return elem;
//     }
//     node* next(){
//         return next_node;
//     }
//     void set_next(node* n){
//         next_node=n;
//     }
// };
// class stack{
//     private:
//     node* top;
//     int sz;
//     public:
//     stack():top(nullptr), sz(0){}
//     bool empty(){
//         return (top==nullptr);
//     }
//     node* getTop(){
//         if(empty()){
//             return 0;
//         }
//         return top;
//     }
//     void push_top(int val){
//         node* newN = new node(val);
//         newN->set_next(top);
//         top=newN;
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
//         return val;
//     }
//     void display(){
//         for(node* ptr=top; ptr!=nullptr; ptr=ptr->next()){
//             cout<<ptr->retrieve()<< "  ";
//         }
//     }
//  };   
//     int main(){
//         stack st;
//         st.push_top(56);
//         st.push_top(18);
//         st.push_top(0);
//         st.pop();
//         st.pop();
//         st.pop();
//         st.display();
//     }

#include <iostream>
using namespace std;
class stack{
    private:
    static const int max=100;
    int topIndex;
    int arr[max];
    int sz;
    public:
    stack():topIndex(-1), sz(0){}
    bool empty(){
        return (topIndex==-1);
    }
    int size(){
       return sz;
    }
    bool full(){
        return(topIndex==max-1);
    }
    void push(int val){
        if(full()){
            return;
        }
        arr[++topIndex]=val;

    }
    int pop(){
        if(empty()){
            return -1;
        }
        return arr[topIndex--];
    }
    void display(){
        if(empty()){
            return;
        }
        for (int i =topIndex; i>=0; --i){
            cout<< arr[i]<< " ";
        }
        cout<<endl;
    }
    int top(){
        return(arr[topIndex+1]);
    }

};

int main(){
    stack st;
    st.push(56);
    st.push(18);
    st.pop();
    st.display();
}
