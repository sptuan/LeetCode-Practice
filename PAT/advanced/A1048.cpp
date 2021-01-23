#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int coins[100005];
int hash1[5000] = {0};

int main(){
	int N,K;
	cin>>N>>K;
	
	int i,j,k;
	for(i = 0; i < N; i++){
		scanf("%d",&coins[i]);
		hash1[coins[i]]++;
	}
	
	sort(coins,coins+N);
	
	int print_flag = 0;
	for(i = 0; i < N; i++){
		//cout<<coins[i];
		hash1[coins[i]]--;
		
		if(hash1[K-coins[i]] > 0){
			cout<<coins[i]<<" "<<K - coins[i]<<endl;
			print_flag = 1;
			hash1[coins[i]]++;
			break;
		}
		hash1[coins[i]]++;
	}	
	
	if(print_flag == 0){
		cout<<"No Solution"<<endl;
	}
	
	 
	
	return 0;
} 
