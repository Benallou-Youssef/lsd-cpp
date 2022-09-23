#include"ex3.h"

void main(){

	printf("Choose a number to know if it's MSB is set or not : ");
	
	int x;
	scanf("%d",&x);
	
	checkmsb(x);
	
	printf("Enter a number between 0 and 255 to get it's binary form : ");
	
	unsigned char y;
	scanf("%hhu",&y);
	
	print_bits(y);
	
	return;
}
	
	
