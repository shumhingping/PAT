1029 旧键盘(20)（20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：
输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es

输出样例：
7TI

作者: CHEN, Yue
单位: PAT联盟
时间限制: 200ms
内存限制: 64MB
代码长度限制: 16KB

//AC代码
#include<cstdio> 
#include<cstring>
int main( ){
	char str1[100], str2[100];
	scanf("%s", str1);            //读入两组字符串 
	scanf("%s", str2);            //gets函数不安全，用gets会编译错误 
	bool hash[128] = {false};     //hash数组需要包括题给字符，用ASCⅡ码的个数作为数组长度 
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i, j;
	for(i=0; i<len1; i++){
		char c1, c2;
		c1 = str1[i];
		for(j=0; j<len2; j++){
			c2 = str2[j];
			if(c1>='a' && c2<='z')	c1 -=32;      //题目要求输出全为大写字母 
			if(c2>='a' && c2<='z')  c2 -=32;      //将小写字母转换成大写字母 
			if(c1==c2){
				hash[c1] = true;  
				break;             //如果c1在第二个字符串中出现了，跳出 
			}
		}
		if(j==len2 && hash[c1] == false){
			printf("%c", c1);
			hash[c1] = true;      //打印过一次后也设为true，以免多次打印同一字符 
		}
	}
	printf("\n");
	return 0;
}
