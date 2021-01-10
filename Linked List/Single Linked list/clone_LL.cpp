#include <bits/stdc++.h> 
using namespace std; 

struct node 
{ 
    int data; 
    node *next,*random; 
    node(int x) 
    { 
        data = x; 
        next = random = NULL; 
    } 
}; 

void print(node *start) 
{ 
    node *ptr = start; 
    while (ptr) 
    { 
        cout << "Data = " << ptr->data << ", Random  = "<< ptr->random->data << endl; 
        ptr = ptr->next; 
    } 
}

node* clone(node *head) 
{ 
    node *next,*temp;
    for(node *curr=head;curr!=NULL;){
        next=curr->next;
        curr->next=new node(curr->data);
        curr->next->next=next;
        curr=next;
    }
    for(node *curr=head;curr!=NULL;curr=curr->next->next){
        curr->next->random=(curr->random!=NULL)?(curr->random->next):NULL;
    }
    
     node* original = head, *copy = head->next; 
  
    temp = copy; 
  
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp;   
}

int main() 
{ 
	node* head = new node(10); 
    head->next = new node(5); 
    head->next->next = new node(20); 
    head->next->next->next = new node(15); 
    head->next->next->next->next = new node(20); 
    
    head->random = head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next;
    head->next->next->next->next->random=head->next->next->next;
    
    cout << "Original list : \n"; 
    print(head); 
  
    cout << "\nCloned list : \n"; 
    node *cloned_list = clone(head); 
    print(cloned_list); 
  
    return 0; 
} 
