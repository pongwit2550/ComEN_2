#include <stdio.h>

float h = 0;
float b = 0;
float tri_area ;
float Tri_area( int b, int h );
float ans ;




int main(){  
   
    //float tri_area ;
    printf("Input Height: ");
    scanf("%f", &h);

    printf("Input Base: ");
    scanf("%f", &b);

    Tri_area(b,h);
   
    
}




float Tri_area( int b,int h ){

    //0.5 * b * h
    tri_area = (0.5 * b) * h;
    printf("Tri Area : %f\n", tri_area);

} 
