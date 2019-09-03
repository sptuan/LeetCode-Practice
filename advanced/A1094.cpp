#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> child[100005];

int N;

int root;

int layer[100005];
int layer_counter[100005];

int main(){
	int K;
	//cin>>N>>K;
	scanf("%d %d",&N,&K);
	//cout<<N<<" "<<K<<endl;
	int i,j,k;
	for(i=0;i<K;i++){
		int id,num;
		scanf("%d",&id);
		scanf("%d",&num);
		//cout<<id<<num<<endl;
		for(j=0;j<num;j++){
			int temp;
			scanf("%d",&temp);
			//cout<<"scan "<<temp<<endl; 
			child[id].push_back(temp);
		}
	}
	
	int point = 1;
	int max_layer = 1;
	int max_layer_counter = 1;
	layer[1]++;
	layer_counter[1]++;
	
	queue<int> q;
	q.push(point);
	
	while(q.size()!=0){
		point = q.front();
		q.pop();
		
		vector<int>::iterator a;
		for(a=child[point].begin();a!=child[point].end();a++){
			q.push(*a);
			layer[*a] = layer[point]+1;
			layer_counter[layer[*a]]++;
			if(layer_counter[layer[*a]]>max_layer_counter){
				max_layer_counter = layer_counter[layer[*a]];
				max_layer = layer[*a];
			}
			
		}
		
		
	}
	
	cout<<max_layer_counter<<" "<<max_layer<<endl;
	
	return 0;
}
