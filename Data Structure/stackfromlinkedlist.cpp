#include<iostream>
#include<list>
using namespace std;

class Node{
public:    
    int data;
    Node* ptr;

    Node(int val){
        data=val;
        ptr=NULL;
    }
};


class LinkedListStack{  
private:
    Node* head;
    int capacity;
    int size;
public:
    LinkedListStack(int cap){   
        head=NULL;
        capacity=cap;
        size=0;
    }    
    void push(int val){
        if(size==capacity){
            cout<<"stack overflow"<<endl;
            return;
        }
        Node* node=new Node(val);
        node->ptr=head;
        head=node;
        size++;
    }
    int pop(){
        if(head==NULL){
            cout<<"list is empty nothing to pop in there:Stack underflow"<<endl;
            return -1;
        }
        Node*temp=head;
        head=temp->ptr;
        int val=temp->data;
        delete temp;
        size--;
        return val;
    }
    int peek(){
        if(head==NULL){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        return head->data;
    }
    void print(){
        if(head==NULL){
            cout<<"The stack is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->ptr;
        }
        cout<<endl;
    }
    bool isEmpty(){
        return head==NULL;
    }
    bool isFull(){
        return size==capacity;
    }
    int count(){
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->ptr;
            count++;
        }
        return count;
    }
};

int main() {
    LinkedListStack stack(3);

    // Test push
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print();
    cout<<"is stack full:"<<(stack.isFull() ? "yes":"no")<<endl;

    // Test peek
    cout << "Top element: " << stack.peek() << endl;

    // Test pop
    stack.pop();
    stack.print();

    // Test count
    cout << "Number of elements in stack: " << stack.count() << endl;

    // Test isEmpty
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    // Pop remaining elements
    stack.pop();
    stack.pop();
    stack.pop(); // Trying to pop from an empty stack

    // Final check
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}