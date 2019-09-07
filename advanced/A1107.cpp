#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

set<int> hobby[1010];

int father[1010];


int N;

int isRoot[1010];

bool cmp(int a, int b){
	return a>b;
}

int findFather(int x){
	while(father[x]!=x){
		x = father[x];
	}
	return x;
}

int makeUnion(int x, int y){
	int xFather = findFather(x);
	int yFather = findFather(y);
	if(xFather != yFather){
		father[xFather] = yFather;
		isRoot[yFather]+= isRoot[xFather];
		isRoot[xFather] = 0;
	} 
	return 0;
}

int main(){
	cin>>N;
	int i,j,k;
	for(i=1;i<=N;i++){
		int counter = 0;
		scanf("%d:",&counter);
		//cin>>counter;
		for(j=0;j<counter;j++){
			int temp;
			cin>>temp;
			hobby[temp].insert(i);
		}
	}
	
	//init father
	for(i=0;i<=N;i++){
		father[i] = i;
		isRoot[i] = 1;
	}
	
	//union
	for(i=0;i<1010;i++){
		if(hobby[i].size()>1){
			set<int>::iterator it;
			for(it=hobby[i].begin();it!=hobby[i].end();it++){
				makeUnion(*(hobby[i].begin()),*it);
				//cout<<"makeUnion:"<<*(hobby[i].begin())<<" + "<<*it<<endl;
			}
		}
	}
	
	isRoot[0] = 0;
	
	sort(isRoot,isRoot+1010,cmp);
	int sum=0;
	for(i=0;i<1010;i++){
		if(isRoot[i]!=0){
			sum++;
		}
	}
	cout<<sum<<endl;
	for(i=0;i<sum;i++){
		cout<<isRoot[i];
		if(i!=sum-1){
			cout<<" ";
		}
	}
	return 0;
}
