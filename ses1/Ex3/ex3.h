#include<stdio.h>
#include<stdlib.h>

//	Prototypes :	//

void checkmsb(int);

void print_bits(unsigned char);


//	Functions :	//

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
