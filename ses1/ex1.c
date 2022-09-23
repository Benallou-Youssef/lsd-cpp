#include<stdio.h>
#include<stdlib.h>

void checkmsb(int num){
    
    if((num>>31)&1)
        printf("msb is set\n");
    
    else
        printf("msb is not set\n");
    
    return;
}

void main(){

    printf("Choose a number to know if it's MSB is set or not : ");
    
    int x;
    scanf("%d",&x);
    
    checkmsb(x);
    return ;
}
