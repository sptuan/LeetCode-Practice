//#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct node{
	int data;
	node *lchild = NULL;
	node *rchild = NULL;
}; 

node *create(int data){
	node *root = new node;
	root->data = data;
	return root;
}

int N;

//vector<int> raw;
int raw[1010];
queue<node*> q;


node *create_tree(int a, int b){
	if(a>=b){
		return NULL;
	}
	if(a<0 || b>N){
		return NULL;
	}

	
	node *root = new node;
	int total = b - a;
	
	
	int layers = -1;
	int maxn = 0;
	int comp_flag = 0; 
	while(maxn < total){
		layers ++;
		maxn += pow(2,layers);
		if(maxn == N){
			comp_flag = 1;
		}
	}
	
	//cout<<"layers: "<<layers<<endl;
	//cout<<"maxn:  "<<maxn<<endl;
	
    
	int lnum = 0;
	int rnum = 0;
	if(comp_flag == 0){
		int maxn_temp = maxn - pow(2,layers);
		int last_layer = pow(2,layers);
		int rest = total - maxn_temp;
		//cout<<"rest:  "<<rest<<endl;
		if(rest>last_layer/2){
			lnum = maxn_temp/2 + last_layer/2;
			rnum = maxn_temp/2 + rest - last_layer/2;
		} 
		else{
			lnum = maxn_temp/2 + rest;
			rnum = maxn_temp/2;
		}
	}
	else{
		lnum = maxn / 2;
		rnum = maxn / 2;
	}
	//cout<<"lnum:"<<lnum<<"  rnum:"<<rnum<<endl;
	root->data = raw[a+lnum];
    
	//root->data = 0;
	//cout<<"Find data:"<<raw[a+lnum]<<endl;
	root->lchild = create_tree(a,a+lnum);
    
	//cout<<"PUSH L:"<<a<<":"<<a+lnum<<endl;
	root->rchild = create_tree(a+lnum+1,b);
	//cout<<"PUSH R:"<<a+lnum+1<<":"<<b<<endl;
	//cout<<"------"<<endl;
    return root;
}

void BFS(node *root){
	q.push(root);
	
	while(q.size()!=0){
		printf("%d",q.front()->data);
		if(q.front()->lchild!=NULL){
			q.push(q.front()->lchild);
		}
		if(q.front()->rchild!=NULL){
			q.push(q.front()->rchild);
		}
		q.pop();
		if(q.size()!=0){
			//cout<<" ";
			printf(" ");
		}
	}
	//cout<<endl;
	printf("\n");
}

int main(){
	//cin>>N;
	scanf("%d",&N);
	int i,j,k;
	for(i=0; i<N; i++){
		int temp;
		scanf("%d",&temp);
		//raw.push_back(temp);
		raw[i] = temp;
	}	
	sort(raw,raw+N);
	
	/*
	vector<int>::iterator a;
	for(a=raw.begin();a!=raw.end();a++){
		cout<<*a<<" ";
	}*/
	

	
	node *root = create_tree(0,N);
	BFS(root);
	

	
	
	
	
	return 0;
}
