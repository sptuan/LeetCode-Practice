#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
int weight[1005];
int ranks[1005];

int main(){
	int Np,Ng;
	
	weight[1003] = -1;
	
	cin>>Np>>Ng;
	//int total;
	
	int i,j,k;
	for(i=0; i<Np; i++){
		scanf("%d",&weight[i]);
	}
	
	queue<int> q;
	for(i=0;i<Np;i++){
		int temp;
		scanf("%d",&temp);
		q.push(temp);		
	}
	
	/*
	if(Np%Ng != 0){
		total = Np/Ng*Ng + Ng;
		for(i=Np; i<total; i++){
			weight[i] = -1;
		}
	}
	else{
		total = Np;
	}*/
	
	
	int total = Np;
	int group;
	if(Np%Ng !=0){
		group = Np / Ng + 1;
	}
	else{
		group = Np/Ng;
	}
	
	
	
	while(group!= 0){
		//cout<<"start while Qsize"<<q.size()<<endl;
		if(total % Ng !=0){
			for(i=0;i<Ng - total % Ng;i++){
				q.push(1003);
				//cout<<"push 1003"<<endl;
			}
		}
		
		for(i =0 ;i < group; i++){
			int temp[Ng];
			for(j = 0; j< Ng; j++){
				temp[j] = q.front();
				//cout<<"Qsize"<<q.size()<<endl;
				if(q.size() == 0){
					return 1;
				}
				q.pop();
			}
			int max_temp = 0;
			int max_temp_point = 0;
			for(j = 0; j< Ng; j++){
				if(weight[ temp[j] ]>=max_temp){
					max_temp = weight[temp[j]];
					max_temp_point = temp[j];
				}
			}
			
			q.push(max_temp_point);
			
			for(j = 0; j< Ng; j++){
				if(weight[ temp[j] ]!=max_temp){
					ranks[temp[j]] = group + 1;
				}
			}	
			
				
		}
		total = group;
		
		if(total==1){
			break;
		}
		if(total%Ng !=0){
			group = total / Ng + 1;
		}
		else{
			group = total / Ng;
		}
	}
	ranks[q.front()] = 1;
	
	for(i=0;i<Np ; i++){
		cout<<ranks[i];
		if(i!=(Np-1)){
			cout<<" ";
		}
	}
	cout<<endl;
	
	
	
	return 0;
}
