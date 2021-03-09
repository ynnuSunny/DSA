#include<stdio.h>

int main(){


  int rowOfA,collumOfA,rowOfB,collumOfB;
   printf("Enter 1st matrix row and column : ");
  scanf("%d%d",&rowOfA,&collumOfA);

   int a[rowOfA][collumOfA];
  printf("Enter a %d * %d Matrix \n",rowOfA,collumOfA);
  for(int i=0;i<rowOfA;i++){
    for(int j=0;j<collumOfA;j<j++){
        scanf("%d",&a[i][j]);
    }
  }
  printf("Enter 2nd matrix row and column : ");
  scanf("%d%d",&rowOfB,&collumOfB);
  printf("Enter a %d * %d Matrix \n",rowOfB,collumOfB);
  int b[rowOfB][collumOfB];
  for(int i=0;i<rowOfB;i++){
    for(int j=0;j<collumOfB;j++){
        scanf("%d",&b[i][j]);
    }
  }
  if(collumOfA==rowOfB){
        int multi[rowOfA][collumOfB];
    for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        multi[i][j]=0;
        //we can also use collum of B also beacouse those are same.
        for(int k=0;k<rowOfB;k++){
            multi[i][j] += a[i][k]*b[k][j];
        }
    }

  }
  printf("Matrix Multiplication is : \n");
  for(int i=0;i<rowOfA;i++){
    for(int j=0;j<collumOfB;j++){
        printf("%d ",multi[i][j]);
    }
    printf("\n");
  }
  }
  else printf("Multiplication is not possible .:-(\n");

  }

