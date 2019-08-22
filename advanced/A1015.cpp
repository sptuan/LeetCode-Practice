#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

bool prime_hash[100050] = {false};

void prime(){
	int i,j,k;
	prime_hash[0] = true;
	prime_hash[1] = true;
	
	
	
	for(i=2;i<100010;i++){
		if(prime_hash[i] == false){
			k = 2;
			j = k*i;
			while(j<100010){
				prime_hash[j] = true;
				k++;
				j = k*i;
			}
		}	
	}
}

int main(){
	prime();
	int i,j,k;
	
	while(1){
		int N,D;
		scanf("%d",&N);
		if(N<0){
			//cout<<"No"<<endl;
			return 0;
		}
		scanf("%d",&D);
		
		if(prime_hash[N] == true){
			cout<<"No"<<endl;
		}
		else{
		
		
			//bits?
			int count = 0;
			int temp_N = N;
			while(temp_N>0){
				count++;
				temp_N = temp_N/10;
			}
			
			//radix
			int output[100000];
			int point = 0;
			temp_N = N;
			while(temp_N>0){
				output[point] = temp_N % D;
				temp_N = temp_N/D;
				point++;
			}
			
			
			//reverse
			int rev = 0;
			for(i=0;i<point;i++){
				rev += output[i] * pow(D,point-i-1);
			}
			
			if(prime_hash[rev] == false){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		
		}
	}
	
	return 0;
}
