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




&nbsp;
<h4>1032 Sharing （25 分）</h4>
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, loading and being are stored as showed in Figure 1.

Figure 1

You are supposed to find the starting position of the common suffix (e.g. the position of i in Figure 1).

Input Specification:
Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (≤10​5​​), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by −1.

Then N lines follow, each describes a node in the format:

Address Data Next

whereAddress is the position of the node, Data is the letter contained by this node which is an English letter chosen from { a-z, A-Z }, and Next is the position of the next node.

Output Specification:
For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output -1 instead.

Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

Sample Output 1:
67890

Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1

Sample Output 2:
-1

&nbsp;
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
using namespace std;




int main() {
	bool hash[100001] = {false};
	char data[100001]; 
	int next[100001];
	int a_start,b_start,k;
	cin&gt;&gt;a_start&gt;&gt;b_start&gt;&gt;k;
	int i,j;
	for(i=0;i&lt;k;i++){
		int temp_add,temp_data,temp_next;
		scanf("%d %c %d",&amp;temp_add,&amp;temp_data,&amp;temp_next);
//		cin&gt;&gt;temp_add&gt;&gt;temp_data&gt;&gt;temp_next;
		data[temp_add]=temp_data;
		next[temp_add]=temp_next;
	}
	int temp_root;
	temp_root = a_start;
	while(temp_root!=(-1)){
		hash[temp_root]=true;
		temp_root=next[temp_root];
	}
	temp_root = b_start;
	int flag = 0;
	while((flag == 0) &amp;&amp; (temp_root != (-1))){
		if(hash[temp_root] == true){
			printf("%.5d",temp_root);
			flag = 1;
		}
		temp_root=next[temp_root];
	}
	if(flag == 0){
		printf("-1");
	}
	return 0;
}</pre>
此题比较简单，貌似所有用例都是尾缀相同的；考虑到情况没做，试着秒一下直接通过了。



<h3>DFS</h3>
<h4>1103 Integer Factorization （30 分）</h4>
The K−P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a program to find the K−P factorization of N for any positive integers N, K and P.

Input Specification:
Each input file contains one test case which gives in a line the three positive integers N (≤400), K (≤N) and P (1&lt;P≤7). The numbers in a line are separated by a space.

Output Specification:
For each case, if the solution exists, output in the format:

N = n[1]^P + ... n[K]^P

where n[i] (i = 1, ..., K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 12​2​​+4​2​​+2​2​​+2​2​​+1​2​​, or 11​2​​+6​2​​+2​2​​+2​2​​+2​2​​, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest factor sequence must be chosen -- sequence { a​1​​,a​2​​,⋯,a​K​​ } is said to be larger than { b​1​​,b​2​​,⋯,b​K​​ } if there exists 1≤L≤K such that a​i​​=b​i​​ for i&lt;L and a​L​​&gt;b​L​​.

If there is no solution, simple output Impossible.

Sample Input 1:
169 5 2

Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2

Sample Input 2:
169 167 3

Sample Output 2:
Impossible

&nbsp;
<pre class="lang:c++ decode:true">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
using namespace std;

int N,K,P;
vector&lt;int&gt; temp,ans;
int flag = 0;
int ans_sumD=0;
int pre_n[401];


void DFS(int temp_sum,int n,int counter,int sumD){
	//temp_sum临时立方和，n选到的数，counter已选的数 ,sumD底数的和 
	//死胡同条件 
	if(((n&lt;1) || temp_sum&gt;N || counter &gt;K))
	{
		return; 
	}
	//符合条件
	if(((temp_sum == N) &amp;&amp; (counter == K))) {
		if(sumD &gt; ans_sumD){
			ans_sumD = sumD;
			ans = temp;
		}
		flag = 1;
	} 
	//开始DFS 
	//选该n
	temp.push_back(n);
	DFS(temp_sum + pre_n[n],n,counter+1,sumD+n);
	temp.pop_back();
	//不选该N 
	DFS(temp_sum,n-1,counter,sumD);
	
}

int main() {
	cin&gt;&gt;N&gt;&gt;K&gt;&gt;P;
	int NN;
	int i,j;
	j=0;
	int pre_flag = 0;
	while(pre_flag == 0){
		pre_n[j]=j;
		for(i=0;i&lt;P-1;i++){
			pre_n[j] =  pre_n[j]*j;
		}
		if(pre_n[j]&lt;=N){
			NN = j;
		}
		if(pre_n[j]&gt;N){
			pre_flag = 1;
		}
		j++;
	}

	
	DFS(0,NN,0,0);
	if(flag == 0){
		cout&lt;&lt;"Impossible"&lt;&lt;endl;
	}
	else{
		cout&lt;&lt;N&lt;&lt;" = ";
		auto i = ans.begin();
		for(i = ans.begin(); i !=ans.end();i++){
			if(i !=(ans.end()-1)){
				cout&lt;&lt;*i&lt;&lt;"^"&lt;&lt;P&lt;&lt;" + ";
			}
			else{
				cout&lt;&lt;*i&lt;&lt;"^"&lt;&lt;P&lt;&lt;endl;
			}
		}
	}
	return 0; 
} 
//忽略了1 1 2极端条件</pre>
忽略了1 1 2极端条件,后来在幂计算处修正

必须预处理幂计算，否则直接超时，高阶运算非常耗时！

另一个超时的问题，是不对幂计算进行剪枝

&nbsp;

注：不要太聚焦于示例输入，而导致未注意到KNP等参数变化
&nbsp;
<h3>BFS</h3>
<h4>1091 Acute Stroke （30 分）</h4>
One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M×N matrix, and the maximum resolution is 1286 by 128); L (≤60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).

