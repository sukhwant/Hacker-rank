#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;	
	int visible;
};

// Supporting Functions //
int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}

// Basic Tree Functions //
void insert(struct node** root,int data){
	if(*root==NULL){
		struct node *temp=NULL;
		temp=(struct node*) malloc(sizeof(struct node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		temp->visible=0;
		*root=temp;
		return;
	}
	
	if((*root)->data>data){
		insert(&((*root)->left),data);
	}
	else{
		insert(&((*root)->right),data);
	}
}

struct node* search(struct node* tree,int key){
	
	if(key==tree->data){
		struct node *temp=tree;
		return temp;
	}
	
	else if( tree->right!=NULL && key>tree->data){
		return search(tree->right,key);
	}
	else if(tree->left!=NULL){
		return search(tree->left,key);
	}
	return NULL;
}

void preOrder(struct node* root){
	printf("%d\t",root->data);
	if(root->left!=NULL){
		preOrder(root->left);
	}
	if(root->right!=NULL){
		preOrder(root->right);
	}
}

void postOrder(struct node* root){
	if(root->left!=NULL){
		postOrder(root->left);
	}
	if(root->right!=NULL){
		postOrder(root->right);
	}
	printf("%d\t",root->data);
}

void inOrder(struct node* root){
	if(root->left!=NULL){
		inOrder(root->left);
	}
	printf("%d\t",root->data);
	if(root->right!=NULL){
		inOrder(root->right);
	}
}

int height(struct node* root){
	
	if(root==NULL)
		return 0;
	
	return max(height(root->left),height(root->right))+1;
}

//  light question - light coming from right, which all nodes will be visible. //
void nodeVisible(struct node** root,int value,int* count){
	if((*root)==NULL)
		return;
	
	if(value==0){
		printf("%d\n",(*root)->data);
		(*root)->visible=1;
		(*count)++;
		int leftChild_height = height((*root)->left);
		int rightChild_height = height((*root)->right);
		nodeVisible(&((*root)->right),0,&(*count));
		if(rightChild_height<leftChild_height){
			nodeVisible(&((*root)->left),rightChild_height,&(*count));
		}
	}
	else{
		(*root)->visible=0;
		int leftChild_height = height((*root)->left);
		int rightChild_height = height((*root)->right);
		nodeVisible(&((*root)->right),value-1,&(*count));
		if(rightChild_height<leftChild_height){
			int val=max(rightChild_height,value-1);
			nodeVisible(&((*root)->left),val,&(*count));
		}
	}
}

int visibleCount(struct node** root){
	int count=0;
	nodeVisible(&(*root),0,&count);
	return count;
}

/* complete binary tree question - check whether a tree is complete binary tree or not
	all element should have two child or no child or only left child which must be a leaf.
*/
int completeBinary(struct node* root){
	if(root==NULL)
		return 0;
	//printf("%d\n",root->data);
	if((root->right!=NULL) && (root->left==NULL)){
		//printf("only right child\n");
		return 1;
	}
	if((root->left!=NULL) && (root->right==NULL)){
		if(root->left->left!=NULL || root->left->right!=NULL){
			//printf("Only left but left child is not leaf\n");
			return 1;
		}
	}
	else{
		//printf("calling for child\n");
		if(completeBinary(root->left)==1 || completeBinary(root->right)==1)
			return 1;
		else
			return 0;
	}
}

// Question - leaf nodes sum//
void findSum(struct node* root,int* sum){
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
		*sum += root->data;
	findSum(root->left,&(*sum));
	findSum(root->right,&(*sum));
}
int leafSum(struct node* root){
	int sum=0;
	findSum(root,&sum);
	return sum;
}
// Utility program //
int main(){
	struct node* tree=NULL;
	
	int data[]={50,20,300,200,500,10,40,30,150,35},n=9,i;
	for(i=0;i<n;i++)
		insert(&tree,data[i]);
	
	//inOrder(tree);
	// struct node* temp = search(tree,5);
	
	// if(temp!=NULL)
		// printf("Found  %d\n",temp->data);
	// else
		// printf("Not Found\n");
	
	//printf("%d\n",height(tree));
	
	//printf("\ntotal visible: %d\n",visibleCount(&tree));
	
	printf("%d\n",leafSum(tree));
	
	return 0;
}
