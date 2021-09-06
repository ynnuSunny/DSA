#include <bits/stdc++.h>
using namespace std;
typedef struct LinkList node;

void printList(node* head);

struct LinkList
{
    int data;
    LinkList *next;
    
};

void removeItem(node** head,int item){
    node *temp;
    temp = *head;
    if(temp==NULL){
      return;
    }
    else if(temp->data==item && temp->next == NULL){
        delete(temp);
        temp = NULL;
    }else{
        while(temp->next->data != item){
            temp = temp->next;
        }
        if(temp->next->data ==item){
            //delete(temp->next);
            temp = temp->next->next;
        }
    }
}


void insertLast(node* *head){
    node *temp,*lastNode;
    temp = *head;
    lastNode = new node();
    lastNode ->data = 120;
    lastNode ->next = NULL;
    if(head!=NULL){
        while(temp->next!=NULL){
            temp = temp->next;
        }temp->next = lastNode;

    }else{
        *head = lastNode;
    }

}

void removeAtEnd(node** head){
    node *temp,*prev;
    temp = *head;
    if(temp==NULL)return;
    else if(temp->next==NULL){
        *head = temp->next;
    }
    else{
        while(temp->next->next!=NULL){
           //prev = temp;
            temp = temp->next;
        }
        delete(temp->next);
       temp ->next =NULL;
        
    }
}

void removeAtBegin(node* *head){
    node *temp;
    temp = *head;
    if(temp!=NULL){
        temp = temp->next;
        *head =temp;
    }
}



void insertAtEnd(node* *head){
    node *temp,*newNode;
    temp = *head;
    newNode = new node;
    newNode ->data = 120;
    newNode ->next = NULL;
    if(head!=NULL){
      while(temp->next != NULL){
          temp = temp->next;
      }
      temp->next = newNode;
    }
    else{
        temp = new node();
        temp->data = 120;
        temp->next = NULL;
    }
}



//Insert 1st
void insertAtBegin(node* *head,int item)
{
    node *temp ;
    temp = new node;
    temp->data = item;
    temp->next=*head;
    *head = temp;
    
}
//Using this function we can print the list
void printList(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
    
}


//using this funtion we can insert node value rendomly
void fillTheListRandomly(node *head,int n){
    node *temp;
    temp = head;
   
    for(int i=1;i<=n;i++){
        temp->data = i+rand()%10;
        if(i==n)break;
        temp->next = new node();
        temp = temp->next;
    }
}


int main(){
    node *head,*tail;
    head = new node();
//Using this funtion we can fillup the linked list we random number
    fillTheListRandomly(head,10);
  
//Using this function we can insert a value at the begining  
    insertAtBegin(&head,9);

 //Using thisfunction we can insert a value at the last   
    insertAtEnd(&head);
  //  removeAtBegin(&head);
    //removeAtEnd(&head);
    //removeItem(&head,60);
   // head = NULL;
    // insertFirst(head);
   // insertLast(&head);

    //intsertInFast(&head,8);
    //insertLast(head);
    
   
 //Using this function we can print te linked list
    printList(head);

}