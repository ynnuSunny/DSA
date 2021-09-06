#include<bits/stdc++.h>
using namespace std;

typedef struct SinglyLinkedList node;

struct  SinglyLinkedList
{
   int data,power;
   SinglyLinkedList *next;
   
};

void insert(node **Head,char eq[]){
   node *temp,*temp2;
   temp = *Head;

     for(int i=0;eq[i]!='\0';i++){
        if(eq[i]=='+'){
       //  cout<<temp->data<<" "<<temp->power<<endl;
         temp->next = new node();
         temp = temp->next;
         if(eq[i+1] != 'x'){
            temp->data = eq[i+1] - '0';
            temp->power = 0;
         }
        }
        else if(eq[i]=='x'){
          if(i==0 || eq[i-1]=='+'){
            temp->data = 1;
          }
          else{
            temp->data = eq[i-1] -'0';
          }
          if(eq[i+1]=='\0' || eq[i+1]=='+'){
             temp->power = 1;
          }
          else{
            if(eq[i+1]!='\0')
               temp->power = eq[i+1] - '0';
          }
        }
     } temp->next = NULL;
     
}

void showData(node *head){
   node *temp;
   temp = head;
   while(temp!=NULL){
      cout<<temp->data<<"|"<<temp->power<<" ---> ";
      temp = temp->next;
   }
   cout<<"NULL"<<endl;
}

void sum(node *eq1Head,node *eq2Head,node **finalHead){
   node *tempEq1,*tempEq2,*temp;
   tempEq1 = eq1Head;
   tempEq2 = eq2Head;
   temp = *finalHead;
   while(tempEq1!=NULL){
      temp->data = tempEq1->data;
      temp->power = tempEq1->power;
      tempEq2 = eq2Head;
     while(tempEq2!=NULL){
      if(tempEq1->power == tempEq2->power){
         temp->data += tempEq2->data;
      }
      tempEq2 = tempEq2->next;
      
    }
    if(tempEq1->next!=NULL)
    {temp->next = new node();
    temp = temp->next;}
    tempEq1 = tempEq1->next;
   }
   temp->next = NULL;
}

int main(){
   node *eq1Head,*eq2Head,*finalHead;
   eq1Head = new node();
   eq2Head = new node();
   finalHead = new node();
   char eq1[100],eq2[100];
   //cout<<"Enter Equation 1 : ";
   cin>>eq1;
   //cout<<"Enter Equation 2 : ";
   cin>>eq2;
   insert(&eq1Head,eq1);
   //cout<<eq1Head->data<<endl;
   showData(eq1Head);
   cout<<endl;
   insert(&eq2Head,eq2);
   showData(eq2Head);
   cout<<endl;
   sum(eq1Head,eq2Head,&finalHead);
   showData(finalHead);
   

   

}
