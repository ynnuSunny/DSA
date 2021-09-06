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

//This fucntion use for insert last or insert end
void insert(node **head,node **tail,int number){
    node *temp,*lastNode;
    temp = *head;
    if(*head==NULL){
        temp = new node();
        temp->data = number;
        temp->next = NULL;
        temp->prev = NULL;
        *head = temp;
        *tail = temp;
    }else{
        while(temp!=NULL){
            lastNode = temp;
            temp = temp->next;
        }
        lastNode->next = new node();
        lastNode->next->data =number;
        temp = lastNode->next;
        temp->prev = lastNode;
        *tail = temp;

    }
}

// this function 1st or at the beggining
void insertBeggin(node **head,node **tail,int item){
    node *temp,*newNode;
    temp = *head;
    newNode = new node();
    newNode->data = item;
    newNode ->prev = NULL;

    if(*head==NULL){
         newNode ->next =NULL;
         *head = newNode;
         *tail = newNode;
    }
    else {
        newNode ->next = temp;
        temp->prev = newNode;
        *head = newNode;
    }
}


//this function use for remove first
void removeFirst(node **head,node **tail){
     node *temp;
     temp = *head;
     if(*head == NULL){
        cout<<"This is empty Linked list"<<endl;
     }
     else if(temp->next==NULL){
          *head = NULL;
          *tail =NULL;
     }
     else{
        temp = temp->next;
        temp ->prev = NULL;
        *head = temp;
     }
}

//this function use for remove the last item of the list
void removeLast(node **head,node **tail){
      node *temp;
      temp = *tail;
      if(*head == NULL){
        cout<<"This is empty Linked list"<<endl;
     }
     else if(temp->prev==NULL){
          *head = NULL;
          *tail =NULL;
     }
     else{
        temp = temp->prev;
        temp ->next =NULL;
        *tail = temp;
     }
}

// using this function we can remove spacipic item
void removeItem(node **head,node **tail,int item){
      node *temp,*itemNode,*fontNode;
      temp = *head;
      if(*head == NULL){
        cout<<"This is empty Linked list"<<endl;
      }
      else{
        while(temp!=NULL){
            if(temp->data==item)break;
            itemNode = temp;
            temp = temp->next;
            fontNode = temp->next;
        }
        if(temp==NULL){
            cout<<"Print item not found!"<<endl;
        }
        else if(temp->prev == NULL){
             temp = temp->next;
             temp->prev = NULL;
             *head = temp;
        }
        else if(temp->next ==NULL){
            temp = *tail;
            temp = temp->prev;
            temp->next = NULL;
            *tail = temp;

        }
        else{
            itemNode->next = fontNode;
            fontNode->prev = itemNode;

            
        }
      }
}

int main(){
    node *head=NULL,*tail=NULL;

    for(int i=0;i<5;i++){
        int n;
        cin>>n;
        insert(&head,&tail,n);

    }
    printFont(head);
    //insertBeggin(&head,&tail,45);
   // removeFirst(&head,&tail);
   // removeLast(&head,&tail);
    removeItem(&head,&tail,);
    printFont(head);
    printfBack(tail);

}