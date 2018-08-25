1096 Consecutive Factors（20 分）
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3×5×6×7, where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive factors, and list the smallest sequence of the consecutive factors.

Input Specification:
Each input file contains one test case, which gives the integer N (1<N<2^31).

Output Specification:
For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence of the consecutive factors in the format factor[1]*factor[2]*...*factor[k], where the factors are listed in increasing order, and 1 is NOT included.

Sample Input:
630

Sample Output:
3
5*6*7

作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio>
#include<cmath>
using namespace std;
int main( ) {
	//num题给数字，max需要求证到的最大值，first累乘的第一个数，len累乘数字的长度 
	long long num, max = sqrt(num), first = 0, len=0;  //题给数据范围是（1，2^31），四则运算可能超过int范围，所以直接设为long long int 
	scanf("%lld", &num);
	for(int i=2; i<=max; i++){          //i只需要从2开始，因为数字乘以1就等于它本身 
		long long temp = 1, j;            //temp记录累乘值，初值设为1 
		for(j=i; j<=max; j++){
			temp *= j;                      //从i开始累乘，跳出循环的条件是1. num不能被累乘值整除，2. j达到上限max 
			if(num%temp!=0) break;	
		}
		if(j-i>len){                      //如果当前累乘的数字长度大于len
			len = j-i;                      //更新len 
			first = i;                      //更新first 
		}
	}
	if(first==0) printf("1\n%lld", num);    //如果first没有被改变，说明该数是一个素数，质因子只有1和它本身，但是题意1不可以输出，故输出num 
	else{
		printf("%lld\n", len);
		for(int i=0; i<len; i++){
			if(i!=0) printf("*");
			printf("%lld", first+i);
		}
	}
	return 0;
}
