#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
#define MAXN 510

using namespace std;

int G[MAXN][MAXN];
int Cmax,N,Sp,M;
int Cap[MAXN];

int d[MAXN];
bool visit[MAXN];
vector<int> pre[MAXN];

void dij(int s){
	//init
	int i,j,k;
	for(i=0;i<=N;i++){
		d[i] = INF;
	}
	
	d[s] = 0;
	//visit[s] = true;
	
	// N+1 times
	for(i=0;i<=N;i++){
		//find shortest node
		int shorts = INF;
		int short_node = -1;
		for(j=0;j<=N;j++){
			if(d[j]<shorts && visit[j] == false){
				shorts = d[j];
				short_node = j;
			}
		}
		//cout<<"Find short_node: "<<short_node<<endl;
		visit[short_node] = true;
		//update G
		for(j=0;j<=N;j++){
			//cout<<"update G: "<<j<<endl;
			if(d[short_node] + G[short_node][j] < d[j] && visit[j]==false){
				d[j] = d[short_node] + G[short_node][j];
				pre[j].clear();
				pre[j].push_back(short_node);
			}
			else if(d[short_node] + G[short_node][j] == d[j] && visit[j]==false){
				pre[j].push_back(short_node);
			}
		}
		
		
	}
	
}

int send = INF;
int recv = INF;

vector<int> temp_path;
vector<int> opt_path;

void DFS(int s){
	if(s==0){
		//cout<<"Find start0!"<<endl;
		temp_path.push_back(s);
		//opt
		int send_temp=0;
		int recv_temp=0;
		int sum = 0;
		vector<int>::iterator it;
		for(it=temp_path.begin();it!=temp_path.end();it++){
			//cout<<"caps@"<<*it<<" "<<Cap[*it] - Cmax/2<<endl;
			sum+=(Cap[*it] - Cmax/2);
		} 
		//cout<<"SUM "<<sum<<endl;
		if(-sum >=0){
			send_temp = -sum;
			recv_temp = 0;
		}
		else{
			recv_temp = sum;
			send_temp = 0;
		}

		if(send_temp<send){
			opt_path = temp_path;
			send = send_temp;
			recv = recv_temp;
		}
		else if(send_temp == send){
			if(recv_temp < recv){
				opt_path = temp_path;
				send = send_temp;
				recv = recv_temp;	
			}
		}
		
		
		temp_path.pop_back();
		return;
	}
	//cout<<"DFS @ "<<s<<endl;
	temp_path.push_back(s);
	vector<int>::iterator it;
	for(it=pre[s].begin(); it!=pre[s].end();it++){
		DFS(*it);
	}
	temp_path.pop_back();
	return;
}

int main(){
	int i,j,k;
	for(i=0;i<MAXN;i++){
		for(j=0;j<MAXN;j++){
			G[i][j]=INF;
			G[j][i]=INF;
		}
	}
	
	cin>>Cmax>>N>>Sp>>M;

	for(i=1;i<=N;i++){
		cin>>Cap[i];
	}
	

	for(i=0;i<M;i++){
		int s1,s2,t;
		cin>>s1>>s2>>t;
		G[s1][s2] = t;
		G[s2][s1] = t;
	}
	
	int s=0;
	dij(s);
	//cout<<"dij Complete"<<endl;
	
	Cap[0] = Cmax/2;
	
	DFS(Sp);
	
	cout<<send<<" ";
	vector<int>::iterator it;
	for(it=opt_path.end()-1; it!=opt_path.begin(); it--){
		cout<<*it<<"->";
	}
	cout<<*opt_path.begin()<<" "<<recv<<endl;
	
	return 0;
}
