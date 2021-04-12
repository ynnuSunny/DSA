#include<stdio.h>


int binary_search(int a[],int n,int x){

     int left,right,mid;
     left=0;
     right=n-1;

     while(left<=right){
          mid = (left+right)/2;
         if(a[mid]==x){
            return mid+1;
         }
         if(a[mid]<x){
            left = mid+1;
         }
         else{
            right = mid-1;
         }

     }

return 0;}

int main(){

    int a[21]={1,2,4,5,8,9,10,15,16,18,20,22,25,26,28,29,30,63,85,95,100};
     int value = binary_search(a,21,98);
     printf("%d",value);
return 0;}
