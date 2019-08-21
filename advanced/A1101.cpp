#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long num[100005];
long long max_num[100005];
long long min_num[100005];

long long ans[100005];
int ans_point = 0;

int main(){
	int N;
	scanf("%d",&N);
	int i,j,k;
	
	long long min_temp = 1000000001;
	long long max_temp = -1;
	
	for(i=0;i<N;i++){
		
		scanf("%d",&num[i]);
		if(num[i] > max_temp){
			max_temp = num[i];
		}
		max_num[i] = max_temp;
		
	}
	
	for(i=0;i<N;i++){
		if(num[N-i-1] < min_temp){
			min_temp = num[N-i-1];
		}
		min_num[N-i-1] = min_temp;
	}
	
	for(i=0;i<N;i++){
		int left_flag = 0;
		int right_flag = 0;
		
		if(N!=1){
			if(i==0){
				if(min_num[i+1] < num[i]){
					right_flag = 1;
				}
			}
			else if(i==N-1){
				if(max_num[i-1] > num[i]){
					left_flag = 1;
				}
			}
			else{
				if(min_num[i+1] < num[i]){
					right_flag = 1;
				}
				if(max_num[i-1] > num[i]){
					left_flag = 1;
				}	
			}
		}
		
		if(left_flag == 0 && right_flag == 0){
			ans[ans_point] = num[i];
			ans_point++;
		}
		
	}
	
	//cout<<ans_point<<endl;
	printf("%d\n",ans_point);
	sort(ans,ans+ans_point);
	for(i=0;i<ans_point;i++){
		//cout<<ans[i];
		printf("%d",ans[i]);
		if(i!=ans_point-1){
			//cout<<" ";
			printf(" ");
		}
	}
	cout<<endl;
	
	
	return 0;
	
	
}
