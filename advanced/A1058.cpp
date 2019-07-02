#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// A1058
using namespace std;

int main(int argc, char** argv) {
	int a,b,c;
	int A,B,C;
	
	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&A,&B,&C);
	
	a = a + A;
	b = b + B;
	c = c + C;
	
	if(c > 28){
		b += c / 29;
		c = c % 29;
	}
	if(b > 16){
		a += b / 17;
		b = b % 17;
	}
	
	printf("%d.%d.%d",a,b,c);
	
	
	return 0;
}
