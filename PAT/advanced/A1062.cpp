#include <iostream>
#include <cstdio>
#include <algorithm>
#define SAGE 1
#define NOBLE 2
#define FOOL 3
#define SMALL 4
#define OTHER 5
using namespace std;

struct node{
	int id;
	int V;
	int T;
	int type;
	int total;
}user[100009];

bool cmp(node a,node b){
	if(a.total == b.total){
		
		if(a.V == b.V){
			return a.id<b.id;
		}
		else{
			return a.V>b.V;
		}
			
	}
	else{
		return a.total>b.total;
	}
}

int main(){
	int N,L,H;
	cin>>N>>L>>H;
	
	int temp = 0;
	
	int i;
	for(i = 0; i < N; i++){
		int V,T;
		cin>>user[i].id>>V>>T;
		user[i].V = V;
		user[i].T = T;
		
		user[i].total = user[i].V + user[i].T;
		
		if(V>=L && T>=L){
			temp++;
			
			if(V >= H && T >= H){
				user[i].type = SAGE;
			}
			else if(V >= H && T<=H){
				user[i].type = NOBLE;
			}
			else if(V<=H && T<=H){
				
				if(V>=T){
					user[i].type = FOOL;
				}
				else{
					user[i].type = SMALL;
				}
				
				
			}
			else{
				user[i].type = SMALL;
			}
			
		}
		else{
			user[i].type = OTHER;
		}
		

	}
	
	sort(user,user+N,cmp);
	
	cout<<temp<<endl;
	for(i=0;i<N;i++){
		if(user[i].type == SAGE){
			cout<<user[i].id<<" "<<user[i].V<<" "<<user[i].T<<endl;
		}
	}
	for(i=0;i<N;i++){
		if(user[i].type == NOBLE){
			cout<<user[i].id<<" "<<user[i].V<<" "<<user[i].T<<endl;
		}
	}

	for(i=0;i<N;i++){
		if(user[i].type == FOOL){
			cout<<user[i].id<<" "<<user[i].V<<" "<<user[i].T<<endl;
		}
	}
	
	for(i=0;i<N;i++){
		if(user[i].type == SMALL){
			cout<<user[i].id<<" "<<user[i].V<<" "<<user[i].T<<endl;
		}
	}
	
	return 0;
		
}
