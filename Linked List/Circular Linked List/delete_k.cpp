#include <bits/stdc++.h> 
using namespace std; 

struct node {
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void printlist(node *head) {
    if(head==NULL)return;
    node *p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}

node *deleteHead(node *head) {
    if(head==NULL)return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    node *temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

node *deleteKth(node *head,int k){
    if(head==NULL)return head;
    if(k==1)return deleteHead(head);
        node *curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}

int main() 
{ 
	node *head=new node(10);
	head->next=new node(20);
	head->next->next=new node(30);
	head->next->next->next=new node(40);
	head->next->next->next->next=head;
	head=deleteKth(head,3);
	printlist(head);
	return 0;
} 
