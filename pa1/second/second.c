#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *newNode(int data){
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	n->data=data;
	n->next=NULL;
	return n;
}

struct Node *insert(struct Node *front, int data){
	if(front==NULL){
		front = newNode(data);
	}
	else{
		struct Node *ptr = front->next, *prev = front;
		struct Node *newOne = newNode(data);
		while(ptr!=NULL){
			if(ptr->data>newOne->data){
				prev->next=newOne;
				newOne->next=ptr;
				break;
			}
			else{
				prev=ptr;
				ptr=ptr->next;
			}
		}
		if(ptr==NULL){
			prev->next=newOne;
			free(ptr);
		}
	}
	return front;
}

struct Node *delete(struct Node *front, int data){
	if(front==NULL){
		free(front);
		return NULL;
	}
	if(front->data==data){
		struct Node *next = front->next;
		free(front);
		return next;
	}
	struct Node *ptr = front->next, *prev = front;
	while(ptr!=NULL){
		if(ptr->data==data){
			prev->next=ptr->next;
			free(ptr);
			return front;
		}
		else{
			prev=ptr;
			ptr=ptr->next;
		}
	}
	return front;
}

struct Node *onlyUnique(struct Node *front){
	int data;
	struct Node *noDups=NULL;
	struct Node *ptr;
	int counter = 0;
	for(ptr=front;ptr!=NULL;ptr=ptr->next){
		counter++;
	}
	int i;
	while(front!=NULL){
		data = front->data;
		noDups = insert(noDups,data);
		for(i=0;i<counter;i++){
			front = delete(front,data);
		}
	}
	return noDups;
}

struct Node *sortFirst(struct Node *front){
	int data = front->data;
	struct Node *newy = front->next;
	free(front);
	struct Node *newOne = newNode(data);
	struct Node *ptr=newy->next, *prev=newy;
	while(ptr!=NULL){
		if(ptr->data>data){
			newOne->next=ptr;
			prev->next=newOne;
			break;
		}
		else{
			prev=ptr;
			ptr=ptr->next;
		}
	}
	if(ptr==NULL){
		prev->next=newOne;
		free(ptr);
	}
	return newy;
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
	struct Node *node = NULL;
	int data;
	char opt[1];
	char c;
	while(1==1){
		c=fscanf(file,"%c\t%d\n",opt,&data);
		if(c!=2){
			break;
		}
		if(opt[0]=='i'){
			node = insert(node,data);
		}
		else if(opt[0]=='d'){
			node = delete(node,data);
		}
	}
	if(node!=NULL){
		if(node->next!=NULL){
			if(node->data>node->next->data){
				node = sortFirst(node);
			}
		}
	}
	struct Node *ptr;
	int counter = 0;
	for(ptr=node;ptr!=NULL;ptr=ptr->next){
		counter++;
	}
	printf("%d\n",counter);
	node = onlyUnique(node);
	for(ptr=node;ptr!=NULL;ptr=ptr->next){
		if(ptr->next==NULL){
			printf("%d",ptr->data);
		}
		else{
			printf("%d\t",ptr->data);
		}
	}
	fclose(file);
	deleteLinkedList(&node);
}
