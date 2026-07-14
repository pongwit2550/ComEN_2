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


// ข้อ 2
int NDown(int n){
    printf("Iterative");
    while (n >= 1) {
       printf("%d  \n", n--);
    }
    printf("Exit Number of n is 1! \n");
}

void NDownR(int n){
    if (n == 1) {
        printf("Recursive  : %d", n); 
    }
    else if (n <= 0) {
        printf("Recursive is Lower that 1 : %d \n", n);
        return NDownR(n + 1);
    }else {
        printf("Recursive  : %d \n", n);
        return NDownR(n - 1);
    }
 
}


/*
// ข้อ 3
void printToN(int n){
    for(int i = 1 ; i <= n; i++){
        printf("Iterative : %d \n",i);
    }
}

void printToNR(int i , int n){
    if (i == n) {
        printf("Recursive num :  %d \n", i);
    }
    else if (i >= n) {
        
        printf("Recursive num :  %d \n", i);
        return printToNR(i - 1, n);
    }
    else {
        
        printf("Recursive num :  %d \n", i);
        return  printToNR(i + 1, n); 
    } 
    
}
 */
/*
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
    
    if (i > n) { 
        return 0; 
    }

    printf("%d\n", i);
    return i + sumToN_Recursive(i + 1, n);
}

*/


int main (){
    NDown(6);
    NDownR(5);

}