1093 Count PAT's（25 分）
The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.
Now given any string, you are supposed to tell the number of PAT's contained in the string.

Input Specification:
Each input file contains one test case. For each case, there is only one line giving a string of no more than 10^5characters containing only P, A, or T.

Output Specification:
For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.

Sample Input:
APPAPT

Sample Output:
2

作者: CAO, Peng
单位: Google
时间限制: 150 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<iostream>
#include<string>
using namespace std;
int main( ){
	int cnt=0, T=0;   //组合总个数，T的个数 
	string temp;
	getline(cin, temp);
	int len = temp.length();
	int P[len]={0};   //P数组记录在第i个字符（包括i） 前面有几个P
	for(int i=0; i<len; i++){
		if(i>0 ) P[i] = P[i-1];   //如果i>0，先继承上一位的结果 
		if(temp[i]=='P') P[i]++;  //如果第i位也是P，加1 
	}
	for(int i=len-1; i>=0; i--){  //从后往前遍历 
		if(temp[i]=='T') T++;     //记录T的个数 
		else if(temp[i]=='A') {   //如果遇到A，这个A能组成的PAT个数等于前面的P个数*后面的T个数 
			cnt = (cnt+(P[i]*T)%1000000007)%1000000007;   //累加总个数
			//ps.要在这里就对1000000007取模，到printf时再取会有两个点过不了，可能是超出int范围累加时出错？ 
		}
	}
	printf("%d\n", cnt);
	return 0;
}
