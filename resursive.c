#include <stdio.h>



    /*void printDown(int n){
        if (n <= 1 ){
            printf("%d ",n);   
            printDown(n-1);  
        }

        if (n >= 1) {
           
            printf("%d ",n);   
            printDown(n-1);
        }
    }*/


/*  ข้อ 2
int NDown(int n){
    printf("Iterative");
    while (n >= 1) {
       printf("%d  ", n--);
    }
    printf("Exit Number of n is 1!");
}

void NDownR(int n){
    if (n == 1) {
        printf("N  : %d", n); 
    }
    else if (n <= 0) {
        printf("is Lower that 1 : %d \n", n);
        return NDownR(n + 1);
    }else {
        printf("N  : %d \n", n);
        return NDownR(n - 1);
    }
 
}
*/

/* ข้อ 3
void printToN(int n){
    for(int i = 1 ; i <= n; i++){
        printf("%d",i);
    }
}

void printToNR(int i , int n){
    if (i == n) {
        printf("num :  %d \n", i);
    }
    else if (i >= n) {
       
        printf("num :  %d \n", i);
        return printToNR(i - 1, n);
    }
    else {
       
        printf("num :  %d \n", i);
        return  printToNR(i + 1, n); 
    } 

}*/

int sum ;
int instance_num = 1;
int sumToN_Iterative(int n){

  for (int i = 1; i <= n; i++) {
      sum += i;
      printf("%d \n",i);
  }
  
  return sum;

}

int sumToN_Recursive(int i, int n) {
    // Base case: stop when i reaches or passes n
    if (i > n) { 
        return 0; 
    }
    
    // Print current step
    printf("%d\n", i);
    
    // Recursive step: Add current 'i' to the sum of the rest of the numbers
    return i + sumToN_Recursive(i + 1, n);
}



int main (){

    printf("Sum of Iterativer: %d \n", sumToN_Iterative(5));

    printf("Sum of Recursive:  %d \n", sumToN_Recursive(1, 5));

}