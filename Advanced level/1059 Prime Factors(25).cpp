1059 Prime Factors（25 分）
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1*k1*p2^k2*⋯*pm^km.

Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:
Factor N in the format N = p1^k1*p2^k2*…*pm^km , where pi 's are prime factors of N in increasing order, and the exponent ki is the number of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468

Sample Output:
97532468=2^2*11*17*101*1291

作者: HE, Qinming
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio> 
#include<cmath>
bool isprime( long n ){             //判断素数函数，题给输入的范围是long int 
	if(n<=1) return false;
	long sqr = sqrt(1.0*n);
	for(long i=2; i<=sqr; i++){
		if(n%i==0) return false;
	}
	return true;
}
int main( ){
	long n, temp, i, cnt=0, num=0;       //cnt记录该质因子出现的次数，num该质因子的数值 
	scanf("%lld", &n);	
	if(n==1) {                           //如果n==1，要特判输出1 
		printf("1=1\n");
		return 0;
	}
	printf("%d=", n);
	int flag=0;
	for( i=2, temp = n; temp>=2; i++){       
		if(isprime(i)==true && temp%i==0){  //如果i是素数，同时是temp的因数（temp是n的因数，所以temp的因数也是n的因数） 
			num = i;                          //记录当前质因数 
			while(temp%i==0){                 //计算当前质因数需要的个数 
				cnt++;
				temp /= i;
			}
			if(flag==0)	flag=1;               //flag调整格式，在除第一个输出之外的输出前加'*' 
			else printf("*");
			printf("%d", num);
			if(cnt>1) printf("^%d", cnt);     //如果该质因数的个数大于1，按格式打印出来 
		}
		cnt=0, num=0;                       //置cnt、num初值回到0 
	}
	return 0;
}
