1067 Sort with Swap(0,*) (25)（25 分）
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:
Swap(0, 1) => {4, 1, 2, 0, 3}\ Swap(0, 3) => {4, 1, 2, 3, 0}\ Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (<=10^5^) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1

Sample Output:
9

作者: CHEN, Yue
单位: PAT联盟
时间限制: 150ms
内存限制: 64MB
代码长度限制: 16KB

#include<cstdio> 
#include<algorithm>
using namespace std;
int main( ){
	int n;
	scanf("%d", &n);
	// num数组记录数字i所处的位置，即第i位的值本该是i，如果num[]的值不等于下标，就没有排好序 
	int num[100010], temp, left=0, times=0, k=1;
	for(int i=0; i<n; i++) {
		scanf("%d", &temp);
		num[temp] = i;
		if(num[temp]!=temp && num[temp]!=0) left++; //left记录非零的不在原位的数的个数 
	}
	while(left){           //当left减到0，即所有数字都排好序了，跳出循环 
		while(num[0] == 0){       //当0在原位时 
			for(int i=k; i<n; i++){  //这里不要重头遍历，会超时 
				if(num[i]!=i) {   //找出下一个不在原位的数 
					k=i;          //k记录的是下一个不在原位的数字，即k前面的数字是都在原位的，所以for循环那里每次都从上一个k开始就好了 
					break;
				}
			}
			swap(num[0], num[k]); //将其与0交换 
			times++;              //交换次数+1 
		}
		while(num[0]!=0){         //当0不在原位时 
			swap(num[0], num[num[0]]);   //将0和本该在这个位置的数交换 
			left--;               //排好一个数，left-1 
			times++;			  //交换次数+1 
		}
	}
	printf("%d", times);  //打印交换次数
	return 0;
}
