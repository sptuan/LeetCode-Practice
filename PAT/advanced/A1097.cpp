#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

struct node{
	int num;
	int next;
}nodes[100005];
bool hasht[10005];

int node_delete(int pre, int point){
	nodes[pre].next = nodes[point].next;
	return 0;
}

int main(){
	
	int start,N;
	cin>>start>>N;
	
	int start2 = -1;
	int point = -1;
	int point2 = -1;
	int pre = -1;
	int pre2 = -1;
	
	int i ,j ,k;
	for(i = 0; i < N; i++){
		int address,value,next_address;
		cin>>address>>value>>next_address;
		nodes[address].num = value;
		nodes[address].next = next_address;
	}
	
	point = start;
	
	while(point != -1){
		if(hasht[abs(nodes[point].num)] == false){
			hasht[abs(nodes[point].num)] = true;
			//cout<<"Hash"<<nodes[point].num<<"   OK"<<endl;
			pre = point;
			point = nodes[point].next;
			
			
		}
		else{
			//delete
			//cout<<"delete "<<point<<endl;
			//cout<<"next point"<<nodes[point].next;
			nodes[pre].next = nodes[point].next;
			nodes[point].next = -1;
			
			//add
			if(start2 == -1){
				start2 = point;
				point2 = point;
			}
			else{
				nodes[point2].next = point;
				point2 = point;
			}
			
			point = nodes[pre].next;
			
		}
		
	}
	
	point = start;
	while(point != -1){
		//cout<<point<<" "<<nodes[point].num<<" "<<nodes[point].next<<endl;
		if(nodes[point].next!= -1){
			printf("%05d %d %05d\n",point,nodes[point].num,nodes[point].next);
		}
		else{
			printf("%05d %d %d\n",point,nodes[point].num,nodes[point].next);
		}
		
		point = nodes[point].next;
	}
	
	point = start2;
	while(point != -1){
		if(nodes[point].next!= -1){
			printf("%05d %d %05d\n",point,nodes[point].num,nodes[point].next);
		}
		else{
			printf("%05d %d %d\n",point,nodes[point].num,nodes[point].next);
		}		//cout<<point<<" "<<nodes[point].num<<" "<<nodes[point].next<<endl;
		point = nodes[point].next;
	}	
	
	
	return 0;
} 