Then L slices are given. Each slice is represented by an M×N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are connected and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.

【插图】

Figure 1

Output Specification:
For each case, output in a line the total volume of the stroke core.

Sample Input:
3 4 5 2
1 1 1 1
1 1 1 1
1 1 1 1
0 0 1 1
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0

Sample Output:
26

&nbsp;

&nbsp;
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;
 
using namespace std;

int M,N,L,T;
int counter;

int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};

bool inq[60][128][1286] = {false};
int img[60][128][1286];

struct node{
	int l;
	int m;
	int n;
}Node;

bool judge(int l, int m, int n){
	if( (l&lt;0) || (l&gt;=L)
			  || (m&lt;0) || (m&gt;=M)
			  || (n&lt;0) || (n&gt;=N)){
		
		return false;
	}
	else{
		if((img[l][m][n] == 1) &amp;&amp; inq[l][m][n] == false ){
//			cout&lt;&lt;"judge true\n";
			return true;
		}
		else{
//			cout&lt;&lt;"judge false\n";
			return false;
		}
	}
}

void BFS(int l, int m, int n){
//	cout&lt;&lt;"BFS!"&lt;&lt;endl;
	queue&lt;node&gt; Q;
	if(inq[l][m][n] == false){
		Node.l = l;
		Node.m = m;
		Node.n = n;
		Q.push(Node);
		inq[l][m][n] = true;
		
//		cout&lt;&lt;"Push In Q!"&lt;&lt;endl;
	}
	while(!Q.empty()){
		Node = Q.front();
		Q.pop();
//		cout&lt;&lt;"POP!"&lt;&lt;endl;
		if(img[Node.l][Node.m][Node.n] == 1){
			counter++;
//			cout&lt;&lt;"coutner:"&lt;&lt;counter&lt;&lt;endl;
//			cout&lt;&lt;"Find!"&lt;&lt;endl;
		}
		
		node nowNode;
		int i;
		for(i=0;i&lt;6;i++){
			nowNode.l = Node.l + X[i];
			nowNode.m = Node.m + Y[i];
			nowNode.n = Node.n + Z[i];
			if(judge(nowNode.l,nowNode.m,nowNode.n)){
//				if(inq[nowNode.l][nowNode.m][nowNode.n] == false){
				Q.push(nowNode);
//				cout&lt;&lt;"Push Next Door."&lt;&lt;endl;
				inq[nowNode.l][nowNode.m][nowNode.n] = true;	
//				}
			}
		}
	}

	
}

