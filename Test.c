#include <stdio.h>

int main () {

     float sum = 0; 
     float sumflowerprice[255] = {};
     float average;
     int cout; 
     
     printf(" จะขายกี่รอบ:  ");
     scanf("%d", &cout);

     if (cout <= 0) {
         printf("จำนวนรอบต้องมากกว่า 0\n");
         return 1;
     }
     if (cout > 255) {
         printf("จำกัดจำนวนรอบสูงสุดที่ 255 รอบ\n");
         cout = 255;
     }

     for(int i = 1 ; i <= cout; i++ ){
         printf("ลูกค้าคนที่ %d \n" , i);
         scanf("%f", &sumflowerprice[i - 1]);
     }

     
     for(int i = 1; i <= cout; i++ ){
         sum += sumflowerprice[i - 1];
     }

     float expensive = sumflowerprice[0];
     float cheap = sumflowerprice[0];

     
     
     for(int j = 0; j < cout; j++ ){

         if(sumflowerprice[j] > expensive) {
             expensive = sumflowerprice[j];
         }

         if (sumflowerprice[j] < cheap) { 
             cheap = sumflowerprice[j];
         }
        
         
         // printf("check expensive in loop %f \n", expensive);
         // printf("check cheap in loop %f \n", cheap);        
     }
    
     average = sum / cout;
   
     printf("SUM: %f \n", sum);
     printf("Expensive: %f \n", expensive);
     printf("Cheap: %f \n", cheap);
     printf("Average: %f \n", average);

     return 0;
}
