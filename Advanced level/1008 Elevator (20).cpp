1008 Elevator (20)（20 分）
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1

Sample Output:
41

作者: CHEN, Yue
单位: PAT联盟
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio> 
int main( ){
	int n, now=0, to, sum=0;            //now现在所在的楼层，to要去的楼层，sum总共花的时间
	scanf("%d", &n);
	sum += 5*n;                         //每停下一次就要花费5秒，不管那个楼层和now之间是上升、下降还是不动
	for(int i=0; i<n; i++){
		scanf("%d", &to);
		if(to<now) sum += 4*(now-to);     //下降一层花费4秒
		else if(to>now) sum +=6*(to-now); //上升一层花费6秒
		now = to;                         //更新现在所在的楼层
	}
	printf("%d\n", sum);
	return 0;
}
