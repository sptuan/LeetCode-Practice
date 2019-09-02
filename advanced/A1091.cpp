#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int s[60][1286][128];
bool hashs[60][1286][128];
queue<int> l,m,n;


int M,N,L,T;

int acute = 0;

void DFS(int i, int j, int k){
	
	int counter = 0;
	
	if(s[i][j][k] == 1 && hashs[i][j][k] == false){
		l.push(i);
		m.push(j);
		n.push(k);
		hashs[i][j][k] = true;
	}
	else{
		return;
	}
	while(l.size()!=0){
		i = l.front();
		l.pop();
		j = m.front();
		m.pop();
		k = n.front();
		n.pop();
		//cout<<"Mark "<<i<<" "<<j<<" "<<k<<endl;
		
		counter++;
		
		//i-
		if(i-1 >=0){
			if(s[i-1][j][k] == 1 && hashs[i-1][j][k] == false){
				l.push(i-1);
				m.push(j);
				n.push(k);
				hashs[i-1][j][k] = true;
			}	
		}
		//i+
		if(i+1 <L){
			if(s[i+1][j][k] == 1 && hashs[i+1][j][k] == false){
				l.push(i+1);
				m.push(j);
				n.push(k);
				hashs[i+1][j][k] = true;
			}	
		}
		
		//j-
		
		if(j-1 >= 0){
			if(s[i][j-1][k] == 1 && hashs[i][j-1][k] == false){
				l.push(i);
				m.push(j-1);
				n.push(k);
				hashs[i][j-1][k] = true;
			}	
		}
		
		//j+
		if(j+1 <M){
			if(s[i][j+1][k] == 1 && hashs[i][j+1][k] == false){
				l.push(i);
				m.push(j+1);
				n.push(k);
				hashs[i][j+1][k] = true;
			}	
		}
		
		//k-
		
		if(k-1 >= 0){
			if(s[i][j][k-1] == 1 && hashs[i][j][k-1] == false){
				l.push(i);
				m.push(j);
				n.push(k-1);
				hashs[i][j][k-1] = true;
			}	
		}
		//k+
		if(k+1 <N){
			if(s[i][j][k+1] == 1 && hashs[i][j][k+1] == false){
				l.push(i);
				m.push(j);
				n.push(k+1);
				hashs[i][j][k+1] = true;
			}	
		}
		
	}
	
	if(counter >= T){
		acute += counter;
	}
	
	//cout<<"Finished!!"<<endl;
	return;
}

int main(){
	cin>>M>>N>>L>>T;
	int i,j,k;
	for(i=0;i<L;i++){
		for(j=0;j<M;j++){
			for(k=0;k<N;k++){
				scanf("%d",&s[i][j][k]);				
			}
		}
	}
	
	
	for(i=0;i<L;i++){
		for(j=0;j<M;j++){
			for(k=0;k<N;k++){
				DFS(i,j,k);					
			}
			
		}
	}
	
	cout<<acute<<endl;
	return 0;
}
