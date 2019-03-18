#include <stdio.h>
#include <stdlib.h>

int get(unsigned short x, int n){
	unsigned short y = x;
	y = y>>n;
	int bitval = y&1;
	return bitval;
}

int main(int argc, char *argv[]){
	unsigned short x = atoi(argv[1]);
	int i, beg, end;
	for(i=0;i<8;i++){
		beg = get(x,i);
		end = get(x,15-i);
		if(beg!=end){
			printf("Not-Palindrome");
			return 0;
		}
	}
	printf("Is-Palindrome");
}
