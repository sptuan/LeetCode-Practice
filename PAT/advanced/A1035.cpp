#include <iostream>
#include <stdio.h> 
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main(int argc, char** argv) {
	
	int N;
	int i,j,k;
	int counter = 0;
	
	cin>>N;
	
	string pwd[1001];
	string id[1001];
	bool modify[1001];
	for(i=0;i<1001;i++){
		modify[i] = false;
	}
	

	
	for(i=0;i<N;i++){
		cin>>id[i]>>pwd[i];
		auto it = pwd[i].begin();
		for(it; it != pwd[i].end(); it++){
			if(*it == '1'){
				*it = '@';
				modify[i] = true;

			}
			if(*it == '0'){
				*it = '%';
				modify[i] = true;

			}
			if(*it == 'l'){
				*it = 'L';
				modify[i] = true;

			}
			if(*it == 'O'){
				*it = 'o';
				modify[i] = true;

			}
			

		}
					if(modify[i] == true){
				counter++;
			}
	}
	
	if(counter != 0)
		cout<<counter<<endl;
	
	for(i = 0; i < 1001; i++){
		if(modify[i] == true){
			cout<<id[i]<<" "<<pwd[i]<<endl;
		}
	}

	if(counter == 0){
		if(N==1){
			cout<<"There is "<<N<<" account and no account is modified"<<endl;
		}
		else{
			cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
		}

	}
	
	return 0;
}
