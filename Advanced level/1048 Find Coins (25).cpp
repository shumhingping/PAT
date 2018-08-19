1048 Find Coins (25)（25 分）
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^5^ coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=10^5^, the total number of coins) and M(<=10^3^, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the two face values V~1~ and V~2~ (separated by a space) such that V~1~ + V~2~ = M and V~1~ <= V~2~. If such a solution is not unique, output the one with the smallest V~1~. If there is no solution, output "No Solution" instead.

Sample Input 1:
8 15
1 2 8 7 2 4 11 15

Sample Output 1:
4 11

Sample Input 2:
7 14
1 8 7 2 4 11 15

Sample Output 2:
No Solution

作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

#include<cstdio>
#include<cstring>
using namespace std;
int main( ){
	//n输入数据个数， m和， hashtable[]记录每个数字出现次数，数组大小要超过m的最大值，不然i很小时访问hashtable[m-i]就会段错误 
	int n, m, hashtable[1010];        
	memset(hashtable, 0, sizeof(hashtable));   //初始化hashtable数组
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		int temp;             //当前数字 
		scanf("%d", &temp);
		hashtable[temp]++;    //当前数字出现次数+1 
	}
	for(int i=0; i<m; i++){
		//如果v1，v2不相等且v1，v2出现次数均大于0， 或者v1等于v2，该数字出现次数不小于2次，即找到了符合题意的一对数据 
		if((hashtable[i] && hashtable[m-i] && i!=m-i)||(i==m-i && hashtable[i]>=2)){
			printf("%d %d\n", i, m-i);         //不需要判断i， m-i的大小来输出，只要该对数据存在，在i为较小的那个数时就会输出并return 
			return 0;
		}
	}
	printf("No Solution\n");     //没有找到符合题意的数据 
	return 0;
}
