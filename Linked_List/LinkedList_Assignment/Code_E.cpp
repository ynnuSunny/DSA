#include<bits/stdc++.h>
using namespace std;

typedef struct charcterLink node;

struct  charcterLink
{
   char character;
   int  num;
   charcterLink *next;
   
};
void insert( node **head){
  node* temp,*newNode;
  temp = *head;
   char ch = 'a';
   for(int i=0;i<26;i++){
     newNode = new node();
     newNode->character  = ch;
     newNode->num = 0;
     newNode->next = NULL;
     temp->next = newNode;
     temp = temp->next;
     ch++; 
   }

}
void countAdd(node **head,char ch[]){
     node *temp,*tempMain;
     tempMain = *head;
     tempMain = tempMain->next;
    for(int i=0;ch[i]!='\0';i++){
        temp = tempMain;
       ch[i] = tolower(ch[i]);
       while(temp!=NULL){
           if(temp->character==ch[i]){
            temp->num += 1;
            break;
         }
           temp = temp->next;
       }
   }
}
void print(node *head){
   node *temp;
   temp = head;
   temp = temp->next;
   while(temp!=NULL){
      cout<<temp->character<<" : "<<temp->num<<endl;
      temp = temp->next;
   }
}

int main(){
   node *head;
   head = new node();
   head->next = NULL;

   char a[100];
   cin>>a;

   insert(&head);
   countAdd(&head,a);
   print(head);


}