int main() {


	vector&lt;int&gt; sum;
	int sumF=0;
	
	cin&gt;&gt;M&gt;&gt;N&gt;&gt;L&gt;&gt;T;
	int i,j,k;
	for(i=0;i&lt;L;i++){
		for(j=0;j&lt;M;j++){
			for(k=0;k&lt;N;k++){
				scanf("%d",&amp;(img[i][j][k]));
			}
		}
	}

/*
	for(i=0;i&lt;L;i++){
		for(j=0;j&lt;M;j++){
			for(k=0;k&lt;N;k++){
				printf("%d ",(img[i][j][k]));
			}
			cout&lt;&lt;endl;
		}
	}	
	*/
	
	for(i=0;i&lt;L;i++){
		for(j=0;j&lt;M;j++){
			for(k=0;k&lt;N;k++){
				if((inq[i][j][k] == false) &amp;&amp; (img[i][j][k] == 1)){
					counter = 0;
					BFS(i,j,k);
					if(counter !=0){
						sum.push_back(counter);
					}
				}
			}
		}
	}
	
	auto ii = sum.end();
	for(ii = sum.begin();ii!=sum.end();ii++){
		if(*ii&gt;=T){
			sumF += *ii;
		}
	}
	
	cout&lt;&lt;sumF&lt;&lt;endl;
	

	return 0; 
} 
/*
写BFS就应该相信自己的思路，因为已经理解了这东西，不要太依赖于教材。

在遍历所有节点进行BFS时，应该及时剪枝，不合适的节点根本不让他进BFS，节省程序开销。
最后一个例一直出错，对进入BFS的遍历进行限制之后成功，并且耗时大大减小。 
*/</pre>
&nbsp;

&nbsp;
<h3>Tree</h3>
<h4>1020 Tree Traversals （25 分）</h4>
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

Sample Output:
4 1 6 3 5 7 2

&nbsp;
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

int post[30];
int in[30];
int N;

node* create(int posti,int postj, int ini, int inj){
	//cout&lt;&lt;"posti:"&lt;&lt;posti&lt;&lt;" postj:"&lt;&lt;postj&lt;&lt;" ini"&lt;&lt;ini&lt;&lt;" inj"&lt;&lt;inj&lt;&lt;endl;
	if(postj &lt; posti){
		//cout&lt;&lt;"NULL"&lt;&lt;endl;
		return NULL;
	}
	if(posti&lt;0 || postj&lt;0 || ini&lt;0 || inj&lt;0){
		//cout&lt;&lt;"NULL"&lt;&lt;endl;
		return NULL;
	}
	node* root = new node;
	root-&gt;data = post[postj];
	//cout&lt;&lt;"Node:"&lt;&lt;root-&gt;data&lt;&lt;endl;
	
	if(posti==postj){
		root-&gt;lchild = NULL;
		root-&gt;rchild = NULL;
		return root;
	}
	
	//开始寻找根节点
	int i=0;
	int counter=0;
	do{
		if(in[ini+i] == post[postj]){
			counter = ini+i;
		}
		i++;
	}while(counter == 0 &amp;&amp; i&lt;N);

	//counter-ini要统一，用来判断存在与否 
	 
	root-&gt;lchild = create(posti,posti+(counter-ini)-1,ini,ini+(counter-ini)-1);
	root-&gt;rchild = create(postj-1+1-(inj-counter),postj-1,counter+1,inj);
	return root;
}

void BFS(node* root){
	queue&lt;node*&gt; Q;
	Q.push(root);
	int j=0; 
	while(!Q.empty()){
		if(j!=N-1){
			cout&lt;&lt;Q.front()-&gt;data&lt;&lt;" ";	
			j++;
		}
		else{
			cout&lt;&lt;Q.front()-&gt;data&lt;&lt;endl;
		}
		
		if(Q.front()-&gt;lchild != NULL){
			Q.push((Q.front())-&gt;lchild);
		}
		if(Q.front()-&gt;rchild != NULL){
			Q.push((Q.front())-&gt;rchild);
		}
		Q.pop();
	}
}


int main() {
	cin&gt;&gt;N;
	int i,j,k;
	for(i = 0; i &lt; N; i++){
		cin&gt;&gt;post[i]; 
	}
	for(i = 0; i &lt; N; i++){
		cin&gt;&gt;in[i];
	}
	//cout&lt;&lt;"Cin OK!"&lt;&lt;endl;
	node* root;
	root = create(0,N-1,0,N-1);
	BFS(root);
	return 0;
}</pre>
&nbsp;

树的中序和后序创建，加一层DFS

&nbsp;
<h4>1102 Invert a Binary Tree （25 分）</h4>
The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node from 0 to N−1, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6

Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1

&nbsp;

&nbsp;
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int lchild[10];
int rchild[10];
int root; 
bool root_flag[10]={false};
int counter = 0;
int N;

void BFS(int root){
	queue&lt;int&gt; Q;
	Q.push(root);
	while(!Q.empty()){
		if(counter == N-1){
			cout&lt;&lt;Q.front();
		}
		else{
			cout&lt;&lt;Q.front()&lt;&lt;" ";
		}
		counter++;
		if(lchild[Q.front()] != -1){
			Q.push(lchild[Q.front()]);
		} 
		if(rchild[Q.front()] != -1){
			Q.push(rchild[Q.front()]);
		}
		Q.pop();
	}
}

