#include<bits/stdc++.h>
using namespace std;

typedef struct Octopus node;

struct  Octopus
{
   int data;
   Octopus* left,*right,*bottom,*top;
   
};
void insertLeft( node **head,int x){
  node* temp,*newNode;
  newNode = new node();
  newNode->data = x;
  newNode->left = NULL;
  temp = *head;
  while(temp->left != NULL){
   temp = temp->left;
  }
  temp->left = newNode;

}
void insertRight( node **head,int x){
  node* temp,*newNode;
  newNode = new node();
  newNode->data = x;
  newNode->right = NULL;
  temp = *head;
  while(temp->right != NULL){
   temp = temp->right;
  }
  temp->right = newNode;
}
void insertBottom( node **head,int x){
  node* temp,*newNode;
  newNode = new node();
  newNode->data = x;
  newNode->bottom = NULL;
  temp = *head;
  while(temp->bottom != NULL){
   temp = temp->bottom;
  }
  temp->bottom = newNode;

}
void insertTop( node **head,int x){
  node* temp,*newNode;
  newNode = new node();
  newNode->data = x;
  newNode->top = NULL;
  temp = *head;
  while(temp->top != NULL){
   temp = temp->top;
  }
  temp->top = newNode;
}
int sumLeft(node *head){
   int sum = 0;
   node *temp;
   temp = head;
   while(head->left!=NULL){
      sum += head->left->data;
      head = head->left;
   }
   return sum;
}
int sumRight(node *head){
   int sum = 0;
   node *temp;
   temp = head;
   while(head->right!=NULL){
      sum += head->right->data;
      head = head->right;
   }
   return sum;
}
int sumBottom(node *head){
   int sum = 0;
   node *temp;
   temp = head;
   while(head->bottom!=NULL){
      sum += head->bottom->data;
      head = head->bottom;
   }
   return sum;
}
int sumTop(node *head){
   int sum = 0;
   node *temp;
   temp = head;
   while(head->top!=NULL){
      sum += head->top->data;
      head = head->top;
   }
   return sum;
}

int main(){
   node *head;
   head = new node();
   head->left = NULL;
   head->right = NULL;
   head->top = NULL;
   head->bottom = NULL;
  

  int n,A[4],max=0,index=0;
  cin>>n;
  while(n--){
   char c;
   int x;
   cin>>c>>x;
        if(c=='L')insertLeft(&head,x);
   else if(c=='R')insertRight(&head,x);
   else if(c=='B')insertBottom(&head,x);
   else if(c=='T')insertTop(&head,x);
 }
     A[0] = sumLeft(head);
     A[1] = sumRight(head);
     A[2] = sumBottom(head);
     A[3] = sumTop(head);
     max = A[0];

     for(int i = 0;i<4;i++){
        if(A[i]>max){
         max = A[i];
         index = i;
        }
     }
  
   if(index == 0){
       cout<<"Left Link List Has Maximum Sum "<<max<<endl;
   }
   else if(index == 1){
       cout<<"Right Link List Has Maximum Sum "<<max<<endl;
   }
   else if(index == 2){
       cout<<"Bottom Link List Has Maximum Sum "<<max<<endl;
   }
   else if(index == 3){
       cout<<"Top Link List Has Maximum Sum "<<max<<endl;
   }


}