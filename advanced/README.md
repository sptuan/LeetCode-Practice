<h1>PAT应试解题纪录&amp;笔记 - Advanced</h1>
[toc depth="2]

&nbsp;
<h2>资料/博客存放</h2>
&nbsp;

<h2>解题纪录-Advanced</h2>
<div class="problemListItem_2867x">
<div class="problem_2tXnk">
<h3>7 Data Structure</h3>
<h4>1051 Pop Sequence （25 分）</h4>
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output:
YES
NO
NO
YES
NO

</div>
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;stack&gt;
using namespace std;


int main() {
	int m,n,k;
	int i,j;
	cin&gt;&gt;m&gt;&gt;n&gt;&gt;k;
	
	for(i = 0; i &lt; k; i++){
		stack&lt;int&gt; st;
		int num2push = 1;
		int flag = 0;
		for(j = 0; j &lt; n; j++){
			int temp;
			cin&gt;&gt;temp;
			if(st.empty()){
				do{
					st.push(num2push);
					num2push++;
				}while(st.top() != temp);
				
				if(st.size()&gt;m){
					flag = 1;
				}
					
				st.pop();
			}
			else{
				if(st.empty()){
					flag = 1;
					break;
				}
				else{
				
					if(temp &gt; st.top()){
						do{
							st.push(num2push);
							num2push++;
						}while(st.top() != temp);
						st.pop();
					}
					else{
						if(st.top() == temp){
							st.pop();
						}
						else{
							flag = 1;
							
						}
					}
				}
			}
			if(st.size()&gt;m){
				flag = 1;
			}
			

		}
		if(!st.empty()){
			flag = 1;
		}
		if(flag == 0){
			cout&lt;&lt;"YES"&lt;&lt;endl;
		}
		else{
			cout&lt;&lt;"NO"&lt;&lt;endl;
		}
		
;//		cout&lt;&lt;"Line Finshed! i="&lt;&lt;i&lt;&lt;endl; 
		
	}

	return 0;
}</pre>
&nbsp;

</div>
注：此题使用了STL实现栈；用模拟的方法实现；目前还是有一组测试用例无法通过，只获得了23分；

原因待查中，书上有更简洁的实现方法；




<h4>1056 Mice and Rice （25 分）</h4>
Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

First the playing order is randomly decided for N​P​​ programmers. Then every N​G​​ programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every N​G​​ winners are then grouped in the next match until a final winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N​P​​ and N​G​​ (≤1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than N​G​​ mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains N​P​​ distinct non-negative numbers W​i​​ (i=0,⋯,N​P​​−1) where each W​i​​ is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,⋯,N​P​​−1 (assume that the programmers are numbered from 0 to N​P​​−1). All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

Sample Output:
5 5 5 2 5 5 5 3 1 3 5
<pre class="lang:default decode:true">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;queue&gt;
#include &lt;algorithm&gt;
using namespace std;

/*
1. 用结构体存储状态，只用队列保存排序状态（queue int)来节省内存和操作时间。
2. 找出可以持续迭代的条件 ：  队列不等于空
3. 排名为每次选出的人数+1 

最开始部分答案超时 全部改为scanf后仍然超时。
其他用例在3ms左右，应该为死循环了，而不是cout cin带来的时间损耗。 
*/
struct mice_struct{
	int weight;
	int rank;
};

bool cmp(mice_struct a, mice_struct b){
	return a.rank&gt;b.rank;
}

int main() {
	int n,m;
	cin&gt;&gt;n&gt;&gt;m;
	mice_struct mice[n];
	int i,j;
	for(i=0;i&lt;n;i++){
		scanf("%d",&amp;mice[i].weight);
	}
	queue&lt;int&gt; qe;
	for(i=0;i&lt;n;i++){
		int temp;
		scanf("%d",&amp;temp);
		qe.push(temp);
	}
	//已经获得竞赛队列qe
	
	while(qe.size()!=0){
		int round = 0;
		int rest = 0;
		//开始计算需要进行的回合数
		//最开始忘了整除情况的rest，因为最后一回合依据是rest，已改正 
		if((qe.size()%m) == 0){
			round = qe.size() / m;
			rest = m;
		}
		else{
			round = qe.size() / m + 1;
			rest = qe.size() % m;
		}
		for(i=0;i&lt;round-1;i++){

				int temp_max=-1;
				int id_max=-1;
				int temp[m];
				
				for(j=0;j&lt;m;j++){
					temp[j]=qe.front();
					qe.pop();
					if(mice[temp[j]].weight &gt; temp_max){
						temp_max = mice[temp[j]].weight;
						id_max = temp[j];
					}
				}
				qe.push(id_max);
				for(j=0;j&lt;m;j++){
					if(temp[j]!=id_max){
						mice[temp[j]].rank = round + 1;
					}
					else{
						mice[temp[j]].rank = round;
					}
				}
		}
			
			//特殊处理最后一回合
			//注意冠军已经生成的的条件，要停止进队了 
				int temp_max=-1;
				int id_max=-1;
				int temp[m];
				
				for(j=0;j&lt;rest;j++){
					temp[j]=qe.front();
					qe.pop();
					if(mice[temp[j]].weight &gt; temp_max){
						temp_max = mice[temp[j]].weight;
						id_max = temp[j];
					}
				}
				if(round != 1) qe.push(id_max);
				for(j=0;j&lt;rest;j++){
					if(temp[j]!=id_max){
						mice[temp[j]].rank = round + 1;
					}
					else{
						mice[temp[j]].rank = round;
					}
				}				
			
			
		
	} 
	
	for(i=0;i&lt;n;i++){
		if(i!=(n-1))
			printf("%d ",mice[i].rank);
		//	cout&lt;&lt;mice[i].rank&lt;&lt;" ";
		else
			printf("%d",mice[i].rank);
	}
	 	

	return 0;
}</pre>
&nbsp;

&nbsp;

&nbsp;

<h4>1074 Reversing Linked List （25 分）</h4>
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10​5​​) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

&nbsp;
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
using namespace std;



int main() {
	int data[100001]; 
	int next[100001];	
	int root,total,k;
//	scanf("%d %d %d\n",&amp;root,&amp;total,&amp;k);
	cin&gt;&gt;root&gt;&gt;total&gt;&gt;k;
	int a,d,n;
	int cc;
	for(cc = 0;cc&lt;total; cc++){
		//scanf("%d %d %d\n",&amp;a,&amp;d,&amp;n);
		cin&gt;&gt;a&gt;&gt;d&gt;&gt;n;
		data[a] = d;
		next[a] = n;
	}
	
	int round,rest;
	if(total%k == 0){
		round = total/k;
		rest = 0;
	}
	else{
		round = total/k;
		rest = total%k;
	}
	int i,j;
	int temp_root;
	int last_tail;
	for(i=0;i&lt;round;i++){

		int temp_addr[k]; 
		if(i==0){
			temp_root = root;
			for(j=0;j&lt;k;j++){
				temp_addr[j]=temp_root;
				temp_root=next[temp_root];
			}
			root = temp_addr[k-1];

			for(j=0;j&lt;k;j++){
				if(j==0){
					next[temp_addr[j]]=temp_root;
				}
				else{
					next[temp_addr[j]]=temp_addr[j-1];	
				}
			}
			last_tail = temp_addr[0];
			
		} 
		else{
			for(j=0;j&lt;k;j++){
				temp_addr[j]=temp_root;
				temp_root=next[temp_root];
			}
			for(j=0;j&lt;k;j++){
				if(j==0){
					next[temp_addr[j]]=temp_root;
				}
				else{
					next[temp_addr[j]]=temp_addr[j-1];	
				}
			}
			next[last_tail] = temp_addr[k-1];
			last_tail = temp_addr[0];
		}
	}
	int cout_temp;
	cout_temp=root;
	
	while(next[cout_temp]!=(-1)){
		printf("%.5d %d %.5d\n",cout_temp,data[cout_temp],next[cout_temp]);
		cout_temp=next[cout_temp];
	}
	printf("%.5d %d %d\n",cout_temp,data[cout_temp],next[cout_temp]);

	return 0;
}</pre>
1 注意5位数的地址输出，最后用了printf

&nbsp;

最后还是有1个时间比较短的用例不通过，24分。各种情况后来都是尝试了，包括格式控制的疏忽等等，最后仍然没通过，原因待查中