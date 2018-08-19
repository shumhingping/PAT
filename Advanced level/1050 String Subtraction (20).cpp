1050 String Subtraction (20)（20 分）
Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.

Input Specification:
Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 10^4. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.

Output Specification:
For each test case, print S1 - S2 in one line.

Sample Input:
They are students.
aeiou

Sample Output:
Thy r stdnts.

作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main( ){
	string str1, str2;     
	getline(cin, str1);
	getline(cin, str2);
	int len1 = str1.length(), len2 = str2.length();
	bool hashtable[128];                            //hashtable记录某一字符是否在str2中出过 
	memset(hashtable, true, sizeof(hashtable));     //hashtable初始化为true 
	for(int i=0; i<len2; i++){
		hashtable[str2[i]] = false;                   //一旦该字符在str2中出现，对应的hashtable[]置为false 
	}
	for(int i=0; i<len1; i++) {
		if(hashtable[str1[i]]==true){                 //如果str1中的某一字符没有在str2中出现，打印它 
			printf("%c", str1[i]);
		}
	}
	return 0;
}
