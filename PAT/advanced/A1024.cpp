#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int bign1[100005];
int bign2[100005];
int point1 = 0;
int point2 = 0;

void plusplus(){
	int i;
	for(i=0;i<100005;i++){
		int temp = bign1[i] + bign2[i];
		if(temp>9){
			bign1[i+1]++;
			if(i==point1-1){
				point1++;
			}
		}
		bign1[i] = temp % 10;
	}
}

void rev(){
	int i;
	point2 = point1;
	for(i=0;i<point1;i++){
		bign2[i] = bign1[point1-1-i];
	}
}

bool check(){
	int i = 0;
	bool flag = true;
	for(i=0; i<point1/2; i++){
		if(bign1[i] != bign1[point1 - 1 -i]){
			flag = false;
			break;
		}
	}
	return flag;
}

int main(){
	string  N;
	int K;
	cin>>N>>K;
	
	string::iterator a;
	for(a=N.begin(); a!=N.end(); a++){
		bign1[point1] = *a - '0';
		point1++;
	}
	int counter = 0;
	
	while((check()==false)&&counter<K){
		rev();
		
		plusplus();
		
		counter++;
	}
	
	int i;
	for(i = point1 - 1; i>=0;i--){
		cout<<bign1[i];
	}
	
	cout<<endl<<counter<<endl;
	
	
	
	
	
	
	
	return 0;
	
}
