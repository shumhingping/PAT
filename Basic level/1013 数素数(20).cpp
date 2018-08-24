1013 数素数（20 分）
令 Pi表示第 i 个素数。现任给两个正整数 M≤N≤10^4，请输出 PM到 PN的所有素数。

输入格式：
输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：
输出从 PM到 PN的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27

输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103

作者: CHEN, Yue
单位: 浙江大学
时间限制: 200 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio> 
#include<cmath>
bool isprime(int n){             //判断素数函数 
	if(n<=1)return false;
	int sqr = sqrt(1.0*n);
	for(int i=2; i<=sqr; i++){
		if(n%i==0) return false;
	}
	return true;
}
int main( ){
	int min, max, flag=0;        //min需要打印的第一个素数下标，max需打印的最后一个素数下标 ，flag调整格式 
	scanf("%d %d", &min, &max);
	for(int i=2,cnt=0; cnt<max; i++){   //cnt记录现在是第几个素数，记到max个为止 
		if(isprime(i)==true){    
			cnt++;                       
			if(cnt>=min) {              //当现在的素数下标>=min，就要输出 
				if(flag>0) printf(" "); //每行的非第一个数前都要打印空格 
				printf("%d", i);   
				flag++;                 //flag可以记录现在打印第几个了 
				if(flag==10){           //每十个换行 
					printf("\n");
					flag=0;             //换行后更新flag 
				}
			}
		}
	}
	return 0;
}
