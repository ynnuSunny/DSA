#include<bits/stdc++.h>
using namespace std;

class DynamicArray{
   private:
    int size;
    int currentIndex;
    int *a;

   public:
    DynamicArray(int size){
       this->size = size;
       this->currentIndex = 0;
       this->a = new int(size);
    }
    void add(int n){
       if(size<=currentIndex){
           size*=2;
           int newArray[size];
           for(int i=0;i<size/2;i++){
               newArray[i] = this->a[i];
           }
          
           this->a = new int(size);
           for(int i=0;i<size/2;i++){
               a[i] = newArray[i];
           }
           //cout<<currentIndex<<endl;
           a[currentIndex] = n;
           currentIndex++;
       }else{
          a[currentIndex] = n;
          currentIndex++;
       }
    }
    void print(){
      for(int i=0;i<currentIndex;i++){
        cout<<a[i]<<" ";
      }
    }
    int getSize(){
        return this->size;
    }
};

int main(){
  DynamicArray a(3);
  a.add(5);
  a.add(10);
  a.add(8);
  a.add(50);
  a.add(80);
  a.print();
}