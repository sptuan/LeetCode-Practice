#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> child[100005];

int N;
double price;
double rate;
int root;

int layer[100005];

int main(){
	cin>>N>>price>>rate;
	int i,j,k;
	for(i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		if(temp != -1){
			child[temp].push_back(i);
			//cout<<"PUSH"<<endl;
		}
		else{
			root = i;
			//cout<<"ROOT"<<endl;
		}
	}
	int counter = 0;
	int point;
	queue<int> q;
	q.push(root);
	layer[root] = 1;
	
	int max_layer = 1;
	int max_layer_counter = 1;
	
	while(q.size()!=0){
		point = q.front();
		//cout<<point<<endl;
		q.pop();
		vector<int>::iterator a;
		for(a=child[point].begin(); a!=child[point].end();a++){
			//cout<<"Push "<<*a<<endl;
			q.push(*a);
			layer[*a] = layer[point]+1;
			
			
			if(layer[*a]>max_layer){
				max_layer = layer[*a];
				max_layer_counter = 1;
			}
			else if(layer[*a]==max_layer){
				max_layer_counter++;
			}
		}
	}
	double max=price*pow(1+rate/100,max_layer-1);
	//cout<<"max "<<max_layer<<" counter"<<max_layer_counter<<endl;	
	printf("%.2f %d\n",max,max_layer_counter);
	return 0;
	
}
