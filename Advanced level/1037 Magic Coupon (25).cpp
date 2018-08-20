1037 Magic Coupon (25)（25 分）
The magic shop in Mars is offering some magic coupons. Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!
For example, given a set of coupons {1 2 4 -1}, and a set of product values {7 6 -2 -3} (in Mars dollars M\$) where a negative value corresponds to a bonus product. You can apply coupon 3 (with N being 4) to product 1 (with value M\$7) to get M\$28 back; coupon 2 to product 2 to get M\$12 back; and coupon 4 to product 4 to get M\$3 back. On the other hand, if you apply coupon 3 to product 4, you will have to pay M\$12 to the shop.
Each coupon and each product may be selected at most once. Your task is to get as much money back as possible.

Input Specification:
Each input file contains one test case. For each case, the first line contains the number of coupons NC, followed by a line with NC coupon integers. Then the next line contains the number of products NP, followed by a line with NP product values. Here 1<= NC, NP <= 10^5^, and it is guaranteed that all the numbers will not exceed 2^30^.

Output Specification:
For each test case, simply print in a line the maximum amount of money you can get back.

Sample Input:
4
1 2 4 -1
4
7 6 -2 -3

Sample Output:
43

作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

分析：最大的正数相乘乘积最大，最小的负数相乘乘积最大。故按大小排好序之后，将从前、后分别相乘的乘积累加即得最大和

#include<cstdio> 
#include<algorithm>
using namespace std;
int main( ){
	int nc, np, amount = 0, coupon[100010], product[100010];   
	scanf("%d", &nc);
	for(int i=0; i<nc; i++){
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &np);
	for(int i=0; i<np; i++){
		scanf("%d", &product[i]);
	}
	sort(coupon, coupon+nc);         //将coupon数组从小到大排序 
	sort(product, product+np);       //将product数组从小到大排列 
	int i=0, j=0;
	while(i<nc && i<np && coupon[i]<0 && product[i]<0){
		amount += coupon[i]*product[i];
		i++;
	}
	i=nc-1; j=np-1;                 //coupon数组最后一个的下标是nc-1，同理product数组 
	while(i>=0 && j>=0 && coupon[i]>0 && product[j]>0){
		amount += coupon[i]*product[j];
		i--, j--;
	}
	printf("%d", amount);
	return 0;
}
