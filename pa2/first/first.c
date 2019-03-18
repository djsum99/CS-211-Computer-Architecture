#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get(unsigned short x, int n){
	unsigned short y = x;
	int bitval = (y>>n)&1;
	return bitval;
}

unsigned short set(unsigned short x, int n, int v){
	if(v==1){
		return (1<<n)|x;
	}
	else{
		return ~(1<<n)&x;
	}
}

unsigned short comp(unsigned short x, int n){
	int bitval = get(x,n);
	if(bitval==0){
		return set(x,n,1);
	}
	else{
		return set(x,n,0);
	}
}

int main(int argc, char *argv[]){
	FILE *file;
	file = fopen(argv[1],"r");
	int x;
	fscanf(file,"%d\n",&x);
	unsigned short y = x;
	int n,v;
	char str[10];
	char c;
	while(1==1){
		c=fscanf(file,"%s\t%d\t%d\n",str,&n,&v);
		if(c!=3){
			break;
		}
		if(strcmp(str,"get")==0){
			printf("%d\n",get(y,n));
		}
		else if(strcmp(str,"comp")==0){
			y = comp(y,n);
			printf("%u\n",y);
		}
		else if(strcmp(str,"set")==0){
			y = set(y,n,v);
			printf("%u\n",y);
		}
	}
	fclose(file);
}
