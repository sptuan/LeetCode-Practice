#include <iostream>
#include <algorithm> 

using namespace std;


int hash_c[100005];
int hash_a[100005];


int main(int argc, char** argv) {
	int N;
	scanf("%d",&N);
	int i,j,k;
	
	for(i=0;i<100005;i++){
		hash_c[i] = -1;
	}
	
	for(i=0;i<N;i++){
		int temp1,temp2;
		scanf("%d %d",&temp1,&temp2);
		hash_c[temp1] = temp2;
		hash_c[temp2] = temp1;
	}
	
	scanf("%d",&N);
	
	int counter = 0;
	for(i=0;i<N;i++){
		int temp = 0;
		scanf("%d",&temp);
		hash_a[temp] = true;
		
	}
	
	int counter_temp = 0;
	for(i=0;i<100005;i++){
		if(hash_a[i]==true && (hash_a[hash_c[i]]==false)){
			counter++;
		}
	}
	
	cout<<counter<<endl;
	
	for(i=0;i<100005;i++){
		if(hash_a[i]==true && (hash_a[hash_c[i]]==false)){
			printf("%05d",i);
			counter_temp++;
			if(counter_temp!=counter){
				printf(" ");
			}
		}
	}
	
	
	
	return 0;
}
