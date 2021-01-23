#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct cake{
	double ton;
	double price;
}cakes[1001];

bool cmp(cake a, cake b){
	return a.price>b.price;
}

int main(){
	int N;
	double D;
	cin>>N>>D;
	int i,j,k;
	
	for(i=0;i<N;i++){
		cin>>cakes[i].ton;
	}
	for(i=0;i<N;i++){
		cin>>cakes[i].price;
	}
	for(i=0;i<N;i++){
		cakes[i].price = cakes[i].price / cakes[i].ton;
	}
	sort(cakes,cakes+N,cmp);
	
	i = 0;
	double total = 0;
	while(D>0 && i<N){
		if(cakes[i].ton >= D){
			total += cakes[i].price * double(D);
			D = 0;	
			//cout<<"Sell "<<i<<" "<<D<<"ton, price"<<cakes[i].price<<endl;
		}
		else{
			total += cakes[i].price * double(cakes[i].ton);
			D -= cakes[i].ton;
			//cout<<"Sell "<<i<<" "<<cakes[i].price<<"ton, price"<<cakes[i].price<<endl;
		}
		i++;
	}
	
	printf("%.2f",total);
	
	return 0;
	
} 
