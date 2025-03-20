#include <iostream>
using namespace std;

class Stack{
private:
    int size;
    int* arr;
    int top;

public:
    Stack(int capacity){
        size=capacity;
        arr=new int[size];
        top=-1;
        }
    ~Stack(){
        delete[] arr;
    }
    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top]=val;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return arr[top];
    }
    int getSize(){
        return top+1;
    }
    bool isFull(){
        return top==size-1;
    }
    bool isEmpty(){
        return top==-1;
    }
};


int main() {
    // Create a stack with a capacity of 5
    Stack s(5);

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element (peek): " << s.peek() << endl; // Should print 30
    cout << "Stack size: " << s.getSize() << endl; // Should print 3

    // Pop an element
    s.pop();
    cout << "After popping, top element: " << s.peek() << endl; // Should print 20

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