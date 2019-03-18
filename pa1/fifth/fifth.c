#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int i,j;
	int strSize;
	char current;
	for(i=1;i<argc;i++){
		strSize=strlen(argv[i]);
		for(j=0;j<strSize;j++){
			current=argv[i][j];
			if(current=='a'||current=='e'||current=='i'||current=='o'||current=='u'||
				current=='A'||current=='E'||current=='I'||current=='O'||current=='U'){
				printf("%c",current);
			}
		}
	}
}
