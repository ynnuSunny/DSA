#include<bits/stdc++.h>
using namespace std;

typedef struct DoublyCircularLinkedList node;

struct  DoublyCircularLinkedList
{
   int data;
   DoublyCircularLinkedList *next,*prev;
   
};
void insert( node **head ,int num){
  node* temp,*newNode,*firstNode,*tail;
  temp = *head;
  newNode = new node();
  newNode->data = num;
  firstNode = *head;
   if(*head==NULL){  
      temp = newNode;
      temp ->next = temp;
      temp ->prev = temp;
      *head = temp;   
   }
   else{
      temp = temp->prev;
     while(1){
        if(firstNode->data>=num){
            newNode->next = firstNode;
            newNode->prev = firstNode->prev;
            firstNode->prev = newNode;
            firstNode = newNode->prev;
            firstNode->next = newNode;
            *head = newNode;
            break;
        }
        else if (temp->data<=num){
            newNode->next= temp->next;
            newNode->prev=temp;
            temp->next = newNode;
            temp = newNode->next;
            temp->prev = newNode;
            break;
        }
        temp = temp->prev;
     }

   }

}

void ShowAll(node *head){
    node *temp;
    temp = head;

    if(head!=NULL){
      cout<<"All item ";
      while(1){
         cout<<temp->data<<" ";
         temp = temp->next;
         if(temp==head)break;
      }
      cout<<endl;
    }
    else {
      cout<<"There is no item"<<endl;
    }
    cout<<endl;
}
void SearchItem(node *head,int item){
    node *temp;
    temp = head;

    if(head!=NULL){
      cout<<"Item searching : ";
      while(1){
         if(temp->data==item){
            cout<<"Yes item is found"<<endl;
            break;
         }

         temp = temp->next;
         if(temp==head){
            cout<<"Item is not found"<<endl;
            break;
         }
      }
      
    }
     else {
      cout<<"There is no item"<<endl;
    }
    cout<<endl;


}
void DeleteItem(node **head,int item){
    node *temp,*prevItem,*nextItem;
    temp = *head;

    if(head!=NULL){
      cout<<"Deleting item : ";
      while(1){
         if(temp->data==item){
            prevItem = temp->prev;
            nextItem = temp->next;
            prevItem->next = nextItem;
            nextItem->prev = prevItem;
            cout<<"Item deleted successfully"<<endl;
            break;
         }

         temp = temp->next;
         if(temp==*head){
            cout<<"Item is not found"<<endl;
            break;
         }
      }
    }
     else {
      cout<<"There is no item"<<endl;
    }
    cout<<endl;
}

void listLength(node *head){
   node *temp;
   temp = head;
   int len = 0;

    if(head!=NULL){
      cout<<"Corrent length: ";
      while(1){
         len++;
         temp = temp->next;
         if(temp==head)break;
      }
      cout<<len<<endl;
    }
    else {
      cout<<"There is no item"<<endl;
    }
    cout<<endl;
}
int main(){
   node *head;
   head = NULL;
   int n,search,del;
   cout<<"Enter how many number you want to input : ";
   cin>>n;
   srand(time(0));
   for(int i=0;i<n;i++){
      insert(&head,rand()%10);
   }
   ShowAll(head);
   cout<<"Enter an item for search : ";
   cin>>search;
   SearchItem(head,search);

   listLength(head);

   cout<<"Enter an item for delete : ";
   cin>>del;
   DeleteItem(&head,del);
   ShowAll(head);
   listLength(head);

  
   

}