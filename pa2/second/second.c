#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	unsigned short x = atoi(argv[1]);
	int counter = 0;
	int i;
	int one = 0;
	int numones = 0;
	int bitval;
	for(i=0;i<16;i++){
		bitval = x&1;
		x = x>>1;
		if(bitval==1){
			numones++;
			if(one==0){
				one++;
			}
			else{
				counter++;
				one = 0;
			}
		}
		else{
			one = 0;
		}
	}
	unsigned short count = numones;
	if((count&1)==1){
		printf("Odd-Parity\t%d",counter);
	}
	else{
		printf("Even-Parity\t%d",counter);
	}
}
