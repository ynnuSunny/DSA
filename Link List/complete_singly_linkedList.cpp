//All about single Linked List

#include<bits/stdc++.h>
using namespace std;
typedef struct LinkedList node;
 



struct LinkedList
{
    int data;
    LinkedList *next;
    
};


//This is also called linked list 
//Traverse 1st to end .
void print(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}


//This function wark like insert last or 
//Step by step insert in the linked list
void insert(node **head,int number){
    node *temp;
    if(*head == NULL){
        temp = new node();
        temp->data = number;
        temp->next = NULL;
        *head = temp;
    }

    else{
         while(temp->next!=NULL){
           temp = temp->next;
        } 
        temp->next = new node();
        temp->next->data = number;
        temp->next->next =NULL;
     }

}

// Using this function we can insert item/number
// At the beggining
void insertBeggin(node **head,int number){
     node *item;
     if(*head==NULL){
        item = new node();
        item->data = number;
        item->next = NULL;
        *head = item;
     }
     else{
        item = new node();
        item ->data = number;
        item->next = *head;
        *head = item;
     }
}

void insertAfter(node **head,int afterNumber,int number ){
       node *temp,*newNumber;
       temp  = *head;
       newNumber = new node();
       newNumber->data = number;
       while(temp!=NULL){
         if(temp->data == afterNumber){
            break;
         }
         temp = temp->next;
       }
       if(temp!=NULL){
        newNumber->next = temp->next;
        temp->next = newNumber;
       }else{
        cout<<afterNumber<<" is not found in this list"<<endl;
       }
}
void insertBefore(node **head,int beforeNumber,int number){
      node *temp,*newNumber;
      temp = *head;
      newNumber = new node();
      newNumber->data = number;
      if(temp->data==beforeNumber){
          newNumber->next =temp;
          temp = newNumber;
      }else{
         while(temp!=NULL){
            if(temp->next->data == beforeNumber){
               break;
            }
            temp = temp->next;
            if(temp==NULL)break;
         }
      }
      if(temp!=NULL){
         newNumber->next = temp->next;
         temp->next = newNumber;
      }else{
         cout<<beforeNumber<<" is not found in this link"<<endl;
      }
}

void deleteFirst(node **head){
      node *temp;
      temp = *head;
      if(temp==NULL){
        cout<<"There is no item"<<endl;
      }
      else{
         *head = temp->next;
         delete(temp);
      }
}
void deleteEnd(node **head){
    node *temp,*item;
    temp = *head;
    if(temp==NULL){
        cout<<"There is no item"<<endl;
    }else{
        while(1){
            if(temp->next==NULL)break;
            item = temp;
            temp = temp->next;
        }
        item->next = temp->next;
        delete(temp);
    }
}

void deleteItem(node **head,int item){
    node *temp,*select;
    temp = *head;
    if(temp->data==item){
        *head = temp->next;
    }
    else{
    while(temp!=NULL){
        if(temp->data == item){
            break;
        }
        select = temp;
        temp = temp->next;
    }
    select->next = temp->next;
    delete(temp);
 } 
}

int main(){
    node *head=NULL,*temp;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    insert(&head,60);
    print(head);

    //insertBeggin(&head,80);
    //print(head);

    // insertAfter(&head,10,15);
    // print(head);
    // insertAfter(&head,60,70);
    // print(head);

    // insertBefore(&head,50,25);
    // print(head);

    deleteFirst(&head);
    print(head);
   // deleteEnd(&head);
    //print(head);
    //deleteItem(&head,10);
    //print(head);     
  
}