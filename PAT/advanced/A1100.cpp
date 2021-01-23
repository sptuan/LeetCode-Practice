#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<int,string> int2stringL;
map<string,int> string2intL;
map<int,string> int2stringH;
map<string,int> string2intH;


void init(){
	int2stringL[0] = "tret";
	int2stringL[1] = "jan";
	int2stringL[2] = "feb";
	int2stringL[3] = "mar";
	int2stringL[4] = "apr";
	int2stringL[5] = "may";
	int2stringL[6] = "jun";
	int2stringL[7] = "jly";
	int2stringL[8] = "aug";
	int2stringL[9] = "sep";
	int2stringL[10] = "oct";
	int2stringL[11] = "nov";
	int2stringL[12] = "dec";
	string2intL["tret"] = 0;
	string2intL["jan"] = 1;
	string2intL["feb"] = 2;
	string2intL["mar"] = 3;
	string2intL["apr"] = 4;
	string2intL["may"] = 5;
	string2intL["jun"] = 6;
	string2intL["jly"] = 7;
	string2intL["aug"] = 8;
	string2intL["sep"] = 9;
	string2intL["oct"] = 10;
	string2intL["nov"] = 11;
	string2intL["dec"] = 12;
	string2intL["tre"] = 0;
	
	int2stringH[0] = "tret";
	int2stringH[1] = "tam";
	int2stringH[2] = "hel";
	int2stringH[3] = "maa";
	int2stringH[4] = "huh";
	int2stringH[5] = "tou";
	int2stringH[6] = "kes";
	int2stringH[7] = "hei";
	int2stringH[8] = "elo";
	int2stringH[9] = "syy";
	int2stringH[10] = "lok";
	int2stringH[11] = "mer";
	int2stringH[12] = "jou";
	string2intH["tam"] = 1;
	string2intH["hel"] = 2;
	string2intH["maa"] = 3;
	string2intH["huh"] = 4;
	string2intH["tou"] = 5;
	string2intH["kes"] = 6;
	string2intH["hei"] = 7;
	string2intH["elo"] = 8;
	string2intH["syy"] = 9;
	string2intH["lok"] = 10;
	string2intH["mer"] = 11;
	string2intH["jou"] = 12;
	string2intH["tret"] = 0;
}



int main(){
	init();
	int N;
	scanf("%d",&N);
	int i;
	for(i = 0; i<N; i++){
		string X;
		//cout<<"--------"<<endl;
		getline(cin,X);
		if(X==""){
			i--;
			continue;
		} 
		//cout<<X<<" -- "<<endl;
		if((X[0]<='9') && X[0]>='0'){
			int temp = 0 ;
			string::iterator it;
			for(it = X.begin(); it!=X.end(); it++){
				temp = temp*10;
				temp += *it - '0';
			}
			
			//cout<<temp<<endl;
			//radix
			//cout<<int2stringH[2]<<endl;
			if(temp/13>0){
				cout<<int2stringH[temp/13];
				if(temp%13!=0){
					cout<<" "<<int2stringL[temp%13]<<endl;
				}
				else{
					cout<<endl;
				}
			}
			else{
				cout<<int2stringL[temp%13]<<endl;
			}
			
		}
		
		else{
			int temp = 0;


			string X1 = X.substr(0,3);
			if(string2intH.find(X1)!=string2intH.end()){
				temp = temp*13;
				temp += string2intH[X1];
				temp = temp*13;	
				//string X1;
				//cin>>X1;
				if(X.size()>=5){
					temp += string2intL[X.substr(4,3)];	
				}
				
			}
			else{
				temp += string2intL[X1];
			}
			
			cout<<temp<<endl;
			
		}
		

		
		
	}
	
	return 0;
}
