<h1>PAT应试解题纪录&amp;笔记</h1>
[toc depth="2]
<h2>资料/博客存放</h2>
&nbsp;
<h2>解题纪录</h2>
<h5 class="card-title">B1013 数素数 （20 分）</h5>
<div class="problemListItem_2867x">
<div class="problem_2tXnk">
<div class="ques-view">

令 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">i</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 表示第 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">i</span></span></span></span> 个素数。现任给两个正整数 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">M</span><span class="mrel">≤</span><span class="mord mathit">N</span><span class="mrel">≤</span><span class="mord mathrm">1</span><span class="mord"><span class="mord mathrm">0</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle uncramped mtight"><span class="mord mathrm mtight">4</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span>，请输出 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">M</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 到 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">N</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 的所有素数。
<h3 id="-">输入格式：</h3>
输入在一行中给出 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">M</span></span></span></span> 和 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord mathit">N</span></span></span></span>，其间以空格分隔。
<h3 id="-">输出格式：</h3>
输出从 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">M</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 到 <span class="katex"><span class="katex-html" aria-hidden="true"><span class="base textstyle uncramped"><span class="mord"><span class="mord mathit">P</span><span class="msupsub"><span class="vlist"><span class="fontsize-ensurer reset-size5 size5">​</span><span class="reset-textstyle scriptstyle cramped mtight"><span class="mord mathit mtight">N</span></span><span class="baseline-fix"><span class="fontsize-ensurer reset-size5 size5">​</span>​</span></span></span></span></span></span></span> 的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
<h3 id="-">输入样例：</h3>
<pre><code class="lang-in">5 27
</code></pre>
<h3 id="-">输出样例：</h3>
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
