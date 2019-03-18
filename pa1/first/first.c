#include <stdio.h>
#include <stdlib.h>

void sort(int arr[],int length) {
	int evenCounter = 0;
	int i;
	for(i=0;i<length;i++){
		if(arr[i]%2==0){
			evenCounter++;
		}
	}
	int evens[evenCounter];
	int odds[length-evenCounter];
	int even = 0, odd = 0;
	for(i=0;i<length;i++){
		if(arr[i]%2==0){
			evens[even]=arr[i];
			even++;
		}
		else{
			odds[odd]=arr[i];
			odd++;
		}
	}
	int key, j;
	for(i=1;i<even;i++){
		key=evens[i];
		j=i-1;
		while(j>=0 && evens[j]>key){
			evens[j+1]=evens[j];
			j=j-1;
		}
		evens[j+1]=key;
	}
	for(i=1;i<odd;i++){
		key=odds[i];
		j=i-1;
		while(j>=0 && odds[j]<key){
			odds[j+1]=odds[j];
			j=j-1;
		}
		odds[j+1]=key;
	}
	for(i=0;i<even;i++){
		arr[i]=evens[i];
	}
	for(i=even;i<length;i++){
		arr[i]=odds[i-evenCounter];
	}
}

int main(int argc, char **argv) {
	FILE *file;
	file = fopen(argv[1],"r");
	int arraySize;
	fscanf(file,"%d",&arraySize);
	int arr[arraySize];
	int i;
	for (i=0;i<arraySize;i++) {
		if (i<arraySize-1) {
			fscanf(file,"%d\t",&arr[i]);
		}
		else {
			fscanf(file,"%d",&arr[i]);
		}
	}
	int p;
	sort(arr,arraySize);
	for (p=0;p<arraySize;p++) {
		printf("%d\t",arr[p]);
	}
	fclose(file);
	
}
