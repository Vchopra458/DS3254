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


class LinkedListqueue{  
private:
    Node* head;
    Node* tail;
    int capacity;
    int size;
public:
    LinkedListqueue(int cap){   
        head=NULL;
        tail=NULL;
        capacity=cap;
        size=0;
    }
    void enqueue(int val){
        if(size==capacity){
            cout<<"queue overflow"<<endl;
            return;
        }
        Node* node =new Node(val);
        if(head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->ptr=node;
            tail=node;
        }
        size++;
    }
    int dequeue(){
        if(head==NULL){
            cout<<"queue underflow"<<endl;
            return -1;
        }
        int temp=head->data;
        Node* old=head;
        head=head->ptr;
        if(head==NULL){
            tail=NULL;
        }
        size--;
        delete old;
        return temp;
    }
    int front(){
        if(head==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return head->data;
    }
    int back(){
        if(tail==NULL){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return tail->data;
    }
    bool isEmpty(){
        return head==NULL;
    }
    bool isFull(){
        return size==capacity;
    }
    int count(){
        return size;
    }
    void print() {  
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->ptr;
        }
        cout << endl;
    }
};

int main(){

    LinkedListqueue queue(3);  // Creating a queue with size limit 3

    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.print();  // Expected output: 10 20 30

    // Test queue overflow
    queue.enqueue(40);  // Should print "Queue overflow"

    // Test front and back
    cout << "Front element: " << queue.front() << endl;  // Expected: 10
    cout << "Back element: " << queue.back() << endl;    // Expected: 30

    // Test dequeue
    cout << "Dequeued: " << queue.dequeue() << endl;  // Expected: 10
    queue.print();  // Expected output: 20 30

    // Test count
    cout << "Queue size: " << queue.count() << endl;  // Expected: 2

    // Test isEmpty and isFull
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;  // Expected: No
    cout << "Is queue full? " << (queue.isFull() ? "Yes" : "No") << endl;    // Expected: No

    // Dequeue remaining elements
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();  // Should print "Queue underflow"

    // Final check
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;  // Expected: Yes

    return 0;
}