#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> course[2505];


int main(){
	int N,K;
	cin>>N>>K;
	
	int i;
	for(i=0; i<N; i++){
		string name;
		char temp[5];
		int j,k;
		scanf("%s",&temp);
		name.append(temp);
		//cout<<name<<endl;
		//cin>>name>>k;
		scanf("%d",&k);
		
		for(j=0; j<k; j++){
			int course_id;
			scanf("%d",&course_id);
			course[course_id].push_back(name);
		}
		
		
		//cout<<"----------"<<endl;
	}
	
	
	for(i=1;i<=K;i++){
		//cout<<i<<" "<<course[i].size()<<endl;
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end());
		vector<string>::iterator it;
		for(it = course[i].begin(); it != course[i].end(); it++){
			//cout<<*it<<endl;
			printf("%s\n",(*it).c_str()); 
		}
	}
	
	
		
	return 0;
}
