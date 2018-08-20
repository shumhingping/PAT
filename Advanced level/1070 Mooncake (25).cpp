1070 Mooncake (25)（25 分）
Mooncake is a Chinese bakery product traditionally eaten during the Mid-Autumn Festival. Many types of fillings and crusts can be found in traditional mooncakes according to the region's culture. Now given the inventory amounts and the prices of all kinds of the mooncakes, together with the maximum total demand of the market, you are supposed to tell the maximum profit that can be made.

Note: partial inventory storage can be taken. The sample shows the following situation: given three kinds of mooncakes with inventory amounts being 180, 150, and 100 thousand tons, and the prices being 7.5, 7.2, and 4.5 billion yuans. If the market demand can be at most 200 thousand tons, the best we can do is to sell 150 thousand tons of the second kind of mooncake, and 50 thousand tons of the third kind. Hence the total profit is 7.2 + 4.5/2 = 9.45 (billion yuans).

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (<=1000), the number of different kinds of mooncakes, and D (<=500 thousand tons), the maximum total demand of the market. Then the second line gives the positive inventory amounts (in thousand tons), and the third line gives the positive prices (in billion yuans) of N kinds of mooncakes. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the maximum profit (in billion yuans) in one line, accurate up to 2 decimal places.

Sample Input:
3 200
180 150 100
7.5 7.2 4.5

Sample Output:
9.45

作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

#include<cstdio> 
#include<algorithm>
using namespace std;
struct node{
	double amount, sell, price;   //月饼库存数量，月饼总价， 月饼单价 
}cake[1010];
bool cmp(node a, node b){
	return a.price>b.price ;     //按单价从大到小排序 
}
int main( ){
	int n;                      //月饼种类 
	double d, profit=0;         //商家需求数量，获利 ，因为是以thousand ton和billion做单位，要考虑可能有小数，要用double类型 
	scanf("%d%lf", &n, &d);
	for(int i=0; i<n; i++) scanf("%lf", &cake[i].amount);
	for(int i=0; i<n; i++) scanf("%lf", &cake[i].sell);
	for(int i=0; i<n; i++) cake[i].price = cake[i].sell / cake[i].amount;
	sort(cake, cake+n, cmp);
	for(int i=0; i<n; i++){
		while(cake[i].amount>0 && d>0){     //如果该种月饼数量大于0，且月商家需求量大于0 
			profit += cake[i].price;        //将该份月饼的单价累计到获利上 
			cake[i].amount--;               //月饼库存数量-1 
			d--;                            //商家需求量-1 
		}
	}
	printf("%.2f\n", profit);
	return 0;
}
