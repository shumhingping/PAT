1003 我要通过！(20)（20 分）
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
得到“答案正确”的条件是：
1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
(1)任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
(2)如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n(<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

作者: CHEN, Yue
单位: PAT联盟
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

分析：根据题目可推出通过的字符串在P前面的A的个数*P、T之间A的个数=T之后A的个数，具体分析见柳婼大神的blog(http://www.liuchuo.net/archives/460)，渣渣如我是自己想不出来的😭

#include<iostream> 
#include<cstring>
#include<map>
using namespace std;
int main( ){
	int n, p=-1, t=-1;             //字符串总数，字符P在字符串中的位置（即下标），字符T在字符串中的位置 
	string str;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>str;
		map<char, int>mp;         //记录每个字符的个数 
		for(int j=0; j<str.size(); j++){
			mp[str[j]]++;         //更新字符str[j]的个数 
			if(str[j]=='P') p=j;  //如果遇到P，记录P的位置 
			if(str[j]=='T') t=j;  //如果遇到T，记录T的位置 
		}
		//如果字符串中只有1个P，1个T，且P前面的A个数+P、T之间的A的个数+T之后A的个数=A的总个数（即检查除了P,T,A之外还有没有其他字符），且P前面的A个数*T、P之间A的个数=T之后的A的个数 
		if(mp['P']==1 && mp['T']==1 && p+(t-p-1)+(str.size()-t-1)==mp['A'] && p*(t-p-1)==str.size()-t-1 && mp['A']>0){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}
