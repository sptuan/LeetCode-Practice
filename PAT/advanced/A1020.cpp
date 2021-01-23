#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int post[35];
int in[35];

struct node{
	int data;
	node *lchild;
	node *rchild;
};

node* create(int posta, int postb, int ina, int inb){
	if(posta>=postb || ina >= inb){
		return NULL;
	}
	if(posta<0 || postb>N || ina<0 || inb>N){
		return NULL;
	}
	
	node *root =new node;
	root->data = post[postb-1];
	
	int i=0;
	for(i=ina;i<inb;i++){
		if(in[i] == post[postb-1]){
			break;
		}
	}
	root->rchild = create(postb-1-(inb-i-1),postb-1,i+1,inb);
	root->lchild = create(posta,posta+(i-ina),ina,i); 
	return root;
}


void DFS(node *root){
	queue<node*> q;
	q.push(root);
	
	while(q.size() != 0){
		node *temp;
		temp = q.front();
		q.pop();
		if(temp->lchild!=NULL){
			q.push(temp->lchild);
		}
		if(temp->rchild!=NULL){
			q.push(temp->rchild);
		}
		cout<<temp->data;
		
		if(q.size()!=0){
			cout<<" ";
		}
	}
	return;	
}

int main(){
	cin>>N;
	int i,j,k;
	for(i = 0; i<N; i++){
		scanf("%d",&post[i]);
	}
	for(i = 0; i<N; i++){
		scanf("%d",&in[i]);
	}	
	
	node *root=create(0,N,0,N);
	DFS(root);
	
	return 0;
}
