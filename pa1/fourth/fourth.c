#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int r1, c1, r2, c2;
	FILE *file;
	file = fopen(argv[1],"r");
	fscanf(file,"%d",&r1);
	fscanf(file,"%d",&c1);
	int *mat1 = (int*)malloc(r1*c1*sizeof(int));
	int i;
	for(i=0;i<r1*c1;i++){
		fscanf(file,"%d",&mat1[i]);
	}
	fscanf(file,"%d",&r2);
	fscanf(file,"%d",&c2);
	if(r2!=c1){
		printf("bad-matrices");
		return 0;
	}
	int *mat2 = (int*)malloc(r2*c2*sizeof(int));
	for(i=0;i<r2*c2;i++){
		fscanf(file,"%d",&mat2[i]);
	}
	int *final = (int*)malloc(r1*c2*sizeof(int));
	int productsum = 0;
	int finalCounter = 0;
	int j,k;
	for(i=0;i<r1;i++){
		for(k=0;k<c2;k++){
			for(j=0;j<c1;j++){
				productsum = productsum+mat1[c1*i+j]*mat2[k+c2*j];
			}
			final[finalCounter]=productsum;
			finalCounter++;
			productsum=0;
		}
	}
	finalCounter=0;
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			if(i==r1-1&&j==c2-1){
				printf("%d",final[finalCounter]);
			}
			else if(j==c2-1){
				printf("%d\n",final[finalCounter]);
				finalCounter++;
			}
			else{
				printf("%d\t",final[finalCounter]);
				finalCounter++;
			}
		}
	}
	fclose(file);
	free(mat1);
	free(mat2);
	free(final);
}
