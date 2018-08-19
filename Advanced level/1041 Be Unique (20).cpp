1041 Be Unique (20)（20 分）
Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1, 10^4^]. The first one who bets on a unique number wins. For example, if there are 7 people betting on 5 31 5 88 67 88 17, then the second one who bets on 31 wins.

Input Specification:
Each input file contains one test case. Each case contains a line which begins with a positive integer N (<=10^5^) and then followed by N bets. The numbers are separated by a space.

Output Specification:
For each test case, print the winning number in a line. If there is no winner, print "None" instead.

Sample Input 1:
7 5 31 5 88 67 88 17

Sample Output 1:
31

Sample Input 2:
5 888 666 666 888 888

Sample Output 2:
None

作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

#include<cstdio> 
int main( ){
	int n;          //数字个数
	scanf("%d", &n);
	int num[n], hashtable[10010] = {0};     //num[]为输入的数字，可通过下标判断其顺序， hashtable[]为每个数字的出现次数
	for(int i=0; i<n; i++){
		scanf("%d", &num[i]);
		hashtable[num[i]]++;
	}
	for(int i=0; i<n; i++){
		if(hashtable[num[i]]==1){
			printf("%d\n", num[i]);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}
