#include <iostream>
#include <stdio.h>
#include <stack>
#include <math.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int a;
	int b;
	
	scanf("%d %d",&a,&b);
	
	int sum;
	sum = a + b;
	
	//cout<<sum<<endl;
	
	stack<int> st;
	

	
	int counter = 0;
	do{
		counter++;
		st.push(abs(sum%10));
		sum = sum/10;
		if(counter%3 == 0 && (counter / 3)!=0){
			st.push(-11);
		}
	}while(sum!=0);
	
	if(a+b<0)
	{
		cout<<"-";
	}
	
	int i=0;
	int N = st.size();
	for(i=0; i<N; i++){
		
		int temp = st.top();
		st.pop();
		if(temp == -11 ){
			if(i!=(0))
				cout<<",";
		}
		else{
			cout << temp;
		}
	}
	
	
		
	return 0;
}
