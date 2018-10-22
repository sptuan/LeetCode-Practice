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