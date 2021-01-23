#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int lchild[10];
int rchild[10];
int root;
bool hasht[10];
int N = 0;

int counter = 0;

void inorder(int root){
	if(root == -1){
		return;
	}
	inorder(rchild[root]);
	cout<<root;
	counter++;
	if(counter != N){
		cout<<" ";
	}
	inorder(lchild[root]);
	return;
}

int main(){
	cin>>N;
	
	int i;
	for(i=0;i<N;i++){
		char a,b;
		cin>>a>>b;
		//scanf("%c%*c%c%*c%*c",&a,&b);
		if(a == '-'){
			lchild[i] = -1;
		}
		else{
			lchild[i] = a -'0';
			hasht[a - '0'] = true;
		}
		if(b == '-'){
			rchild[i] = -1;
		}
		else{
			rchild[i] = b -'0';
			hasht[b - '0'] = true;
		}
	}
	for(i=0;i<N;i++){
		if(hasht[i] == false){
			root = i;
			break;
		}
	}
	
	//cout<<"---- start layer\n";
	
	queue<int> q;
	q.push(root);
	while(q.size()!=0){
		int temp=q.front();
		cout<<temp;
		q.pop();
		if(rchild[temp]!=-1){
			q.push(rchild[temp]);
		}
		if(lchild[temp]!=-1){
			q.push(lchild[temp]);
		}
		if(q.size()!=0){
			cout<<" ";
		}
	}
	cout<<endl;
	
	
	//cout<<"---- start inorder\n";
	inorder(root);
	
	return 0;
}
