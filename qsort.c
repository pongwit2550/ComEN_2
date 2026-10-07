#include <stdio.h>
#include <stdlib.h>
int intArray[7] = {4, 6, 3, 2, 1, 9, 7};
void swap(int index1, int index2){
   int temp = intArray[index1];
   intArray[index1] = intArray[index2];
   intArray[index2] = temp;
}
void display(){
   for(int i=0;i<7;i++){
      printf("%d ",intArray[i]);
   }
   printf("\n");
}
int partition(int left, int right, int pivot) {
   int leftPointer = left ;
   int rightPointer = right;
   while(true) {
      while((intArray[++leftPointer] < pivot)&&(leftPointer<7))  { }		
      while(rightPointer > 0 && intArray[rightPointer] > pivot) {
         rightPointer--;
      }
      if(leftPointer >= rightPointer){
         break;
      }else{
         printf(" item swapped :%d,%d\n", 
         intArray[leftPointer],intArray[rightPointer]);
         swap(leftPointer,rightPointer);
      } }
   printf(" pivot swapped :%d,%d\n", intArray[rightPointer],intArray[left]);
   swap(rightPointer,left);
   printf("Updated Array: "); 
   display();
   return rightPointer;
}
void quickSort(int left, int right){        
   if(right-left <= 0){
      return;   
   }else {
      int pivot = intArray[left];
      int partitionPoint = partition(left, right, pivot);
      quickSort(left,partitionPoint-1);
      quickSort(partitionPoint+1,right);
   }        
}   


int main() {
    
   printf("Unsorted Array: "); 
   display();
   quickSort(0,6);
   printf("Sorted Array: "); 
   display();
   return 0;
}