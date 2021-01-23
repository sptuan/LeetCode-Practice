#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> ans;
vector<long long> temp;
long long N,K,P;
long long max_sum = -1;


long long display(vector<long long> temp){
	vector<long long>::iterator i;
	for(i=temp.begin();i!=temp.end();i++){
		cout<<*i<<" ";
	}
	cout<<endl;
	
	return 0;
}

bool cmp_int(long long a, long long b){

	return a>b;	
}


void DFS(long long a, long long sum, long long sum_k, long long depth){
	if((depth>=K) || (sum>=N) || (a > N)){
		if(sum == N && depth == K){
			//sort(temp.begin(),temp.end(),cmp_int);
			//ans.push_back(temp);
			//display(temp);
			if(sum_k > max_sum){
				max_sum = sum_k;
				ans = temp;
			}
		}
		return;
	}

		temp.push_back(a);
		//cout<<"Select "<<a<<endl;
		DFS(a, sum + pow(a,P), sum_k + a, depth+1);
		temp.pop_back();
		
		if(a-1>0){
			DFS(a-1, sum, sum_k, depth);	
		}



		return;
		
}

int main(){
	
	cin>>N>>K>>P;
	

	
	DFS(N,0,0,0);
	

	if(max_sum == -1){
		cout<<"Impossible"<<endl;
	}
	else{
		long long j;
		cout<<N<<" = ";
		for(j=0;j<K;j++){
			cout<<ans[j]<<"^"<<P;
			if(j!=K-1){
				cout<<" + ";
			}
		}
		cout<<endl;
	}
	return 0;
	
} 
