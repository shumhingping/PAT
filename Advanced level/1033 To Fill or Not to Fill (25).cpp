1033 To Fill or Not to Fill (25)（25 分）
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.

Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: C~max~ (<= 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; D~avg~ (<=20), the average distance per unit gas that the car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: P~i~, the unit gas price, and D~i~ (<=D), the distance between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print "The maximum travel distance = X" where X is the maximum possible distance the car can run, accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

Sample Output 1:
749.17

Sample Input 2:
50 1300 12 2
7.10 0
7.00 600

Sample Output 2:
The maximum travel distance = 1200.00

作者: ZHANG, Guochuan
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

*贪心策略的中心思想就是无论何时何地选择价格最低的。如果现在能去一个价格比现在这个站更低的地方，就只加能到那个站的油，到那个站再加价格更低发油；如果现在这个站的价格就是能到的范围内最低的，在这个站就要加满，然后去范围内除现在这个站外价格最低的那个站。

#include<cstdio> 
#include<algorithm>
#define INF 100000000
using namespace std;
struct node{
	double p, d;            //该加油站的价格，距离起点的距离 
}station[510];
bool cmp(node a, node b){
	return a.d<b.d;         //按距离从小到大排列 
}
int main( ){
	double cmax, d, davg;   
	int n; 
	scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
	for(int i=0; i<n; i++) scanf("%lf %lf", &station[i].p, &station[i].d);
	station[n].d = d; station[n].p = 0;      //把重点也计入station数组，距离设为终点距离，油单价设为0 
	sort(station, station+n, cmp);
	if(station[0].d!=0){                     //题设油箱本来是空的，如果最近的加油站距离不是0，车就开不了 
		printf("The maximum travel distance = 0.00\n");
	}
	else{
		double cost=0, nowtank=0, max=cmax*davg;   //总花费，油箱现在还剩的油量，满油能开出的最大距离 
		int now=0;                                 //现在所在的加油站下标 
		while(now<n){                
			int min=-1;                            //价钱较低的加油站下标，即下一个目的地，如果没找到即为-1 
			double minp = INF;                     //价格较低的加油站油单价 
			//从now的下一个加油站开始，到终点（终点下标为n，所以要取等）或加满油能到的最大距离内 
			for(int i=now+1; i<=n && station[i].d-station[now].d<=max; i++){
				if(station[i].p<minp){             //找出价格较低的那个加油站 
					min = i;                       //更新min 
					minp = station[i].p;
					if(station[min].p<station[now].p){    //遇到第一个价格比现在这个站价格低的站，break 
						break;
					}
				}
			}
			if(min==-1)	break;                      //如果找不到能去的加油站，break，打印能走的最大距离
			//如果找到了能去的加油站，下面开始计算需要的钱 
			double need = (station[min].d-station[now].d)/davg;     //从now去到接下来要去的那个站所需要的油量 
			if(station[min].p<station[now].p){             //如果接下来要去的站价格比now还低，只加到够到那个站的油量 
				if(nowtank<need){                          //如果油箱剩下的油比需要的少 
					cost += (need-nowtank)*station[now].p; //加油，算钱 
					nowtank = 0;                           //因为只加刚好够到接下来那个站的油，所以到了之后油箱清空为0 
				}
				else nowtank -= need;                      //如果油箱剩下的油不必需要的少，不用加，就算到那里还剩多少油 
			}
			else{                                          //如果now的价格比接下来那个站低，在这里加满油再去 
				cost += (cmax-nowtank)*station[now].p;      
				nowtank = cmax - need; 
			}
			now = min;          //更新now为接下来到的那个站 
		}
		if(now==n) printf("%.2f\n", cost);                 //如果到了终点，打印花费的钱数 
		else printf("The maximum travel distance = %.2f\n", station[now].d+max);    //没能到终点，最大距离为now已经走的距离+再now加满油再走的距离 
	}
	return 0;
}
