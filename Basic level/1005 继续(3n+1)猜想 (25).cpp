1005 继续(3n+1)猜想 (25)（25 分）
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(&lt100)，第2行给出K个互不相同的待验证的正整数n(1&ltn<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

输入样例：
6
3 5 6 7 8 11

输出样例：
7 6

作者: CHEN, Yue
单位: PAT联盟
时间限制: 400ms
内存限制: 64MB
代码长度限制: 16KB

注意：hashtable数组大小不能只开100多一点，数值较大的奇数进行（3*n+1）/2操作之后会远大于100，开太小就会出现段错误 
     如果要只开100多一点，可先判断数值是否大于100，如果大于100就不对hashtable进行操作。

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int main( ){
	int k, n[110];               //待验证数字个数，待验证数字数组 
	scanf("%d", &k);
	bool hashtable[10000];       //该数字被覆盖为false，没被覆盖为true，hashtable数组大小不能只开100多一点，开太小会段错误 
	memset(hashtable, true, sizeof(hashtable));  //初始化hashtable为true 
	for(int i=0; i<k; i++){
		scanf("%d", &n[i]);
		int temp = n[i];           //用temp记录n[i]的值，不要直接用n[i]去计算，后面还要输出n[i]的值 
		while(temp!=1){
			if(temp%2==1) temp = (3*temp+1)/2;
			else temp = temp/2;
			hashtable[temp] = false;      //将被覆盖到的数设为false 
		}
	}
	sort(n, n+k, cmp);           //题目要求按从大到小输出，将n[]从大到小排序 
	int flag=0;                  //flag用于整理格式 
	for(int i=0; i<k; i++){
		if(hashtable[n[i]] == true){
			if(flag==1) printf(" ");
			printf("%d", n[i]);
			flag=1;
		}
	}
	return 0;
}
