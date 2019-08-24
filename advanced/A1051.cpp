#include <iostream>
#include <cstdio>
#include <algorithm>

#include <stack>

using namespace std;

int main(){
	int M,N,K;
	
	int i,j;
	
	cin>>M>>N>>K;
	
	for(i=0;i<K;i++){
		int temp[N];
		for(j=0;j<N;j++){
			scanf("%d",&temp[j]);
		}
		stack<int> st;
		
		int point = 1;
		int flag = 0;
		for(j=0;j<N;j++){
			if(temp[j]>=point){
				while(point!=(temp[j]+1)){
					st.push(point);
					point++;
				}
			}
			//cout<<"st.size "<<st.size()<<endl;
			if(st.size() > M){
				cout<<"NO"<<endl;
				flag = 1;
				break;
			}
			
			else if(st.top() != temp[j]){
				cout<<"NO"<<endl;
				flag = 1;
				break;
			}
			else{
				//cout<<"st.top "<<st.top()<<endl;
				st.pop();
			}
			
		}
		if(flag == 0){
			cout<<"YES"<<endl;
		}
		
	}
	return 0;
} 
