#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int chain[100005];
int sum[100005];
int main(){
	
	int N,M;
	cin>>N>>M;
	
	int i,j,k;
	sum[0] = 0;
	
	for(i=0;i<N;i++){
		scanf("%d",&chain[i]);
		sum[i+1] = sum[i] + chain[i];
	}
	
	int min_vaule = 99999999;
	
	int print_flag = 0;
	
	for(i=0;i<N;i++){
	
		int point;
		point = lower_bound(sum+i,sum+N+1,M+sum[i]) - sum;
		//cout<<point<<endl;
		//cout<<*point<<endl;
		//cout<<point + i<<endl;
		//cout<<*(point + i)<<endl;
		
		if(sum[point] == (M + sum[i])){
			cout<<i+1<<"-"<<point<<endl;
			print_flag = 1;
		}
		else if(sum[point] - sum[i] - M > 0){
			if(sum[point] - sum[i] - M < min_vaule){
				min_vaule = sum[point] - sum[i] - M;
				//cout<<min_vaule<<endl;
			}
		}
				
	}
	
	if(min_vaule < 99999999 && print_flag == 0){
		for(i=0;i<N;i++){
			int point;
			point = lower_bound(sum+i,sum+N+1,M + sum[i]) - sum;
			if(sum[point] - sum[i] - M == min_vaule){
				//cout<<i+1<<"-"<<endl;
				cout<<i+1<<"-"<<point<<endl;
			}	
		}
	}
	
	
	return 0;
}
