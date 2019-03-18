#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	int value;
	struct Node *next;
};

struct Node *table[10000];
int collisions = 0;
int goodSearches = 0;

void insert(int data){
	int index=data%10000;
	if(index<0){
		index = index+10000;
	}
	int present = 0;
	struct Node *ptr;
	for(ptr=table[index];ptr!=NULL;ptr=ptr->next){
		if(ptr->value==data){
			present = 1;
			break;
		}
	}
	if(ptr==NULL){
		free(ptr);
	}
	if(present==1){
		collisions++;
		return;
	}
	struct Node *item = (struct Node*)malloc(sizeof(struct Node));
	item->key = index;
	item->value = data;
	item->next = NULL;
	if(table[index]==NULL){
		table[index]=item;
	}
	else{
		item->next=table[index];
		table[index]=item;
		collisions++;
	}
}

void search(int data){
	int index=data%10000;
	if(index<0){
		index = index+10000;
	}
	int plus = goodSearches+1;
	struct Node *ptr = table[index];
	while(ptr!=NULL&&goodSearches!=plus){
		if(ptr->value==data){
			goodSearches++;
		}
		else{
			ptr=ptr->next;
		}
	}
	if(ptr==NULL){
		free(ptr);
	}
}

void deleteLinkedList(struct Node** front){
        struct Node *ptr = *front;
        struct Node *next;
        while(ptr!=NULL){
                next=ptr->next;
                free(ptr);
                ptr=next;
        }
        *front=NULL;
}

int main(int argc, char *argv[]){
	FILE *file;
	file = fopen(argv[1],"r");
	int i;
	for(i=0;i<10000;i++){
		table[i]=NULL;
	}
	int data;
	char opt[1];
	char c;
	while(1==1){
		c=fscanf(file,"%c\t%d\n",opt,&data);
		if(c!=2){
			break;
		}
		if(opt[0]=='i'){
			insert(data);
		}
		else if(opt[0]=='s'){
			search(data);
		}
	}
	printf("%d\n%d",collisions,goodSearches);
	fclose(file);
	for(i=0;i<10000;i++){
		deleteLinkedList(&table[i]);
	}
}
