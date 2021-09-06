#include<bits/stdc++.h>
using namespace std;

typedef struct linkedList node;

struct linkedList
{
   char data;
   node *next;
   
};

//For store intial data
void store(char a[],node **head){
     node *temp;
     for(int i=0;a[i]!='\0';i++){  
       if(i==0){
           temp = new node;
           temp->data = a[i];
           temp->next = NULL;
           *head = temp;
           temp = *head;
       }
       else{
          temp->next = new node;
          temp = temp->next;
          temp->data = a[i];
          temp->next = NULL;
       }
       
     }
}

//For printing image
void show(node *head[],int x){
   for(int i=0;i<x;i++){
      node *temp;

      temp = head[i];
      while(temp!=NULL){
         cout<<temp->data;
         temp = temp->next;
      }cout<<endl;
   }
}

//For makeing image
void makeMirrorImage(node *head[],node *mirror[],int x,int y){
     for(int i=0;i<x;i++){
      node *temp,*mtemp,*newnode;
      temp = head[i];
      mirror[i] = NULL;
      while(temp!=NULL){

         if(mirror[i]==NULL){
            mirror[i] = new node;
            mirror[i]->data = temp->data;
            mirror[i]->next = NULL;
         }
         else{
          
            mtemp = new node();
            mtemp->data = temp->data;
            mtemp->next = mirror[i];
            mirror[i] = mtemp; 
         }
         


         temp = temp->next;
      }
   }
}

int main(){
   int x,y;
   cin>>x>>y;
   node *head[x],*mirror[x];
   char a[y+1];
   //take input and store
   for(int i=0;i<x;i++){
       cin>>a;
       store(a,&head[i]);
   }
   //show(head,x);
   makeMirrorImage(head,mirror,x,y);
   show(mirror,x);
   
}




