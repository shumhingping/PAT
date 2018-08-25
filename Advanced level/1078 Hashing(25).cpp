1078 Hashing（25 分）
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.

Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (≤10^4) and N (≤MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.

Sample Input:
4 4
10 6 4 15

Sample Output:
0 1 4 -

作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<cstdio>
#include<cmath>
int isprime( int n ){                   //判断素数函数
	if(n<=1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2; i<=sqr; i++) {
		if(n%i==0) return false;
	}
	return true;
}
int main( ){
	int msize, n;                        
	scanf("%d%d", &msize, &n);
	while(isprime(msize)==false){        //如果user给的msize不是素数，要求不小于user给的msize的最小素数
		msize++;
	}
	int num[msize] = {0};                //num数组记录这个位置是否已被用，0表示没有，1表示被占用
	for(int i=0; i<n; i++){
		int temp, flag=0;                  
		scanf("%d", &temp);
		if(i>0) printf(" ");               //输出格式：除了第一个数外，其他数字的前面加空格
		for(int j=0; j<msize-1; j++){      //从0到msize-1，用正向的平方探测法解决冲突
			int index = (temp+j*j)%msize;    
			if(!num[index]){                 
				num[index] = 1;
				printf("%d", index);
				flag=1;
				break;
			}
		} 
		if(!flag) printf("-");
	}
	return 0;
}
