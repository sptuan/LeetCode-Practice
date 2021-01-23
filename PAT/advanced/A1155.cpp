#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int tree[30000];
int N;
vector<int> ans;

void DFS(int root){
	//
	if((tree[root*2] == -1) && (tree[root*2+1] == -1)){
		ans.push_back(tree[root]);
		vector<int>::iterator a;
		for(a = ans.begin(); a!=ans.end(); a++){
			cout<<*a;
			if(a!=ans.end()-1){
				cout<<" ";
			}
		}
		cout<<endl;
		ans.pop_back();
		return;
	}
	else{
		ans.push_back(tree[root]);
		if(tree[root*2+1]!= -1){
			DFS(root*2+1);
		}
		if(tree[root*2]!= -1){
			DFS(root*2);
		}
				
			
		ans.pop_back();
		return;
	}

	
	

}



queue<int> q;

void check(int root){
	int max_flag = 0;
	int min_flag = 0;
	int equal_flag = 0;
	q.push(root);
	while(q.size()!=0){
		int temp=q.front();
		if(tree[temp*2]!=-1 && tree[temp*2]<tree[temp]){
			max_flag = 1;
		}
		if(tree[temp*2]!=-1 && tree[temp*2]>tree[temp]){
			min_flag = 1;
		}
		if(tree[temp*2+1]!=-1 && tree[temp*2+1]<tree[temp]){
			max_flag = 1;
		}
		if(tree[temp*2+1]!=-1 && tree[temp*2+1]>tree[temp]){
			min_flag = 1;
		}
		if(tree[temp*2+1]!=-1 && tree[temp*2+1]==tree[temp]){
			equal_flag = 1;
		}	
		if(tree[temp*2]!=-1 && tree[temp*2]==tree[temp]){
			equal_flag = 1;
		}	
		if(tree[temp*2]!=-1){
			q.push(temp*2);
		}
		if(tree[temp*2+1]!=-1){
			q.push(temp*2 + 1);
		}
		q.pop();
	}
	if(max_flag == 1 && min_flag == 1){
		cout<<"Not Heap"<<endl;
	}
	if(max_flag == 0 && min_flag == 1){
		cout<<"Min Heap"<<endl;
	}
	if(max_flag == 1 && min_flag == 0){
		cout<<"Max Heap"<<endl;
	}
}


int main() {
	cin>>N;
	int i,j,k;
	
	for(i=0;i<30000;i++){
		tree[i] = -1;
	}
	
	for(i=1;i<N+1;i++){
		scanf("%d",&tree[i]);
	}
	int root = 1;
	
	DFS(root);
    
	check(root);
	return 0;
}
