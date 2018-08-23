1081 Rational Sum（20 分）
Given N rational numbers in the form numerator/denominator, you are supposed to calculate their sum.

Input Specification:
Each input file contains one test case. Each case starts with a positive integer N (≤100), followed in the next line N rational numbers a1/b1 a2/b2 ... where all the numerators and denominators are in the range of long int. If there is a negative number, then the sign must appear in front of the numerator.

Output Specification:
For each test case, output the sum in the simplest form integer numerator/denominator where integer is the integer part of the sum, numerator < denominator, and the numerator and the denominator have no common factor. You must output only the fractional part if the integer part is 0.

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3

Sample Input 2:
2
4/3 2/3
Sample Output 2:
2

Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24

作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

分析：
1.分数相加，a/b + c/d = (ad + bc) / bd，第一个数让它和0/1相加。
2.题目说测试数据不超过long int，要考虑a*b可能超过long int了，所以用long long int。

#include<cstdio> 
long long GCD( long long a, long long b){      //辗转相除法求最大公因数
	if(b&&a) while((a%=b)&&(b%=a));
	return a+b;
}
int main( ){
	int n;
	scanf("%d", &n);
	long long a = 0, b=1, c, d;   //设a/b=0/1
	for(int i=0; i<n; i++){
		scanf("%lld/%lld", &c, &d);
		a = a*d + b*c;
		b = d*b;
		long long gcd = GCD(a, b);
		a /= gcd;
		b /= gcd;
	}
	if(a==0) printf("0\n");      //如果结果是0，打印0
	else if(a>=b){               //如果是假分数
		printf("%lld", a/b);       //打印整数部分
		a -= b*(a/b);              //更新分子
		if(a) printf(" ");         //如果接下来还有分数没打印，之间要打一个空格
	}
	if(a) printf("%d/%d\n", a, b);
	return 0;
}
