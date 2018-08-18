1084 Broken Keyboard (20)（20 分）
On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.
Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.

Input Specification:
Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or "_" (representing the space). It is guaranteed that both strings are non-empty.

Output Specification:
For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.

Sample Input:
7_This_is_a_test
_hs_s_a_es

Sample Output:
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
	bool hash[128] = {false};     //hash数组用ASCⅡ码的个数作为数组长度即可包括题给所有字符
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
