1033 旧键盘打字（20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：
输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过10的5次方个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。题目保证第 2 行输入的文字串非空。
注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：
在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。

输入样例：
7+IE.
7_This_is_a_test.

输出样例：
_hs_s_a_tst

作者: CHEN, Yue
单位: 浙江大学
时间限制: 200ms
内存限制: 64MB
代码长度限制: 16KB

注意：第一行失效键的输入可能为空

#include<iostream>
#include<memory.h>
#include<string>
using namespace std;
int main( ){
	string str1, str2;
	getline(cin, str1);  //用getline(cin,...)即使第一行是空行也能读 
	getline(cin, str2);
	int i, j;
	bool hashtable[128];  //用字符ASCⅡ码做数组下标 
	memset(hashtable, true, sizeof(hashtable));   //初始化hashtable全为true 
	int len1 = str1.length();
	int len2 = str2.length();
	for(i=0; i<len1; i++){
		int c1 = str1[i];
		if(c1 == '+'){    //如果有‘+’，+本身和所以大写字母的hashtable置为false 
			hashtable[c1] = false;
			for(j=65; j<=90; j++){
				hashtable[j] = false;
			}
		}
		else if(c1>='A' && c1<='Z'){  //题给input字母全为大写，但是一个字母键坏掉要同时将大写小写都置为false 
			hashtable[c1] = false;
			hashtable[c1+32] = false;
		}
		else hashtable[c1] = false;
	} 
	for(i=0; i<len2; i++){
		int c2 = str2[i];
		if(hashtable[c2] == true){
			printf("%c", c2);
		}
	}
	printf("\n");
	return 0;
}