void DFS(int root){
	if(lchild[root] != -1){
		DFS(lchild[root]);
	}
	
	if(counter == N-1){
		cout&lt;&lt;root;
	}
	else{
		cout&lt;&lt;root&lt;&lt;" ";
		counter++;
	}
	
	if(rchild[root] != -1){
		DFS(rchild[root]);
	}
}


int main() {
	char a,b;
	cin&gt;&gt;N;
	int i,j;
	for(i=0;i&lt;N;i++){
		cin&gt;&gt;a&gt;&gt;b;
		if(a == '-'){
			rchild[i] = -1;
		}
		else{
			rchild[i] = int(a) - int('0');
			root_flag[rchild[i]] = true;
		}
		if(b == '-'){
			lchild[i] = -1;
		}
		else{
			lchild[i] = int(b - '0');
			root_flag[lchild[i]] =true;
		}
	}
	
	for(i=0;i&lt;N;i++){
		if(root_flag[i] == false){
			root = i;
		}
	}
	counter = 0;
	BFS(root);
	cout&lt;&lt;endl;
	
	counter = 0;
	DFS(root);
	return 0;
}</pre>
非常简单的静态二叉树+BFS+DFS

&nbsp;

&nbsp;
<h4>1079 Total Sales of Supply Chain （25 分）</h4>
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the total sales from all the retailers.

Input Specification:
Each input file contains one test case. For each case, the first line contains three positive numbers: N (≤10​5​​), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N−1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

K​i​​ ID[1] ID[2] ... ID[K​i​​]

where in the i-th line, K​i​​ is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. K​j​​ being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after K​j​​. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 10​10​​.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3

Sample Output:
42.4

&nbsp;

&nbsp;
<pre class="lang:c++ decode:true">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;
#include &lt;map&gt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

vector&lt;int&gt; chain[100000];
//map&lt;int,double&gt; sale;
double sale[100000];

int N;
double price;
double rate;

double final_cost = 0;


double total = 0;

double price_cache[100000];


void DFS(int root, int tier){
	if(!chain[root].empty()){
		//cout&lt;&lt;"DFS"&lt;&lt;endl;
		auto ii = chain[root].begin();
		for(ii = chain[root].begin();ii != chain[root].end();ii++){
			DFS(*ii, tier+1);
		}
	}
	else{
		int i=0;
		double final_rate = 1;
		if(tier&lt;1000000){
			final_cost += price_cache[tier] * sale[root];
		}
		else{
				for(i = 0; i&lt;tier; i++){
					final_rate = final_rate * (1 + rate/100);
				}
		
				final_cost += final_rate * price * sale[root];
				//cout&lt;&lt;"end: "&lt;&lt;final_cost&lt;&lt;endl;
			
		}

	}
}

int main() {
	cin&gt;&gt;N&gt;&gt;price&gt;&gt;rate;
	int i,j,k;
	double sale_temp;
	int child_temp;
	
	price_cache[0] = price;
	
	
	//计算cache，高阶乘法会导致最后一个算力超时！多次尝试发现有高达100000的tier。
	//On复杂度缓存价格，用内存换时间
	for(i = 1; i &lt; 100000; i++){
		price_cache[i] = price_cache[i-1] * (1 + rate/100);
	}
	
	for(i = 0; i &lt; N; i++){
		scanf("%d",&amp;j);
		//cout&lt;&lt;j&lt;&lt;endl;
		if(j == 0){
			scanf("%lf",&amp;sale_temp); 
			//cout&lt;&lt;sale_temp&lt;&lt;endl;
			sale[i] = sale_temp;
		}
		else{
			for(k = 0; k &lt; j; k++){
				scanf("%d",&amp;child_temp);
				//cout&lt;&lt;child_temp&lt;&lt;endl;
				chain[i].push_back(child_temp);
			}
		}
	}
	
//	return 0;
	DFS(0, 0);

	printf("%.1f\n",final_cost);
	return 0;
}</pre>
//计算cache，高阶乘法会导致最后一个算力超时！多次尝试发现有高达100000的tier。 //On复杂度缓存价格，用内存换时间



&nbsp;

