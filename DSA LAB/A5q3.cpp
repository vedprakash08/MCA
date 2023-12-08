#include<iostream>
using namespace std;

// Create C++ programming  for  circular double linked list for the following 

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};

class doublyCircularList{
    public:

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
            head->prev=head;
            return;
        }

        node*curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        temp->next=head;
        head->prev=temp;
        curr->next=temp;
        temp->prev=curr;
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
            head->prev=curr;
            delete temp;
    }


};
int main()
{
    node*head=NULL;
    doublyCircularList l1;
    l1.insertAtstart(head,6);
    l1.insertAtstart(head,7);
    l1.insertAtstart(head,10);
    l1.insertAtstart(head,2);
    
    l1.traverse(head);

    cout<<endl<<"The number of nodes are "<<l1.countNode(head)<<endl;

    l1.deleteAtEnd(head);
    l1.traverse(head);

    cout<<endl<<"Linked list empty or not "<<l1.isEmpty(head)<<endl;
    
    return 0;
}