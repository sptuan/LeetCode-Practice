#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
	int tempA[101];
	int pointA = 0;
	int tempB[101];
	int pointB = 0;
	int bitA,bitB;
	int it_int = 0;
	int point_int = 0;
	
int main(){
	int N;
	string A,B;
	cin>>N>>A>>B;
	
	int zeroA = 0;
	int zeroB = 0;

	
	string::iterator it,point_it;
	for(it=A.begin(); it!=A.end(); it++){
		if(*it!='0'&&*it!='.'){
			break;
		}
		it_int++;
	}
	
	if(it == A.end()){
		zeroA = 1;
	}	
	for(point_it=A.begin(); point_it!=A.end(); point_it++){
		
		if(*point_it=='.'){
			break;
		}
		point_int++;
	}	
	if(point_int - it_int> 0){
		bitA = point_int - it_int;
	}
	else{
		bitA = point_int - it_int + 1;
	}
	//cout<<"bitA"<<bitA<<endl;
	
	
	int i,j,k;

	
	for(i=0;i<N;i++){
		if(it == A.end()){
			break;
		}
		if(*it!='.'){
			tempA[pointA] = *it - '0';
			pointA++;
			it++;}	
		else{
			i--;
			it++;
		}

	}
	
	
	if(zeroA == 1){
		bitA = 0;
	}
	
	it_int = 0;
	point_int = 0;
	for(it=B.begin(); it!=B.end(); it++){
		if(*it!='0'&&*it!='.'){
			break;
		}
		it_int++;
	}
	
	
	
	if(it == B.end()){
		zeroB = 1;
	}
	
	for(point_it=B.begin(); point_it!=B.end(); point_it++){
		
		if(*point_it=='.'){
			break;
		}
		point_int++;
	}	
	if(point_int - it_int> 0){
		bitB = point_int - it_int;
	}
	else{
		bitB = point_int - it_int + 1;
	}
	//cout<<"bitB"<<bitB<<endl;
	
	
	for(i=0;i<N;i++){
		if(it == B.end()){
			break;
		}
		if(*it!='.'){
			tempB[pointB] = *it - '0';
			pointB++;
			it++;}	
		else{
			i--;
			it++;
		}


	}
	
	if(zeroB == 1){
		bitB = 0;
	}
	
	int flag = 0;
	if(bitA==bitB){
		for(i=0;i<N;i++){
			if(tempA[i] != tempB[i]){
				flag = 1;
				break;
			}
		}
	}
	else{
		flag = 1;
	}
	
	if(flag == 0){
		cout<<"YES ";
		

		
		{
			cout<<"0.";
			for(i=0;i<N;i++){
				cout<<tempA[i];
			}
			cout<<"*10^"<<bitA<<endl;
		}

	}
	else{
		cout<<"NO ";
		
		
		{
			cout<<"0.";
			for(i=0;i<N;i++){
				cout<<tempA[i];
			}
			cout<<"*10^"<<bitA;
		}		
		
		cout<<" ";
		

		
		{
			cout<<"0.";
			for(i=0;i<N;i++){
				cout<<tempB[i];
			}
			cout<<"*10^"<<bitB<<endl;
		}
		
	}
	
	return 0;
	
}
