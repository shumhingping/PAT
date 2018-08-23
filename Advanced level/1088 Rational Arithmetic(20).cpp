1088 Rational Arithmetic（20 分）
For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, product and quotient.

Input Specification:
Each input file contains one test case, which gives in one line the two rational numbers in the format a1/b1 a2/b2. The numerators and the denominators are all in the range of long int. If there is a negative sign, it must appear only in front of the numerator. The denominators are guaranteed to be non-zero numbers.

Output Specification:
For each test case, print in 4 lines the sum, difference, product and quotient of the two rational numbers, respectively. The format of each line is number1 operator number2 = result. Notice that all the rational numbers must be in their simplest form k a/b, where k is the integer part, and a/b is the simplest fraction part. If the number is negative, it must be included in a pair of parentheses. If the denominator in the division is zero, output Inf as the result. It is guaranteed that all the output integers are in the range of long int.

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB

分析：本题思路并不难，只是输出格式的调整较为繁琐。

#include<cstdio> 
long long a, b, c, d;
long long GCD(long long a, long long b){        //辗转相除法求最大公约数 
	if(a&&b) while((a%=b)&&(b%=a));
	return a+b;
}
void print(long long a, long long b){            
	if(a==0){                          //如果分子等于0，打印0，跳出函数 
		printf("0");
		return;
	} 
	int gcd = GCD(a, b);               //求最大公约数 
	a /= gcd;                          //把分子约分 
	b /= gcd;                          //把分母约分 
	if(b==1){                          //如果约分后分母等于1，直接打印分子，跳出函数 
		if(a<0)printf("(%lld)", a);
		else printf("%lld", a);
		return;
	}
	int flag1=0, flag2=0, integer = 0; //flag1记录是否是负数，以输出（），flag2记录假分数约分后是否有分数部分，有的话之间要打印一个空格 
	if(a<0){
		a = a*(-1);                      //如果分子为负，调整为正数 
		flag1=1;                         //用flag1来调整格式 
	}
	if(b<0){
		b = b*(-1);                      //如果分母为负，调整为正数。虽然读入的时候都是把负数读到分子里，但是经过除法运算，分母就变成了负数 
		flag1=1;
	}
	if(flag1)printf("(-");
	if(a>=b){
		integer = a/b;
		printf("%lld", integer);
		a -= integer*b;
		if(a) flag2 =1;
		if(flag2) printf(" ");
	}
	printf("%lld/%lld", a, b);
	if(flag1)printf(")");
}
void add(){ 
	long long up = a*d+b*c;
	long long down = b*d;
	print(a, b);printf(" + ");print(c, d);printf(" = ");print(up, down);printf("\n");
}
void minu(){
	long long up = a*d-b*c;
	long long down = b*d;
	print(a, b);printf(" - ");print(c, d);printf(" = ");print(up, down);printf("\n");
}
void multi(){
	long long up = a*c;
	long long down = b*d;
	print(a, b);printf(" * ");print(c, d);printf(" = ");print(up, down);printf("\n");
}
void div(){
	if(c==0){                                                        
		print(a, b);printf(" / ");print(c, d);printf(" = Inf\n");   //如果C==0，即除数等于0，打印Inf，跳出函数 
		return;
	}
	long long up = a*d;
	long long down = b*c;
	print(a, b);printf(" / ");print(c, d);printf(" = ");print(up, down);printf("\n");
}
int main( ){
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	add();
	minu();
	multi();
	div();
	return 0;
}
