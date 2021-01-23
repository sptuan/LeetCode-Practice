#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int i[9];
int cout_flag = 0;

int voice(int n){
	if(n==0){
		cout<<"ling";
	}
	if(n==1){
		cout<<"yi";
	}	
	if(n==2){
		cout<<"er";
	}
	if(n==3){
		cout<<"san";
	}	
	if(n==4){
		cout<<"si";
	}
	if(n==5){
		cout<<"wu";
	}
	if(n==6){
		cout<<"liu";
	}
	if(n==7){
		cout<<"qi";
	}	
	if(n==8){
		cout<<"ba";
	}
	if(n==9){
		cout<<"jiu";
	}	
	return 0;
}

int yi(int num){
	if(i[8]!=0){
		voice(i[8]);
		cout<<" Yi";
	}
	
		
	int zero_flag = 0;
	
	if(i[7]==0){
			zero_flag ++;	
		}
	else{
		cout<<" ";
		voice(i[7]);
		cout<<" Qian";
	}

	if(i[6]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0){
			cout<<" ling";
			zero_flag = 0;
		}
		cout<<" ";
		voice(i[6]);
		cout<<" Bai";
	}
	
	if(i[5]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0){
			cout<<" ling";
			zero_flag = 0;
		}
		cout<<" ";
		voice(i[5]);
		cout<<" Shi";
	}
	if(i[4]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0){
			cout<<" ling";
			zero_flag = 0;
		}
		cout<<" ";
		voice(i[4]);
		zero_flag = 0;
	}
	if(zero_flag == 4){
		cout<<" ling";
	}
	else{
		cout<<" Wan";	
	}
	zero_flag = 0;


	
	if(i[3]==0){
			zero_flag ++;	
		}
	
	else{
		cout<<" ";
		voice(i[3]);
		cout<<" Qian";
	}

	if(i[2]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0){
			cout<<" ling";
			zero_flag = 0;
		}
		cout<<" ";
		voice(i[2]);
		cout<<" Bai";
	}
	
	if(i[1]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0){
			cout<<" ling";
			zero_flag = 0;
		}
		cout<<" ";
		voice(i[1]);
		cout<<" Shi";
	}
	if(i[0]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0){
			cout<<" ling";
			zero_flag = 0;
		}
		cout<<" ";
		voice(i[0]);
		zero_flag = 0;
	}
}


int wan(int num){

	
		
	int zero_flag = 0;
	
	if(i[7]==0){
			zero_flag ++;	
		}
	else{
		if(cout_flag == 0){
			cout_flag = 1;
		}
		else{
			cout<<" ";
		}

		voice(i[7]);
		cout<<" Qian";
	}

	if(i[6]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0 && zero_flag != 1){
			cout<<" ling";
			zero_flag = 0;
		}
		if(cout_flag == 0){
			cout_flag = 1;
		}
		else{
			cout<<" ";
		}
		voice(i[6]);
		cout<<" Bai";
	}
	
	if(i[5]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0  && zero_flag != 2){
			cout<<" ling";
			zero_flag = 0;
		}
		if(cout_flag == 0){
			cout_flag = 1;
		}
		else{
			cout<<" ";
		}
		voice(i[5]);
		cout<<" Shi";
	}
	if(i[4]==0){
		zero_flag ++;	
	}
	else{
		if(zero_flag!=0 && zero_flag != 3){
			cout<<" ling";
			zero_flag = 0;
		}
		if(cout_flag == 0){
			cout_flag = 1;
		}
		else{
			cout<<" ";
		}
		voice(i[4]);
		zero_flag = 0;
	}
	if(zero_flag == 4){

