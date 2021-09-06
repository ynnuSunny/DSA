#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void swap(int* a,int* b){
    int temp = *a;
          *a = *b;
          *b = temp; 
}
//Pivot is middle
//Algo for dessnding odrder
// int positionAssedningPivot1st(int a[],int l,int h){

// }
  //Pivot is middle
//Algo for dessnding odrder
int positionAssedningPivotMiddle(int a[],int l,int h){
       int mid = l+(h-l)/2;
      int pivot = a[mid];
      int i = l;
      int j = h;
      while(i<j){
        while(a[i] < pivot){
            i++;
        }
        while(a[j] >= pivot){
            j--;
        }
        if(i<=j){
            swap(a[i],a[j]);
        }
      }
      return i;
 }


//Pivot is last one
//Algo for assending order
int positionAssedning(int a[],int l,int h){
    int pivot = a[h];
    int i = l-1;
    int j = h;
    while(i<j){
        while(1){
              i++;
            if(a[i]>pivot || i==h)break;
        }
        while(1){
            j--;
            if(a[i]<pivot || j==0)break;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }swap(a[i],a[h]);
    return i;
}




    // Pivot is Last one
   // Algo for Dessending order
int position(int a[],int l,int h){
    int pivot = a[h]; // Let Considier last number as a pivot
    int i = l-1; 
    int j = h;
    while(i<j){  // Exchange the position
        do{
            i++;
        }while(a[i]>pivot);//Incriss I untill a[i]<=pivot
        do{
            j--;
        }while(a[j]<=pivot);//Dicriss J untill a[j]>pivot
        if(i<j){ //Exchange the elemnet in i nad j position
            int temp = a[i];
              a[i] = a[j];
              a[j] = temp;
        }
    }int temp = a[i];  //Exchange the element 
              a[i] = a[h];
              a[h] = temp;
    return i;
}

void QuickSort(int a[],int l,int h){
    if(h>l){
        int pos = positionAssedningPivotMiddle(a,l,h);//Find the pivot possition
          cout<<"Pivot "<<pos<<endl;  
        QuickSort(a,l,pos-1);
        QuickSort(a,pos+1,h);
     
         
    }   


}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}