#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int data;
	struct Node *left, *right;
};

struct Node *newNode(int val){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data=val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct Node *insert(struct Node *n, int val){
	if(n==NULL){
		return newNode(val);
	}
	if(val<n->data){
		n->left = insert(n->left,val);
	}
	else if(val>n->data){
		n->right = insert(n->right,val);
	}
	return n;
}

void inorderTraversal(struct Node *root){
	if(root!=NULL){
		inorderTraversal(root->left);
		printf("%d\t",root->data);
		inorderTraversal(root->right);
	}
}

void deallocate(struct Node *root){
	if(root!=NULL){
		deallocate(root->right);
		deallocate(root->left);
		free(root);
	}
}

int main(int argc, char *argv[]){
	FILE *file;
	file = fopen(argv[1],"r");
	if(file==NULL){
		printf("error");
		return 0;
	}
	int data;
	char opt[1];
	char c;
	struct Node *root = NULL;
	while(1==1){
		c = fscanf(file,"%c\t%d\n",opt,&data);
		if(c!=2){
			break;
		}
		if(opt[0]=='i'){
			root = insert(root,data);
		}
	}
	inorderTraversal(root);
	fclose(file);
	deallocate(root);
	
}
