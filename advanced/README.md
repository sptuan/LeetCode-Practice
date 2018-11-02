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