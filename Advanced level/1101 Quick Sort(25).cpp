1101 Quick Sort（25 分）
There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?

For example, given N=5 and the numbers 1, 3, 2, 4, and 5. We have:
1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
and for the similar reason, 4 and 5 could also be the pivot.
Hence in total there are 3 pivot candidates.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5). Then the next line contains N distinct positive integers no larger than 10^9. The numbers in a line are separated by spaces.

Output Specification:
For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

Sample Input:
5
1 3 2 4 5

Sample Output:
3
1 4 5

作者: CAO, Peng
单位: Google
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio>
int main( ){
	int n;
	scanf("%d", &n);
	int num[n];
	for(int i=0; i<n; i++) scanf("%d", &num[i]);                            //题目可理解为寻找某个数，它的左边没有比自己大的数，同时右边没有比自己小的数，这个数就是主元 
	int rightmin=1000000007, leftmax=-1, smaller[n] = {0}, larger[n] = {0}; //larger记录某个数左边是否有比它大的数，smaller记录某个数右边是否有比它小的数，-1表示有，0表示没有 
	for(int i=0; i<n; i++){                         
		if(num[i]>leftmax) leftmax=num[i];          //更新左边的最大值 
		if(i>0 && num[i]<leftmax) larger[i] = -1;   //如果某个数比左边的最大值要小，即左边一定有比它大的数 
	}
	for(int i=n-1; i>=0; i--){
		if(num[i]<rightmin) rightmin=num[i];        //更新右边的最小值 
		if(i<n-1 && num[i]>rightmin) smaller[i] = -1; //如果某个数大于右边的最小值，那么右边一定有比它小的数 
	}
	int cnt=0;             //主元总个数 
	for(int i=0; i<n; i++){
		if(smaller[i]==0 && larger[i]==0){   //同时满足左边没有比自己大的数，右边没有比自己小的数即为主元 
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for(int i=0; i<n; i++){
		if(smaller[i]==0 && larger[i]==0){
			if(i>0) printf(" ");
			printf("%d", num[i]);
		}
	}
	printf("\n");         //一定要打印换行符，测试点2是主元为0的情况，如果没有换行符，最后结果就只有一行，会被判答案错误 
	return 0;
}
