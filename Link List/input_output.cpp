#include <bits/stdc++.h>
using namespace std;
typedef struct LinkList node;

struct LinkList
{
    int data;
    LinkList *next;
    
};
//Insert item at the 1st 
void intsertInFast(node** head , int item){
    node *temp ;
    temp = new node();
    temp->data = item;
    temp->next = *head;
    *head = temp;
    
}

//Using this function we can print the list
void printList(node *head){
    node *temp;
    temp = head;
    while(1){
        cout<<temp->data<<" ";
        temp = temp->next;
        if(temp->next==NULL)break;
    }
    cout<<endl;
    
}


//using this funtion we can insert node value rendomly
void insertList(node *head){
    node *temp;
    temp = head;
    for(int i=1;i<=10;i++){
        temp->data = 10*i;
        temp->next = new node();
        temp = temp->next;
    }temp=NULL;
    
}

int main(){
    node *head,*temp;
    head = new node();

    insertList(head);
    printList(head);

}