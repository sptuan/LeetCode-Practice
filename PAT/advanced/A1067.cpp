#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int num[100001];

int main(){
	
	int N;
	cin>>N;
	
	int point0;
	int OK = 0;
	
	int i,j;
	for(i=0; i<N; i++){
		scanf("%d",&num[i]);
		if(num[i] == 0){
			point0 = i;
		}
		if(num[i] == i){
			OK++;
		}
	}
	
	int swap_counter = 0;



	while(OK<(N-1)){
		
		if(num[0] == 0){
			for(j=0; j<N; j++){
				if(num[j]!=j){
					int temp;
					temp = num[j];
					num[j] = 0;
					num[point0] = temp;
					point0 = j;
					swap_counter++;
					break;
				}
			}
		}
		
		while(num[0] != 0){
			int swap_point;
			for(i=0;i<N;i++){
				if(num[i] == point0){
					swap_point = i;
					break;
				}
			}
			
			int temp;
			temp = num[swap_point];
			num[swap_point] = 0;
			num[point0] = temp;
			
			point0 = i;
			swap_counter++;
			OK++;

		}
		
		
	}

	
	cout<<swap_counter;
	return 0;
}
