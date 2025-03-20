#include<iostream>
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
class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head=NULL;
    }
    void insert(int val){
        Node *node = new Node(val);
        if(head==NULL){
            head=node;
            return;
        }
        Node* temp=head;
        while(temp->ptr!=NULL){
            temp=temp->ptr;
        }
        temp->ptr=node;
    }
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" "; 
            temp=temp->ptr;
        }
    }
    int count(){
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->ptr;
            count++;
        }    
        return count;    
    }
    void InsertatFirst(int val){
        Node *newnode=new Node(val);
        newnode->ptr=head;
        head=newnode;
    }
    void Insertatlast(int val){
        Node *lastnode=new Node(val);
        if(head==NULL){
            head=lastnode;
            return;
        }
        Node* temp=head;
        while(temp->ptr!=NULL){
            temp=temp->ptr;
        }
        temp->ptr=lastnode;
    }
    void Insertatindex(int idx,int value){
        if(idx>count() || idx<0){
            cout<<"invalid index"<<endl;
            return;
        }
        Node* pos=new Node(value);
        if(idx==0){
            InsertatFirst(value);
            return;
        }
        if(idx==count()){
            Insertatlast(value);
            return;
        }
        Node* temp=head;
        for(int i=0;i<idx-1;i++){
            temp=temp->ptr;
        }
        pos->ptr=temp->ptr;
        temp->ptr=pos;
    }
    void deletebyvalue(int val){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        if(head->data==val){
            Node* temp=head;
            head=head->ptr;
            delete temp;
            return;
        }
        Node* tempr=head;
        while(tempr->ptr!=NULL && tempr->ptr->data!=val){
            tempr=tempr->ptr;
        }
        if(tempr->ptr==NULL){
            cout<<"no such value exists in the linked list"<<endl;
            return;
        }
        Node* nddelete=tempr->ptr;
        tempr->ptr=tempr->ptr->ptr;
        delete nddelete;
    }
};


int main() {
    LinkedList list;

    // Insert at last
    list.Insertatlast(10);
    list.Insertatlast(20);
    list.Insertatlast(30);
    cout << "List after inserting 10, 20, 30 at last: ";
    list.print();  // Expected: 10 20 30
    cout<<endl;
    // Insert at first
    list.InsertatFirst(5);
    cout << "List after inserting 5 at first: ";
    list.print();  // Expected: 5 10 20 30
    cout<<endl;
    // Insert at index 2
    list.Insertatindex(2, 15);
    cout << "List after inserting 15 at index 2: ";
    list.print();  // Expected: 5 10 15 20 30
    cout<<endl;
    // Insert at last using index
    list.Insertatindex(list.count(), 35);
    cout << "List after inserting 35 at last: ";
    list.print();  // Expected: 5 10 15 20 30 35
    cout<<endl;
    // Delete middle value
    list.deletebyvalue(15);
    cout << "List after deleting 15: ";
    list.print();  // Expected: 5 10 20 30 35
    cout<<endl;
    // Delete first value
    list.deletebyvalue(5);
    cout << "List after deleting 5: ";
    list.print();  // Expected: 10 20 30 35
    cout<<endl;
    // Delete last value
    list.deletebyvalue(35);
    cout << "List after deleting 35: ";
    list.print();  // Expected: 10 20 30
    cout<<endl;
    // Try deleting a non-existing value
    list.deletebyvalue(50);
    cout << "After attempting to delete 50 (not in list): ";
    list.print();  // Expected: 10 20 30
    cout<<endl;
    // Count nodes
    cout << "Number of nodes: " << list.count() << endl;  // Expected: 3

    return 0;
}