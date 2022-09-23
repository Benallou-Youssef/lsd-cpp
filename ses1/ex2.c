#include<stdio.h>
#include<stdlib.h>


void print_bits(unsigned char byte){
    
    int bits = 8*sizeof(unsigned char);
    unsigned char one = 1 << bits-1;
    
    for(int i=0; i<bits; i++){
        
        if(byte & one)
            printf("1");
        
        else
            printf("0");
        
        one = one >> 1;
    }
    
    printf("\n");
    return;
}

void main(){

    printf("Enter a number between 0 and 255 to get it's binary form : ");
    
    unsigned char x;
    scanf("%hhu",&x);
    
    print_bits(x);
    return;
}
