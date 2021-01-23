#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
	
	int K1,K2;
	int i,j;
	double ans[1010];
	
	for(i=0;i<1010;i++){
		ans[i] = 0;
	}
	
	cin>>K1;	
	double a1[1010];
	
	for(i=0;i<1010;i++){
		a1[i] = 0;
	}
	
	for(i = 0; i < K1; i++){
		int N;
		double a;
		cin>>N>>a;
		a1[N] = a;
		
	}

	cin>>K2;	
	double a2[1010];
	
	for(i=0;i<1010;i++){
		a2[i] = 0;
	}
	
	for(i = 0; i < K2; i++){
		int N;
		double a;
		cin>>N>>a;
		a2[N] = a;
		
	}
	
	int temp=0;
	
	for(i = 0; i < 1010; i++){
		ans[i] = a1[i] + a2[i];
		if((ans[i]>0.01) || (ans[i]<-0.01)){
			temp++;
		}
	}
	
	cout<<temp;
	
	for(i = 1009; i >= 0; i--){
		if((ans[i]>0.01) || (ans[i]<-0.01)){
			printf(" %d %.1f",i,ans[i]);
		}
	}	
	
	return 0;
}
