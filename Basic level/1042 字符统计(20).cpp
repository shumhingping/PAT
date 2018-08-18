1042 字符统计（20 分）
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：
输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

输出格式：
在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。

输入样例：
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........

输出样例：
e 7

作者: CHEN, Yue
单位: 浙江大学
时间限制: 400ms
内存限制: 64MB
代码长度限制: 16KB

//B1042
#include<iostream> 
#include<string>
using namespace std;
int main( ){
	string str;
	getline(cin, str);
	int times[30] = {0};  //根据题意，只统计英文字母的个数，且不分大小，故数组大小取稍大于26 
	int len = str.length();    
	char temp;             //当前字符
	for(int i=0; i<len; i++){
		temp = str[i];
		if(temp>='A' && temp<='Z'){ //当前字符为大写字母
			times[temp - 'A']++;      //对应字母频率+1
		}
		else if(temp>='a' && temp<='z'){   //当前字符为小写字母
			times[temp - 'a']++;             //对应字母频率+1
		}
	}
	int max=0;  //频率最大的字母下标
	for(int i=0; i<26; i++){
		if(times[i]>times[max]){
			max = i;
		}
	}
	printf("%c %d\n", 'a'+max, times[max]); //打印频率最大的字母及其出现频率 
	return 0;
}
