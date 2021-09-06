#include<bits/stdc++.h>
using namespace std;

typedef struct doubleLinkedList node;

struct  doubleLinkedList
{
   int data;
   doubleLinkedList *next,*prev;

};
node *head,*tail;

void ins(int y,int x){
   node *temp,*itemNode,*insertNode;
   temp = head;
   itemNode = new node();
   itemNode->data = x;
   while(temp!=NULL){
      if(temp->data == y)
         break;
      else temp = temp->next;
   }
   

   if(temp==NULL){
     if(tail->prev==NULL){
         tail = itemNode;
         tail->prev = head;
         tail->next = NULL;
     }
     else{
        insertNode = head->next;
        insertNode->prev = itemNode;
        itemNode->next = insertNode;
     }
     itemNode->prev = head;
     head->next = itemNode;
   }
   else{
       insertNode = temp->next;
      itemNode->prev = temp;
      temp->next = itemNode;
      if(insertNode==NULL){
         itemNode->next = NULL;
      }
      else{
         itemNode->next = insertNode;
         insertNode->prev = itemNode;
      }

   }

}

void shw(){
   node *temp;
   temp = head->next;
   while(temp!=NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}

void del(int x){
   node* temp,*afNode,*beNode;
   temp = head;

   while(temp!=NULL){
      if(temp->data == x){
         break;
      }
      temp = temp->next;
   }
   if(temp==NULL){
      cout<<"DELETE not possible."<<endl;
   }
   else{
      cout<<"Node with key value "<<x<<" is DELETED."<<endl;
      afNode = temp->prev;
      beNode = temp->next;
      if(afNode!=NULL){
         afNode->next = beNode;
      }
      if(beNode!=NULL){
         beNode->prev = afNode;
      }
      else{
         afNode->next = NULL;
      }

   }
}

void sch(int x){
   node* temp;
   temp = head;

   while(temp!=NULL){
      if(temp->data == x){
         break;
      }
      temp = temp->next;
   }
   if(temp==NULL){
      cout<<"Not FOUND"<<endl;
   }
   else{
      cout<<"Node with key value "<<x<<" is FOUNDED."<<endl;
   }
}

int main(){
   head = new node();
   head->next = NULL;
   head->prev = NULL;
   head->data = 10;
   tail = head;
  // For debuging
     // ins (3,1);
     // ins (1,2);
     // ins (1,3);
     // ins (2,4);
    
     // ins (5,0);
     // ins(0,2);
     // del(2);
     // del(0);
     // del(4);
     // shw();
     // sch(1);
     // sch(5);
     // cout<<head->next->data<<endl;
     // cout<<tail->data<<endl;
   int n;
  while(1){
    cout<<"Choose  an option : --"<<endl;
    cout<<"--For insert press    : 1"<<endl;
    cout<<"--For deletation press: 2"<<endl;
    cout<<"--For searching press : 3"<<endl;
    cout<<"--For Show list press : 4"<<endl;
    cout<<"--For close press     : 5"<<endl;
    cin>>n;
    if(n==1){
      int x, y;
      cout<<"Enter value of y and x : ";
      cin>>y>>x;
      ins(y,x);
    }
    else if(n==2){
      int x;
      cout<<"Enter item for deletation : ";
      cin>>x;
      del(x);
    }
    else if(n==3){
      int x;
      cout<<"Enter item for searching : ";
      cin>>x;
      sch(x);
    }
    else if(n==4){
      cout<<"list item : ";
      shw();
    }
    else{
      break;
    }
  }


}