<h1>PAT应试解题纪录&amp;笔记</h1>
[toc depth="2]

&nbsp;
<h2>资料/博客存放</h2>
&nbsp;
<h2>解题纪录</h2>
<h3>3 入门模拟</h3>
<h4>1001 害死人不偿命的(3n+1)猜想 （15 分）
卡拉兹(Callatz)猜想：</h4>
对任何一个正整数 n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把 (3n+1) 砍掉一半。这样一直反复砍下去，最后一定在某一步得到 n=1。卡拉兹在 1950 年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证 (3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……

我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过 1000 的正整数 n，简单地数一下，需要多少步（砍几下）才能得到 n=1？

输入格式：
每个测试输入包含 1 个测试用例，即给出正整数 n 的值。

输出格式：
输出从 n 计算到 1 需要的步数。

输入样例：
3

输出样例：
5

&nbsp;
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
using namespace std;

int main()
{
  int n=0,i=0;
  cin&gt;&gt;n;
  while(n!=1)
  {
    if((n%2)==0)
    {
      n = n/2;
    }
    else
    {
      n = (3*n+1)/2;
    }
    i++;
  };
  cout&lt;&lt;i;
  
}</pre>
&nbsp;
<h4>1011 A+B 和 C （15 分）
给定区间 [−2​31​​,2​31​​] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。</h4>
输入格式：
输入第 1 行给出正整数 T (≤10)，是测试用例的个数。随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔。

输出格式：
对每组测试用例，在一行中输出 Case #X: true 如果 A+B&gt;C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）。

输入样例：
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647

输出样例：
Case #1: false
Case #2: true
Case #3: true
Case #4: false

&nbsp;
<pre class="lang:default decode:true ">#include "iostream"
#include &lt;stdlib.h&gt;
using namespace std;



int main()
{
	int n;
	cin &gt;&gt; n;
	int i;
	for (i = 0; i &lt; n; i++)
	{
		long long a, b, c;
		cin &gt;&gt; a;
		cin &gt;&gt; b;
		cin &gt;&gt; c;
		if ((a + b) &gt; c)
		{
			cout &lt;&lt; "Case #" &lt;&lt; i+1 &lt;&lt; ": true" &lt;&lt; endl;
		}
		else
		{
			cout &lt;&lt; "Case #" &lt;&lt; i+1 &lt;&lt; ": false" &lt;&lt; endl;
		}
	}
	return 0;

}</pre>
&nbsp;
<h4>1016 部分A+B （15 分）</h4>
正整数 A 的“D​A​​（为 1 位整数）部分”定义为由 A 中所有 D​A​​ 组成的新整数 P​A​​。例如：给定 A=3862767，D​A​​=6，则 A 的“6 部分”P​A​​ 是 66，因为 A 中有 2 个 6。

现给定 A、D​A​​、B、D​B​​，请编写程序计算 P​A​​+P​B​​。

输入格式：
输入在一行中依次给出 A、D​A​​、B、D​B​​，中间以空格分隔，其中 0&lt;A,B&lt;10​10​​。

输出格式：
在一行中输出 P​A​​+P​B​​ 的值。

输入样例 1：
3862767 6 13530293 3

输出样例 1：
399

输入样例 2：
3862767 1 13530293 8

输出样例 2：
0
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main() {
	int a,b,a1,b1;
	int ai=0,bi=0;
	int temp_a=0,temp_b=0;
//	cin&gt;&gt;a&gt;&gt;a1&gt;&gt;b&gt;&gt;b1;
	scanf("%d %d %d %d",&amp;a,&amp;a1,&amp;b,&amp;b1);
	do{
		if(a%10 == a1)
			temp_a= temp_a*10+a1; 
		a = a/10;	
	}while(a!=0);
	do{
		if(b%10 == b1)
			temp_b = temp_b*10+b1;
		b = b/10;	
	}while(b!=0);
	printf("%d",temp_a+temp_b);
	return 0;
	
}</pre>
&nbsp;
<h4>1026 程序运行时间 （15 分）</h4>
要获得一个 C 语言程序的运行时间，常用的方法是调用头文件 time.h，其中提供了 clock() 函数，可以捕捉从程序开始运行到 clock() 被调用时所耗费的时间。这个时间单位是 clock tick，即“时钟打点”。同时还有一个常数 CLK_TCK，给出了机器时钟每秒所走的时钟打点数。于是为了获得一个函数 f 的运行时间，我们只要在调用 f 之前先调用 clock()，获得一个时钟打点数 C1；在 f 执行完成后再调用 clock()，获得另一个时钟打点数 C2；两次获得的时钟打点数之差 (C2-C1) 就是 f 运行所消耗的时钟打点数，再除以常数 CLK_TCK，就得到了以秒为单位的运行时间。

这里不妨简单假设常数 CLK_TCK 为 100。现给定被测函数前后两次获得的时钟打点数，请你给出被测函数运行的时间。

输入格式：
输入在一行中顺序给出 2 个整数 C1 和 C2。注意两次获得的时钟打点数肯定不相同，即 C1 &lt; C2，并且取值在 [0,10​7​​]。

输出格式：
在一行中输出被测函数运行的时间。运行时间必须按照 hh:mm:ss（即2位的 时:分:秒）格式输出；不足 1 秒的时间四舍五入到秒。

输入样例：
123 4577973

输出样例：
12:42:59
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv) {
	int time1,time2;
	cin&gt;&gt;time1&gt;&gt;time2;
	int delta = time2 -time1;
	if(delta%100 &gt;= 50)
		delta = delta /100 + 1;
	else
		delta = delta /100;
	printf("%02d:%02d:%02d",delta/3600,(delta%3600)/60,delta%60);
	return 0;
}</pre>
&nbsp;
<h4>1046 划拳 （15 分）</h4>
划拳是古老中国酒文化的一个有趣的组成部分。酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。如果谁比划出的数字正好等于两人喊出的数字之和，谁就赢了，输家罚一杯酒。两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。

下面给出甲、乙两人的划拳记录，请你统计他们最后分别喝了多少杯酒。

输入格式：
输入第一行先给出一个正整数 N（≤100），随后 N 行，每行给出一轮划拳的记录，格式为：

甲喊 甲划 乙喊 乙划

其中喊是喊出的数字，划是划出的数字，均为不超过 100 的正整数（两只手一起划）。

输出格式：
在一行中先后输出甲、乙两人喝酒的杯数，其间以一个空格分隔。

输入样例：
5
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15

输出样例：
1 2
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main() {
	int i,a,aa,b,bb;
	int ai = 0, bi = 0;
	scanf("%d",&amp;i);
	int counter;
	for(counter = 0; counter &lt; i; counter++){
		scanf("%d%d%d%d",&amp;a,&amp;aa,&amp;b,&amp;bb);
		if(aa==(a+b)){
			if(bb!=(a+b))
				ai++;
		}
		else if(bb==(a+b))
			bi++;
	}
	
	printf("%d %d",bi,ai);

	return 0;
	
}</pre>
&nbsp;
<h4>1008 数组元素循环右移问题 （20 分）</h4>
一个数组A中存有N（&gt;0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即将A中的数据由（A​0​​A​1​​⋯A​N−1​​）变换为（A​N−M​​⋯A​N−1​​A​0​​A​1​​⋯A​N−M−1​​）（最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6

输出样例:
5 6 1 2 3 4

&nbsp;
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;vector&gt;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main() {
	vector&lt;int&gt; a;
	int i,j;
	scanf("%d%d",&amp;i,&amp;j);
	int counter;
	for(counter = 0; counter &lt; i; counter++){
		int temp;
		scanf("%d",&amp;temp);
		a.push_back(temp);
	}
	j = j % i;
	auto ii=a.begin();
	for(ii=a.begin() + (i-j); ii != a.end(); ii++)
	{
		printf("%d",*ii);
		if(ii!= (a.end()-1) )
			printf(" ");
		else if(j!=i)
			printf(" ");
	}
	
	for(auto ii=a.begin(); ii != a.end()-j; ii++)
	{
		printf("%d",*ii);
		if(ii!= (a.end()-1-j) )
			printf(" ");	
		}


	return 0;
	
}</pre>
&nbsp;
<h4>1018 锤子剪刀布 （20 分）</h4>
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第 1 行给出正整数 N（≤10​5​​），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：
输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出样例：
5 3 2
2 3 5
B B
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main() {
	int a[3]={0,0,0};
	int score_a[3]={0,0,0};
	int score_b[3]={0,0,0};
	int i,j;
	scanf("%d",&amp;i);
	for(j=0; j&lt;i; j++)
	{
		char A,B;
		cin&gt;&gt;A&gt;&gt;B;
//		scanf("%c %c",&amp;A,&amp;B);
		
		if(A == 'C'){
			if(B =='J'){
				a[0]++;
				score_a[0]++;
			}
			else if(B=='B'){
				a[2]++;
				score_b[2]++;				
			}
			else if(B=='C'){
				a[1]++;
			}
		}
		
		if(A=='J'){
			if(B=='B'){
				a[0]++;
				score_a[1]++;
			}
			else if(B=='C'){
				a[2]++;
				score_b[0]++;				
			}
			else if(B=='J'){
				a[1]++;
			}
		}
			
		if(A=='B'){
			if(B=='C'){
				a[0]++;
				score_a[2]++;
			}
			else if(B=='J'){
				a[2]++;
				score_b[1]++;				
			}
			else if(B=='B'){
				a[1]++;
			}
		}
	}
	
	printf("%d %d %d\n",a[0],a[1],a[2]);
	printf("%d %d %d\n",a[2],a[1],a[0]);
	
	if(score_a[2]&gt;=score_a[1] &amp;&amp; score_a[2]&gt;=score_a[0])
		printf("B");
	else if(score_a[0]&gt;=score_a[1] &amp;&amp; score_a[0]&gt;=score_a[2])
		printf("C");
	else printf("J");
	printf(" ");
	
	if(score_b[2]&gt;=score_b[1] &amp;&amp; score_b[2]&gt;=score_b[0])
		printf("B");
	else if(score_b[0]&gt;=score_b[1] &amp;&amp; score_b[0]&gt;=score_b[2])
		printf("C");
	else printf("J");	
	
	return 0;
	
}</pre>
&nbsp;
<h4>1010 一元多项式求导 （25 分）</h4>
设计函数求一元多项式的导数。（注：x​n​​（n为整数）的一阶导数为nx​n−1​​。）

输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。

输入样例:
3 4 -5 2 6 1 -2 0

输出样例:
12 3 -10 1 6 0

&nbsp;
<pre class="lang:default decode:true ">#include &lt;iostream&gt;
#include &lt;cstdio&gt;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int temp[10010][2];
int main() {
	int i,j;
	int counter = 0;
	while(	scanf("%d%d",&amp;i,&amp;j) != EOF ){
		if(j!=0){
			temp[counter][0] = i;
			temp[counter][1] = j;
			counter++;
		}
	}
	
	int count = 0;
	for(i=0;i&lt;counter;i++)
	{
		printf("%d %d",temp[i][0]*temp[i][1],temp[i][1]-1);
		count++;
		if(i!= counter - 1)
			printf(" ");

	}
	if(count == 0)
		printf("0 0");
	
	return 0;
	
}</pre>
&nbsp;

&nbsp;
<h3>5 数学问题</h3>
<h4 class="card-title">B1013 数素数 （20 分）</h4>
<div class="problemListItem_2867x">
<div class="problem_2tXnk">
<div class="ques-view">令 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">i</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 表示第 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">i</span></span></span></span> 个素数。现任给两个正整数 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">M</span><span class="mrel">≤</span><span class="mord mathit">N</span><span class="mrel">≤</span><span class="mord mathrm">1</span><span class="mord"><span class="mord mathrm">0</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle uncramped mtight"><span class="mord mathrm mtight">4</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span>，请输出 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">M</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 到 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">N</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 的所有素数。</div>
<div></div>
<div class="ques-view">
<p id="-">输入格式：</p>

输入在一行中给出 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">M</span></span></span></span> 和 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">N</span></span></span></span>，其间以空格分隔。</div>
<div class="ques-view">

&nbsp;
<p id="-">输出格式：</p>

输出从 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">M</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 到 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">N</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。</div>
<div class="ques-view">

&nbsp;
<p id="-">输入样例：</p>

<pre><code class="lang-in">5 27
</code></pre>
<p id="-">输出样例：</p>

<pre class=""><code class="lang-out">11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103</code></pre>
</div>
代码：
<pre class="lang:c++ decode:true ">#include &lt;iostream&gt;
#include &lt;algorithm&gt;

using namespace std;
int flag[500000];
int prime[10000];

void find_prime(int m, int n){

	
	int i=2,j=0;
	do{
		if(flag[i]== 0 ){
		
			prime[j] = i;
			j++;
			int k;
			for(k = i+i;k&lt;500000;k+=i){
				flag[k]=1;
			}
		}
		i++;	
	}while(i&lt;500000);
	
	
}

int main(int argc, char *argv[])
{
	int counter = 0;
	for(counter = 0; counter &lt;500000; counter++)
		flag[counter] = 0; 
	int m,n;
	cin&gt;&gt;m&gt;&gt;n;
	find_prime(m,n);
	int i=0,k=0;
	for(i=m-1;i&lt;n;i++){
		cout&lt;&lt;prime[i];
		k++;
		if(k%10 == 0) cout&lt;&lt;endl;
		else if(i!=(n-1))cout&lt;&lt;" ";
	}
	return 0;
}</pre>
笔记：

使用了筛选法选择素数；最开始布尔数组范围为10000 部分测试用例不通过，改到50000顺利通过。

&nbsp;

</div>
</div>