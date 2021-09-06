#include<bits/stdc++.h>
using namespace std;
typedef struct LinkedList node;


struct LinkedList
{
    int data;
    LinkedList *next;
    LinkedList *prev;
};
void printfBack(node *tail){
    node *temp;
    temp = tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }cout<<endl;
}
void printFont(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}


//For print Data
void getData(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

//taking input randomly
void setData(node *head,node **tail,int n){
    node *temp,*backNode;
    temp = head;
    srand(time(0));
    for(int i=1;i<=n;i++){
        temp ->data = rand()%10;
        if(i==n)break;
        backNode = temp;
        temp->next = new node();
        temp = temp->next;
        temp->prev = backNode;
        
    }
   
       *tail=temp;
}

void insert(node **head,node **tail,int number){
    node *temp;
    temp = *head;
    if(head==NULL){
        temp = new node();
        temp->next = NULL;
        temp->prev = NULL;
        *head = temp;
        *tail = temp;
    }else{
        //while()
    }
}

int main(){
    node *head=NULL,*tail=NULL;

   
    insert(&head,&tail,10);
    getData(head);
    //printfBack(tail);

}