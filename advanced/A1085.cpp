#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long long num[100005];

int main(){
	
	long long N,p;
	cin>>N>>p;
	
	long long i,j,k;
	for(i=0; i<N; i++){
		cin>>num[i];		
	}
	
	sort(num,num+N);
	
	int max = 0;
	
	for(i=0;i<N;i++){
		
		long long sum =num[i] * p;
		 	
		long long point = upper_bound(num+i,num+N,sum) - num;
		
		//if(point == N){
		//	
		//	break;
		//}
		
		long long temp;
		if(num[point] == sum){
			temp = point - i + 1;
		}
		else{
			temp = point - i;
		}
		
		if(temp > max){
			max = temp;
		}
		
		
	} 
	
	cout<<max<<endl;
	
	return 0;
}
