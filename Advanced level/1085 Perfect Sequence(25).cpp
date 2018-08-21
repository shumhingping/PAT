1085 Perfect Sequence（25 分）
Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.
Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (≤10^5) is the number of integers in the sequence, and p (≤10^9) is the parameter. In the second line there are N positive integers, each is no greater than 10^9.

Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9

Sample Output:
8

作者: CAO, Peng
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio> 
#include<algorithm>
using namespace std;
int n;  
long long p, num[100010];
//题意可理解为在从小到大的序列中寻找最后一个小于等于x的数，即寻找第一个大于x的数 
int binarysearch(int i, long long x){
	if(num[n-1]<=x) return n;      //如果最大的数都<=x，返回n 
	int left=i+1, right=n-1, mid;  //在(i+1)到(n-1)的范围内寻找第一个大于x的数 
	while(left<right){         
		mid = left+(right-left)/2;
		if(num[mid]<=x)	left = mid+1;  //如果mid<=x，即第一个大于x的数只能在mid后面，更新left 
		else right = mid;              //同理，更新right 
	}
	return left;       //跳出while循环时left==right，返回任意一个即可 
}
int main( ){
	scanf("%d%ld", &n, &p) ;
	for(int i=0; i<n; i++)  scanf("%d", &num[i]);
	sort(num, num+n);  //将num数组从小到大排序 
	int m=1;           //m组成序列的最大个数，最小也有1，因为一个数肯定<=自己乘以一个正整数 
	for(int i=0; i<n; i++){       //计算每一个数的构成的完美序列的长度 
		int j = binarysearch(i, num[i]*p);    
		m = max(m, j-i);          //更新最大长度 
	}
	printf("%d", m);
	return 0;
}
