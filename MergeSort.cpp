#include<bits/stdc++.h>
using namespace std;



void MergeDisneding(int a[],int l,int m,int r){
    int nL,nR;
    nL = m-l+1;
    nR = r-m;
    int L[nL],R[nR];
    for(int i=0;i<nL;i++)
        L[i] = a[l+i];
    for(int i=0;i<nR;i++)
        R[i] = a[m+1+i];
    int i=0,j=0,k=l;
    while(i<nL && j<nR){ // O(n)
        if(L[i]>R[j]){
            a[k++] = L[i++];
        }
        else{
            a[k++] = R[j++];
        }
    }
    while(i<nL){
        a[k++]=L[i++];
    }
    while(j<nR){
        a[k++]=R[j++];
    }

}

void MergeAssending(int A[],int l,int m,int h){
    int nL,nR;
      nL = m-l+1;//find the total size of Left Array
      nR = h-m;//find the total size of Right Array
    int L[nL],R[nR];
    for(int i=0;i<nL;i++){
        L[i] = A[l+i]; // Assign Left Array value in L[nL]
    }
    for(int i=0;i<nR;i++){
        R[i] = A[m+1+i];//Assign Right Array value.
    }
    int i=0;//index of left array L[nL]
    int j=0;//index of Right Array R[nR]
    int k=l;//index of main Array A[]
    //Assing the value in Assending order
    while(i<nL && j<nR){ 
        if(L[i]<R[j]){
            A[k++]=L[i++];
        }
        else{
            A[k++]=R[j++];
        }

    }
    //Assing the rest of the value of L[nL];
    while(i<nL){
        A[k++]=L[i++];
    }
    //Assing the rest of the value of R[nR];
    while(j<nR){
        A[k++]=R[j++];
    }

}


void MegreSort(int A[],int l,int h){
     if(l<h){
        int m = l + (h-l)/2;//to find mid
        //For divide the array
        MegreSort(A,l,m); 
        MegreSort(A,m+1,h);
        //Call one of them
        MergeDisneding(A,l,m,h);
       // MergeAssending(A,l,m,h);
     }
     else return;
}

// 1 2 2 2 3 4 4 5 6 6 7 8 9 

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    MegreSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


}