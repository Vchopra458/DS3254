#include<iostream>
#include <stack>
using namespace std;

class QueueStack{
private:
    stack<int> input;
    stack<int>  output;
public:    
    void enqueue(int val){
        input.push(val);
    }
    int dequeue(){
        if(input.empty() && output.empty()){
            cout<<"queue is empty";
            return -1;
        }
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }    
        int temp=output.top();
        output.pop();
        return temp;
    }
    int front(){
        if(input.empty() && output.empty()){
            cout<<"queue is empty";
            return -1;
        }
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }    
        return output.top();
    }
    bool isEmpty(){
        return (input.empty() && output.empty());
    }
    int count(){
        return input.size() + output.size();
    }
};

int main(){
    QueueStack q;

    cout << "Enqueue 10, 20, 30" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // Expected: 10
    cout << "Dequeue: " << q.dequeue() << endl;     // Expected: 10
    cout << "Front element: " << q.front() << endl; // Expected: 20
    cout << "Dequeue: " << q.dequeue() << endl;     // Expected: 20
    cout << "Dequeue: " << q.dequeue() << endl;     // Expected: 30
    cout << "Dequeue: " << q.dequeue() << endl;     // Expected: Queue is empty

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Expected: Yes

    q.enqueue(40);
    q.enqueue(50);
    cout << "Count after enqueuing 40 and 50: " << q.count() << endl; // Expected: 2

    cout << "Front element: " << q.front() << endl; // Expected: 40
    cout << "Dequeue: " << q.dequeue() << endl;     // Expected: 40
    cout << "Front element: " << q.front() << endl; // Expected: 50

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Expected: No
    return 0;
}