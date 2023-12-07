#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};

//Part A
void traverse(node*&head){
    if(head==NULL)
    return;

    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Part B 
void insert(node*&head,node*&tail, int d,int position){
    //linked list is empty
    node*temp=new node(d);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }

    // insert at head
    if(position==1){
        temp->next=head;
        head=temp;
        return;
    }
    
    int count=1;
    node*curr=head;
    while(count<position-1){
        curr=curr->next;
        count++;
    }
    //insert at tail
    if(curr->next==tail){
        temp->next=tail;
        tail=temp;
    }
    //insert at any position
    else{
        temp->next=curr->next;
        curr->next=temp;
    }

}

//Part c
//Deleting an element at a given position in a linked list
void deletePosition(node* &head, int position){
    //from  head
    if(position==1){
        node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;  // Destructor is called in the class
        return;
    }

    // deletion from middle and at the end
    node* prev=NULL;
    node* curr=head;
    int count=1;
    while(count<position){
        prev=curr;
        curr=curr->next;
        count++;
    }

    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}  

//Part D-- SOrt
void sortLL(node*&head){
    //size of linked list
    int n=0;
    node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        n++;
    }

    //copy data of linkedlist in an array
    vector<int> arr(n);
    int i=0;
    temp=head;
    while(temp!=NULL){
        arr[i++]=temp->data;
        temp=temp->next;
    }

    sort(arr.begin(),arr.end());
    // copy data back to linked list
    i=0;
    temp=head;
    while(temp!=NULL){
        temp->data=arr[i++];
        temp=temp->next;
    }
}

//Part E
node* reverse(node*&head){
    if(head==NULL)
    return NULL;

    node*prev=NULL;
    node*next=NULL;
    node*curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main()
{
    node*head=NULL;
    node*tail=NULL;
    insert(head,tail,4,1);
    insert(head,tail,3,2);
    insert(head,tail,8,2);
    insert(head,tail,10,2);

    traverse(head);

    deletePosition(head,1);
    cout<<endl<<"After deleting the node"<<endl;
    traverse(head);
    head=reverse(head);
    traverse(head);

    sortLL(head);
    cout<<"The sorted linked list is"<<endl;
    traverse(head);
    return 0;
}