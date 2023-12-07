#include<iostream>
using namespace std;
//1. Create C++ programming for double linked list with data elements key

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

void traverseForward(node*head){
    if(head==NULL) return;

    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void traverseBackward(node*tail){
    if(tail==NULL) return;

    node*temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;;
    }
}

void insertAtLast(node*&head,node*&tail,int d){
    node*temp=new node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }

    //insert at last position
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtKthPosition(node*&head,node*&tail,int d,int k){
    node*temp=new node(d);
    if(head==NULL)
    return;

    int count=0;
    node*curr=head;
    while(count<k-1){
        curr=curr->next;
        count++;
    }
    // insertion at 1st position
    if(curr==head){
        temp->next=head;
        head->prev=temp;
        head=temp;
        return;
    }
    //insert at last position
    if(curr->next==NULL){
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        return;
    }

    temp->next=curr->next;
    curr->next->prev=temp;
    curr->next=temp;
    temp->prev=curr;
}


void deletetionAtLast(node*&head,node*&tail){
    if(head==NULL)
    return;

    node*temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete temp;
}

void deletetionAtFirst(node*&head,node*&tail){
    if(head==NULL)
        return;

    node*temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}

void deleteKey(node*&head,node*&tail,int key){
    if(head==NULL)
    return;

    node*temp=head;
    // to reach the node just before key
    while(temp->next!=NULL && temp->next->data==key){
        temp=temp->next;
    }

    node*curr=temp->next;

    //key at last position
    if(curr->next==NULL){
        node*del=curr;
        temp->next=NULL;
        tail=temp;
        delete del;
        return;
    }

    temp->next=curr->next;
    curr->next->prev=temp;
    delete curr;

}
int main()
{
    node*head=NULL;
    node*tail=NULL;
    
    insertAtLast(head,tail,3);
    insertAtLast(head,tail,7);
    insertAtKthPosition(head,tail,10,2);
    insertAtKthPosition(head,tail,1,2);

    deletetionAtFirst(head,tail);
    cout<<"Traverse Forward"<<endl;
    traverseForward(head);
    cout<<endl<<"Traverse backward"<<endl;
    traverseBackward(tail);
    
    return 0;
}