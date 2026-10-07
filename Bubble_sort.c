#include <stdio.h>
#include <stdlib.h>




void bubbleSort(int array[], int length)
{  
    int i, j, temp,test, c;
    
	for(i = length - 1; i > 0; i--){
	       test=0;
           c = 0;
	       for(j = 0; j < i; j++)  {
	           if(array[j] > array[j+1]) {
	               temp = array[j];    
	               array[j] = array[j+1];
	               array[j+1] = temp;
	               test=1;
                   c++;
	           }
	       }
           for(j = 0; j < length; j++)  {
               printf("%d ", array[j]);
        } 
            printf("\t:%d\n", c);
	       if(test==0) break; /*ออกจากฟังก์ชันเมื่อข้อมูลเรียงแล้ว*/
    } 
}


int main(){
    int wcase[5] = {28,5,3,2,1};
    int bcase[5] = {1,2,3,4,5};


    printf("Worst case : \n");
    printf("Data\t:Compare Count\n");
    bubbleSort(wcase, 5);
    printf("Best case : \n");
    printf("Data\t:Compare Count\n");
    bubbleSort(bcase, 5);
    return 0;
}

