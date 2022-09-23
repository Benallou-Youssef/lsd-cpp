#include<stdio.h>
#include<stdlib.h>

void checkmsb(int num){
    
    if((num>>31)&1)
        printf("msb is set\n");
    
    else
        printf("msb is not set\n");
    
    return;
}


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


void print_nth_byte(int n,int m){
    if(n>4 || n<1){
    	
    	printf("There's only 4 bytes in an int, please retry using a number between 1 and 4.\n");
        exit(EXIT_FAILURE);}
        
        print_bits(m>>(8*(n-1)));
        return;
}
