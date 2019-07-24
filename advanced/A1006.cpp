#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	string id;
	string in_id;
	string out_id;
	
	int	in_temp[3] = {99,99,99};
	int out_temp[3] = {0,0,0};
	
	int in[3];
	int out[3];
	
	int i;
	for(i=0;i<n;i++){
		// scan
		cin>>id;
		scanf("%d:%d:%d",&in[0],&in[1],&in[2]);
		scanf("%d:%d:%d",&out[0],&out[1],&out[2]);
		
		// confirm in time
		
		if((in[0]<in_temp[0]) || ((in[0]==in_temp[0]) && (in[1]<in_temp[0])) 
			|| ((in[0] == in_temp[0]) && (in[1] == in_temp[1] && in[2] < in_temp[2])))
			{
				in_id = id;
				in_temp[0] = in[0];
				in_temp[1] = in[1];
				in_temp[2] = in[2];
			}
			
		if((out[0]>out_temp[0]) || ((out[0]==out_temp[0]) && (out[1]>out_temp[0])) 
			|| ((out[0] == out_temp[0]) && (out[1] == out_temp[1] && out[2] > out_temp[2])))
			{
				out_id = id;
				out_temp[0] = out[0];
				out_temp[1] = out[1];
				out_temp[2] = out[2];
			}
			
	}
	
	cout<<in_id<<" "<<out_id;
	
	
	
	return 0;
}

