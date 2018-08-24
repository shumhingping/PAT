1015 Reversible Primes (20)（20 分）
A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.
Now given any two positive integers N (< 10^5^) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2

Sample Output:
Yes
Yes
No

作者: CHEN, Yue
单位: PAT联盟
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio> 
#include<cmath>
bool isprime(int n){           //判断素数函数
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2; i<=sqr; i++){
		if(n%i==0) return false;
	}
	return true;
}
int main( ){
	int n, d;                    //数字，进制
	while(1){                 
		scanf("%d", &n);         
		if(n<0) break;             //当n为负时结束，break
		scanf("%d", &d);
		if(isprime(n)==false){   
			printf("No\n");          //如果当前数字不是素数，打印NO，continue进入下一轮循环
			continue;
		}
		int cnt=0, num[100];     
		do{                        //除基取余法求该十进制数转换成的给定进制数
			num[cnt++] = n%d;        
			n = n/d;
		}while(n!=0);
		for(int i=0; i<cnt; i++){  //将转换后的给定进制数反转后转换回十进制
			n = n*d + num[i];
		}
		if(isprime(n) == false)    //如果反转后的数字不是素数
			printf("No\n");          //打印No
		else printf("Yes\n");      //否则打印Yes
	}
	return 0;
}
