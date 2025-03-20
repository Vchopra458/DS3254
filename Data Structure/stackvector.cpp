#include<iostream>
#include<vector>
using namespace std;

class VectorStack{
private:    
    vector<int> data;
    int size;
    int top;
public:
    VectorStack(int capacity){
        size=capacity;
        top=-1;
        data.resize(size);
    }
    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        data[++top]=val;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return data[top];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==size-1;
    }
    int count(){
        return top+1;
    }
};
int main() {
    VectorStack s(5);
    s.push(15);
    s.push(7);
    s.push(10);

    cout<<"Top element is:"<<s.peek()<<endl;
    cout<<"Stack size:"<<s.count()<<endl;

    s.pop();
    cout << "Top element, after popping: " << s.peek() << endl; 

    // Check if stack is empty or full
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // No
    cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl; // No

    // Push more elements to fill the stack
    s.push(40);
    s.push(50);
    s.push(60); // This should print "Stack Overflow"

    // Pop all elements
    while (!s.isEmpty()) {
        cout << "Popped: " << s.peek() << endl;
        s.pop();
    }

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Yes    

    return 0;
}