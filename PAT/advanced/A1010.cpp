#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

char int2str(long long int a){
	if(a>=0 && a<=9){
		return '0'+a;
	}
	else{
		return 'a' + a -10;
	}
}

long long int pows(long long a, long long u){
	long long i;
	long long temp = a;
	for(i = 0;i<u;i++){
		a = a*temp;
	}
	return a;
}

int main(){
	
	string N1,N2;
	
	cin>>N1>>N2;
	
	long long tag,radix;
	cin>>tag>>radix;
	
	if(tag == 2){
		string temp_N1 = N1;
		N1 = N2;
		N2 = temp_N1;
	}
	string::iterator i;
	
	long long sum=0;
	
	long long counter = 0;
	
	for(i = N1.end()-1; i!=(N1.begin()-1); i-- ){
		if(*i>='0' && *i<='9'){
			sum+=(*i - '0')*pow(radix,counter);
			//cout<<sum<<endl;
		}
		if(*i>='a' && *i<='z'){
			sum+=((*i - 'a')+10)*pow(radix,counter);
		}		
		counter++;
	}	
	
	string out[38];
	
	long long j;
	
	int print_flag = 0;
	
	if(sum == 0){
		if(N2 == "0"){
			cout<<"2"<<endl;
			print_flag = 1;
		}
	}
	
	else{
		
	
	for(j = 2; j <= 36; j++){
		long long temp = sum;
		
		
		while(temp>0){
			char a = int2str(temp % j);
			string temp_a = "";
			temp_a += a;
			out[j]= temp_a + out[j];
			temp = temp / j;
		}
		//cout<<out[j]<<endl;
		if(out[j] == N2){
			cout<<j<<endl;
			print_flag = 1;
			break;
		}
		
	}
	
	if(print_flag == 0)
	{
		cout<<"Impossible"<<endl;
	}
	
	
	
	}
	return 0;
}
