#include<iostream>
using namespace std;

// Create C++ programming  for  circular single linked list 

class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};

class singleCircularList{
    public:
    // node*head;

    // singleCircularList(int data){
    //     head=new node(data);
    // }

    //check list is empty or not
    bool isEmpty(node*head){
        if(head==NULL){
            return true;
        }
        return false;
    }

    //  Count the number of nodes in the list
    int countNode(node*head){
        if(head==NULL)
        return 0;

        node*temp=head;
        int cnt=1;
        while(temp->next!=head){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }

    // Traverse each node of the list
    void traverse(node*head){
        if(head==NULL)
        return;

        node*temp=head;
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data;
    }

    // Insertion of a node at the beginning of the list
    void insertAtstart(node*&head,int d){
        node*temp=new node(d);
        if(head==NULL){
            head=temp;
            head->next=head;
        }

        node*curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        temp->next=head;
        curr->next=temp;
        head=temp;
    }

    // Deletion of the node at the end of the list
    void deleteAtEnd(node*&head){
        if(head==NULL)
        return;
        node*curr=head;
        while(curr->next && curr->next->next!=head){
            curr=curr->next;
        }

        //single node
        if(curr==head && !curr->next){
            delete curr;
            return;
    }

        // more than 1 nodes are present
            node*temp=curr->next;
            curr->next=head;
            delete temp;
    }

};
int main()
{
    node*head=NULL;
    singleCircularList l1;
    l1.insertAtstart(head,6);
    l1.insertAtstart(head,7);
    l1.insertAtstart(head,10);
    l1.insertAtstart(head,2);
    
    l1.traverse(head);

    cout<<endl<<"The number of nodes are "<<l1.countNode(head)<<endl;

    l1.deleteAtEnd(head);
    l1.traverse(head);
    return 0;
}