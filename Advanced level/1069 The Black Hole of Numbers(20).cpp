1069 The Black Hole of Numbers（20 分）
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the black hole of 4-digit numbers. This number is named Kaprekar Constant.
For example, start from 6767, we'll get:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...
Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:
Each input file contains one test case which gives a positive integer N in the range (0,10^4).

Output Specification:
If all the 4 digits of N are the same, print in one line the equation N - N = 0000. Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767

Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174

Sample Input 2:
2222

Sample Output 2:
2222 - 2222 = 0000

作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(char a, char b){
	return a>b;
}
int main( ){
	int n, num[4];            //题给整数，num数组记录题给整数的每一位 
	scanf("%d", &n);
	for(int i=3; i>=0; i--){
		num[i] = n%10;        //将题给整数转化到num数组中 
		n /= 10;
	}
	int temp1=0, temp2=0, temp3=0;
	while((temp1-temp2)!=6174){               //只要差不等于0或者6174，就一直循环 
		sort(num, num+4, cmp);                //从大到小排序 
		temp1 = num[0]*1000 + num[1]*100 + num[2]*10 + num[3];    //将新排序转化成int整数 
		sort(num, num+4);                     //从小到大排序 
		temp2 = num[0]*1000 + num[1]*100 + num[2]*10 + num[3];    //将新排序转化成int整数 
		temp3 = temp1 - temp2;                //求差 
		if(temp3==0){                         //如果差等于0，打印结果，break 
			printf("%04d - %04d = 0000\n", temp1, temp2);     //注意打印结果时，temp可能不足四位数，要用0补全 
			break;
		}
		printf("%04d - %04d = %04d\n", temp1, temp2, temp3);
		for(int i=3; i>=0; i--){              
			num[i] = temp3%10;                //更新num数组 
			temp3 /=10;
		}
	}
	return 0;
}