&nbsp;
<h4>1004 Counting Leaves （30 分）</h4>
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 0&lt;N&lt;100, the number of nodes in a tree, and M (&lt;N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.

The input ends with N being 0. That case must NOT be processed.

Output Specification:
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output 0 1 in a line.

Sample Input:
2 1
01 1 02

Sample Output:
0 1
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;
using namespace std;

vector&lt;int&gt; child[100];
queue&lt;int&gt; q[101];

void DFS(int root){
	q[0].push(root);
	int floor;
	int flag = 0;
	int counter = 0;
	
	while(!q[counter].empty()){
		int tick=0;
		while(!q[counter].empty()){
			int temp = q[counter].front();
			if(child[temp].empty()){
				tick++;
			}
			else{
				auto j = child[temp].begin();
				for(j = child[temp].begin(); j!=child[temp].end(); j++){
					q[counter+1].push(*j);
				}
			}
			q[counter].pop();
		}
		cout&lt;&lt;tick;
		counter++;
		if(!q[counter].empty()){
			cout&lt;&lt;" ";
		}
	}
}

int main(){
	int N,M;
	cin&gt;&gt;N&gt;&gt;M;
	
	int i,j,k;
	for(i=0;i&lt;M;i++){
		int counter;
		cin&gt;&gt;counter&gt;&gt;k;
		for(j=0;j&lt;k;j++){
			int temp_child;
			scanf("%d",&amp;temp_child);
			child[counter].push_back(temp_child);
		}	
	}
	
	DFS(1);
	
	
	return 0;
}</pre>
简单的静态树存储于层级罗列


&nbsp;
<h3>BST</h3>
<h4>1043 Is It a Binary Search Tree （25 分）</h4>
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in a line YES if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or NO if not. Then if the answer is YES, print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
7
8 6 5 7 10 8 11

Sample Output 1:
YES
5 7 6 8 11 10 8

Sample Input 2:
7
8 10 11 8 6 7 5

Sample Output 2:
YES
11 8 10 7 5 6 8

Sample Input 3:
7
8 6 8 5 10 9 11

Sample Output 3:
NO

作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

&nbsp;

&nbsp;
<pre class="lang:c++ decode:true ">#include &lt;stdio.h&gt;
#include &lt;iostream&gt;

using namespace std;

int seq[1000];
int rchild[1000];
int lchild[1000];
int rev_flag = 0; //0不反转 1反转 
int check_flag = 0; //0 YES 1 NO

struct node{
	int data;
	node *lchild;
	node *rchild;
}; 

node *build(int l, int r){
//	cout&lt;&lt;"Build "&lt;&lt;l&lt;&lt;"-"&lt;&lt;r&lt;&lt;endl;
	if(l&gt;=r){
		return NULL;
	}
	else{
		node* root = new node;
		root-&gt;data = seq[l];
//		cout&lt;&lt;"Added "&lt;&lt;root-&gt;data&lt;&lt;endl;

		
		if(rev_flag == 0)//不反转
		{
			int i=l+1;
			while(i &lt; r &amp;&amp; seq[i] &lt; seq[l]) {
				i++;
			}
				root-&gt;lchild = build(l+1,i);
				root-&gt;rchild = build(i,r);
			
			

			
		}
		else if(rev_flag == 1)//反转 
		{
			int i=l+1;
			while(i &lt; r &amp;&amp; seq[i] &gt;= seq[l]) {
				i++;
			}
			

				root-&gt;lchild = build(l+1,i);
				root-&gt;rchild = build(i,r);
			

		}
		return root;
	}

} 

int temp_max,temp_min;

void findMax(node* root){
	if(temp_max&lt;root-&gt;data){
		temp_max = root-&gt;data;
	}
	
	if(root-&gt;lchild != NULL){
		findMax(root-&gt;lchild);
	}
	if(root-&gt;rchild != NULL){
		findMax(root-&gt;rchild);
	}
}

void findMin(node* root){
	if(temp_min &gt; root-&gt;data){
		temp_min = root-&gt;data;
	}
	
	if(root-&gt;lchild != NULL){
		findMin(root-&gt;lchild);
	}
	if(root-&gt;rchild != NULL){
		findMin(root-&gt;rchild);
	}
}




void check(node* root){
	int data = root-&gt;data;
	
//	cout&lt;&lt;"Checking root."&lt;&lt;"data:"&lt;&lt;root-&gt;data;
		if(root-&gt;lchild != NULL){
//			cout&lt;&lt;" lchild"&lt;&lt;root-&gt;lchild-&gt;data;
		}
		if(root-&gt;rchild != NULL){
//			cout&lt;&lt;" rchild"&lt;&lt;root-&gt;rchild-&gt;data;
		}
//	cout&lt;&lt;endl;
	

	if(rev_flag == 0){
		if(root-&gt;lchild != NULL){
			
			temp_max = root-&gt;lchild-&gt;data;
			findMax(root-&gt;lchild);
//			cout&lt;&lt;"Find Max:"&lt;&lt;temp_max&lt;&lt;endl;
			if(temp_max &gt;= data){
				check_flag = 1;
//				cout&lt;&lt;"flag = 1"&lt;&lt;endl;
//				cout&lt;&lt;"CMP"&lt;&lt;data&lt;&lt;"&amp;"&lt;&lt;(root-&gt;lchild)-&gt;data&lt;&lt;" "&lt;&lt;"flag = 1"&lt;&lt;endl;
			}
			check(root-&gt;lchild);

		}
		if(root-&gt;rchild != NULL){
			
			temp_min = root-&gt;rchild-&gt;data;
			findMin(root-&gt;rchild);
//			cout&lt;&lt;"Find Min:"&lt;&lt;temp_min&lt;&lt;endl;
			if(temp_min &lt; data){
				check_flag = 1;
//				cout&lt;&lt;"flag = 1"&lt;&lt;endl;
//				cout&lt;&lt;"CMP"&lt;&lt;data&lt;&lt;"&amp;"&lt;&lt;(root-&gt;rchild)-&gt;data&lt;&lt;" "&lt;&lt;"flag = 1"&lt;&lt;endl;
			}
			check(root-&gt;rchild);
		}
	}

	if(rev_flag == 1){
		int data = root-&gt;data;
		if(root-&gt;lchild != NULL){
			temp_min = root-&gt;lchild-&gt;data;
			findMin(root-&gt;lchild);
//			cout&lt;&lt;"Find Min:"&lt;&lt;temp_min&lt;&lt;endl;
			if(temp_min &lt; data){
				check_flag = 1;
//				cout&lt;&lt;"CMP"&lt;&lt;data&lt;&lt;"&amp;"&lt;&lt;(root-&gt;lchild)-&gt;data&lt;&lt;" "&lt;&lt;"flag = 1"&lt;&lt;endl;
			}
			check(root-&gt;lchild);
		}
		if(root-&gt;rchild != NULL){
			temp_max = root-&gt;rchild-&gt;data;
			findMax(root-&gt;rchild);
//			cout&lt;&lt;"Find Max:"&lt;&lt;temp_max&lt;&lt;endl;
			if(temp_max &gt;= data){
				check_flag = 1;
//				cout&lt;&lt;"CMP"&lt;&lt;data&lt;&lt;"&amp;"&lt;&lt;(root-&gt;rchild)-&gt;data&lt;&lt;" "&lt;&lt;"flag = 1"&lt;&lt;endl;
			}
			check(root-&gt;rchild);
		}
	}

}





void postorder(node* root){
	if(root-&gt;lchild!=NULL){
		postorder(root-&gt;lchild);
	}
	if(root-&gt;rchild!=NULL){
		postorder(root-&gt;rchild);
	}
	cout&lt;&lt;root-&gt;data&lt;&lt;" ";
}

void postorder_1st(node* root){
	if(root-&gt;lchild!=NULL){
		postorder(root-&gt;lchild);
	}
	if(root-&gt;rchild!=NULL){
		postorder(root-&gt;rchild);
	}
	cout&lt;&lt;root-&gt;data;
}


int main(){
	
	int N;
	cin&gt;&gt;N;
	int i,j,k;
	for(i = 0; i &lt; N; i++){
		cin&gt;&gt;seq[i];
	}
	
	if(seq[0]&gt;seq[1]){
		rev_flag = 0;
	} 
	else{
		rev_flag = 1;
	}
	
	node* root;
	root = build(0,N);
	
//	cout&lt;&lt;"Build Complete!"&lt;&lt;endl;
	check(root);
	
	if(check_flag == 1){
		cout&lt;&lt;"NO"&lt;&lt;endl;
	}
	else{
		cout&lt;&lt;"YES"&lt;&lt;endl;
		postorder_1st(root);
	}
	
	return 0;
}</pre>
具体记录在笔记里。尝试了动态写法，注意结构体传递



<h3>Dijkstra</h3>
<h4>1030 Travel Plan （30 分）</h4>
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (≤500) is the number of cities (and hence the cities are numbered from 0 to N−1); M is the number of highways; S and Dare the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:
For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

Sample Output:
0 2 3 3 40

&nbsp;
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;

#define INF 1000000000
#define MAXV 510

using namespace std;

int N,M,S,D;

int G[MAXV][MAXV];
int cost[MAXV][MAXV];

int n[MAXV],d[MAXV],c[MAXV];
bool vis[MAXV] = {false};
vector&lt;int&gt; pre[MAXV];


void dijkstra(int s){
	n[s] = 1;
	d[s] = 0;
	c[s] = 0;
	
	int i,j,k;

	for(i=0;i&lt;N;i++){
		
			//先找最小值 
//		cout&lt;&lt;"Round Start!"&lt;&lt;endl;
		int u = -1;
		int MIN = INF;
		for(j=0;j&lt;N;j++){
			if(vis[j] == false &amp;&amp; d[j]&lt;MIN){
				u = j;
				MIN = d[j];
			}
		}
		if(u==-1){
//			cout&lt;&lt;"Failed"&lt;&lt;endl;
			return;
		}
//		cout&lt;&lt;"Find Min:"&lt;&lt;u&lt;&lt;endl;
		vis[u] = true;
		
		for(j=0;j&lt;N;j++){
			if(G[u][j]!=INF){
//				cout&lt;&lt;"Detecting:"&lt;&lt;u&lt;&lt;"-&gt;"&lt;&lt;j&lt;&lt;"  G="&lt;&lt;G[u][j]&lt;&lt;endl;
				if(vis[j]==false &amp;&amp; (d[u]+G[u][j])&lt;d[j]){
					d[j]=d[u]+G[u][j];
					pre[j].clear();
					pre[j].push_back(u);
//					cout&lt;&lt;"&lt;&lt;&lt;&lt;&lt;&lt;"&lt;&lt;j&lt;&lt;endl;
				}
				else if(vis[j]==false &amp;&amp; (d[u]+G[u][j])==d[j]){
					pre[j].push_back(u);
//					cout&lt;&lt;"======"&lt;&lt;u&lt;&lt;endl;
				}
			}
		}
	}
}

int num=0;
int minCost=INF;
vector&lt;int&gt; tempPath;
vector&lt;int&gt; Path;

void DFS(int d){
//	cout&lt;&lt;"DFS:"&lt;&lt;d&lt;&lt;endl;
	if(d==S){
		tempPath.push_back(d);
//		cout&lt;&lt;"Push Back:"&lt;&lt;d&lt;&lt;endl;
		auto i = tempPath.begin();
		int tempCost = 0;
		for(i;i!=(tempPath.end()-1);i++){
			tempCost+=cost[*i][*(i+1)];
//			cout&lt;&lt;"cost|"&lt;&lt;*i&lt;&lt;"+"&lt;&lt;*(i+1)&lt;&lt;endl;
		}
//		cout&lt;&lt;"tempCost="&lt;&lt;tempCost&lt;&lt;endl;
		if(tempCost&lt;minCost){
			minCost = tempCost;
			Path = tempPath;
		}

//		cout&lt;&lt;"Pop out"&lt;&lt;tempPath.back()&lt;&lt;endl;
		tempPath.pop_back();
		
		return;
	}
	
	tempPath.push_back(d);
//	cout&lt;&lt;"Push Back:"&lt;&lt;d&lt;&lt;endl;
	auto i=pre[d].begin();
	for(i;i!=pre[d].end();i++){
		DFS(*i);
		//cout&lt;&lt;"Pop out"&lt;&lt;tempPath.back()&lt;&lt;endl;
		//tempPath.pop_back();
	}
	
//	cout&lt;&lt;"Pop out"&lt;&lt;tempPath.back()&lt;&lt;endl;
	tempPath.pop_back();

}

int main(){
	cin&gt;&gt;N&gt;&gt;M&gt;&gt;S&gt;&gt;D;
	int i,j,k;
	for(i=0;i&lt;N;i++){
		for(j=0;j&lt;N;j++){
			G[i][j] = INF;
		}
		n[i] = 0;
		d[i] = INF;
		c[i] = INF;
	}
	for(i=0;i&lt;M;i++){
		int c1,c2,D,C;
		cin&gt;&gt;c1&gt;&gt;c2&gt;&gt;D&gt;&gt;C;
		G[c1][c2] = D;
		G[c2][c1] = D;
		cost[c1][c2] = C;
		cost[c2][c1] = C;
	}
//	cout&lt;&lt;"Init Complete!dijkstra-"&lt;&lt;endl;
	dijkstra(S);
//	cout&lt;&lt;"DFS"&lt;&lt;endl;
	DFS(D);
	auto m=Path.end()-1;
	int counter=0;
	for(m;m!=Path.begin();m--){
		cout&lt;&lt;*m&lt;&lt;" ";
		counter++;
	}
	cout&lt;&lt;*m&lt;&lt;" ";
	counter++;
	cout&lt;&lt;d[D]&lt;&lt;" "&lt;&lt;minCost&lt;&lt;endl;
	
	return 0;
}</pre>
&nbsp;



<h4>1003 Emergency （25 分）</h4>
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C​1​​ and C​2​​ - the cities that you are currently in and that you must save, respectively. The next line contains Nintegers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c​1​​, c​2​​ and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C​1​​ to C​2​​.

Output Specification:
For each test case, print in one line two numbers: the number of different shortest paths between C​1​​ and C​2​​, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output:
2 4

&nbsp;
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
#include &lt;queue&gt;

#define INF 1000000000
#define MAXV 510

using namespace std;
//G为图；res为点权；
//d[]为起点到各点最小距离；w[]为最大点权
//n为最小路径数目 
int G[MAXV][MAXV];
int res[MAXV];
int d[MAXV],w[MAXV],n[MAXV];
bool vis[MAXV] = {false}; 
int N,M,C1,C2;


void dijkstra(int s){
	int i,j;
	for(i=0; i&lt;MAXV; i++){
		d[i] = INF;
		w[i] = 0;
		n[i] = 0;
	}
	d[s] = 0;
	w[s] = res[s];
	n[s] = 1;
	
	//循环N次 
	for(i=0; i&lt;N; i++){
//		cout&lt;&lt;"---- Round "&lt;&lt;i&lt;&lt;" ----"&lt;&lt;endl;
		//先找可到达的最短距离点
		int u=-1;
		int MIN = INF;
		 
		 for(j=0;j&lt;N;j++){
		 	if(vis[j]==false &amp;&amp; d[j] &lt; MIN){
		 		u = j;
		 		MIN = d[j];
			 } 
		 }
		 
//		 cout&lt;&lt;"Find min target: "&lt;&lt;u&lt;&lt;endl;
		 
		 if(u == -1) {
		 	return;
//		 	cout&lt;&lt;"Failed"&lt;&lt;endl;
		 }
		 //一定记得标记已访问
		 vis[u] = true;
		 
		 //然后找以d为起点，可到达点是否能更新距离信息 
		 for(j=0; j&lt;N; j++){
		 	//此处注意筛选，需要非INF才进入
			 if(G[u][j]!=INF){
			 	if(vis[j] == false &amp;&amp; (G[u][j]+d[u])&lt;d[j]){
		 		//开始更新 
			 		d[j] = G[u][j]+d[u];
					w[j] = w[u]+res[j];
					n[j] = n[u]; 
//					cout&lt;&lt;"Update &lt;&lt; d["&lt;&lt;j&lt;&lt;endl;
				}
				 else if(vis[j]==false &amp;&amp; (G[u][j]+d[u])==d[j]){
				 	if(w[u]+res[j]&gt;w[j]){
				 		w[j] = w[u]+res[j];
//				 		cout&lt;&lt;"Update == w["&lt;&lt;j&lt;&lt;endl;
					 }
					 
					 //最短路径和权值无关，写在外面
					 n[j] += n[u]; 
//					 cout&lt;&lt;"Update == n["&lt;&lt;j&lt;&lt;endl;
				}
			 	
			 } 

		 } 
	}
	 
}
 
int main(){

	cin&gt;&gt;N&gt;&gt;M&gt;&gt;C1&gt;&gt;C2;
	
	int i,j,k;
	for(i=0; i&lt;N; i++) {
		cin&gt;&gt;res[i];
	}
	
	//初始化图G 
	for(i=0;i&lt;MAXV;i++){
		for(j=0;j&lt;MAXV;j++){
			G[i][j] = INF;
		}
	}
	
	//写入图G 
	for(i=0; i&lt;M; i++){
		int c1,c2,L;
		cin&gt;&gt;c1&gt;&gt;c2&gt;&gt;L;
		G[c1][c2] = L;
		G[c2][c1] = L; 
	}
//	cout&lt;&lt;"digkstra!"&lt;&lt;endl;
	dijkstra(C1);
	
	cout&lt;&lt;n[C2]&lt;&lt;" "&lt;&lt;w[C2];
	
	return 0;
}</pre>
&nbsp;