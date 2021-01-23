#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int main(){
	
	int N;
	cin>>N;
	int dis[N];
	
	int i;
	for(i=0; i<N; i++){
		scanf("%d",&dis[i]);
	}
	
	int M;
	cin>>M;
	for(i=0; i<M; i++){
		int a,b;
		cin>>a>>b;
		a = a-1;
		b = b-1;
		int temp1=0;
		int temp2=0;
		
		int j;
		for(j = a; j%N != b; j++){
			temp1 += dis[j%N];
			//cout<<" temp1 "<<temp1;
		}
		//cout<<temp1<<endl;
		
		for(j = b; j%N != a; j++){
			temp2 += dis[j%N];
			//cout<<" j="<<j;
			//cout<<" temp2 "<<temp2;
		}		
		
		if(temp1>temp2){
			printf("%d",temp2);
			if(i!=(M-1)){
				printf("\n");
			}
		}
		else{
			printf("%d",temp1);
			if(i!=(M-1)){
				printf("\n");
			}
		}
		
	}
	
	return 0;
	
} 
