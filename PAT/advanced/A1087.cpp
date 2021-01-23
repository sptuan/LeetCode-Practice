#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

#define INF 1000000000
using namespace std;


int n,k;
int N;

map<string,int> s2i;
string i2s[205];
int hp[205];
int cost[205][205];
int d[205];
bool visit[205];
vector<int> pre[205];
int counter = 0;

//DFS
int optvalue1 = 0;
int optvalue2 = 0;
vector<int> optpath;
vector<int> temppath;

void dij(int s){
	//init
	int i,j,k;
	for(i=0;i<205;i++){
		d[i] = INF;
	}
	d[s] = 0;
	
	
	//N times
	for(i=0;i<N;i++){
		//find shortest node
		
		int shorts = INF;
		int short_node = -1;
		for(j=0;j<N;j++){
			if(d[j] < shorts && visit[j] == false){
				shorts = d[j];
				short_node = j;
			}
		}
		
		visit[short_node] = true;
		//cout<<"find shortest node:"<<short_node<<endl;
		if(short_node == -1){
			return;
		}
		
		//update graph
		for(j=0;j<N;j++){
			if(cost[short_node][j]!=INF && visit[j]==false){
				if(d[short_node]+cost[short_node][j]<d[j]){
					d[j] = 	d[short_node]+cost[short_node][j];
					pre[j].clear();
					pre[j].push_back(short_node);
				}
				else if(d[short_node]+cost[short_node][j]==d[j]){
					pre[j].push_back(short_node);
				}
			}
		}
		
	}
	
	return;
}


void DFS(int s){
	if(s==0){
		counter++;
		temppath.push_back(0);
		//caculate opt vaule
		vector<int>::iterator it = temppath.begin();
		int total_hp = 0;
		int avg_hp = 0;
		for(it = temppath.begin(); it!=temppath.end();it++){
			total_hp+=hp[*it];
		}
		avg_hp = total_hp / (temppath.size()-1);
		
		if(total_hp>optvalue1){
			optpath=temppath;
			optvalue1 = total_hp;
			optvalue2 = avg_hp;
		}
		else if(total_hp == optvalue1){
			if(avg_hp > optvalue2){
				optpath=temppath;
				optvalue2 = avg_hp;
			}
		}
		
		temppath.pop_back();
		return;
	}
	
	temppath.push_back(s);
	vector<int>::iterator it;
	for(it = pre[s].begin();it!=pre[s].end();it++){
		DFS(*it);
	}
	temppath.pop_back();
	return;
	
}


int main(){

	string start_city;
	cin>>n>>k>>start_city;
	s2i[start_city] = 0;
	i2s[0] = start_city;
	N=n;
	int i,j;
	
	//init
	for(i=0;i<205;i++){
		for(j=0;j<205;j++){
			cost[i][j] = INF;
		}
	}
	
	//cin
	for(i=1;i<n;i++){
		string city;
		int hps;
		cin>>city>>hps;
		s2i[city] = i;
		i2s[i] = city;
		hp[i] = hps;
		//cout<<"HP"<<endl;
	}
	//cout<<"COST"<<endl;
	for(i=0;i<k;i++){
		//cout<<"COST"<<endl;
		string city1,city2;
		int costs;
		cin>>city1>>city2>>costs;
		cost[s2i[city1]][s2i[city2]] = costs;
		cost[s2i[city2]][s2i[city1]] = costs;
	}
	
	int s = 0;
	
	//cout<<"--- start DIJ ---"<<endl;
	dij(s);
	DFS(s2i["ROM"]);
	
	cout<<counter<<" "<<d[s2i["ROM"]]<<" "<<optvalue1<<
			" "<<optvalue2<<endl;
			
	vector<int>::iterator it;
	for(it=optpath.end()-1;it!=optpath.begin();it--){
		cout<<i2s[*it]<<"->";
	}
	cout<<i2s[*optpath.begin()];
	
	return 0;
} 
