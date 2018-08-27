1023 Have Fun with Numbers（20 分）
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!
Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:
Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899

Sample Output:
Yes
2469135798

作者: CHEN, Yue
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<iostream> 
#include<string>
using namespace std;
int main( ){
	string str;                     //题给数据可能大于int范围，用string型读入 
	getline(cin, str);
	int len = str.length();
	//dnum[]记录*2之后的数字，因为题给数据最大20位，如果最高位乘2后要进位就是21位。cnt[]记录1-9每个数字出现的次数 
	int dnum[22] = {0}, cnt[10] = {0}, i;    
	for(i=len; i>0; i--){          //str下标从0到(len-1)，循环从len-1，如果最高位要进位，放到dnum[0]去 
		int temp = str[i-1] - '0';    
		cnt[temp]++;                 //1-9在题给数字中每出现一次计数++ 
		dnum[i] += temp*2%10;        //模拟乘法：dnum第i位数等于temp乘2结果的个位数 
		dnum[i-1] += temp*2/10;      //temp乘2的十位数直接进位到dnum[i-1]中 
		cnt[dnum[i]]--;              //1-9在dnum中每出现一次计数-- 
	}
	for(i=1; i<10; i++){            
		if(cnt[i]!=0){              //如果1-9在题给数字和dnum中出现次数相同，一加一减一定等于0 
			printf("No\n");           //如果某个数计数不为0，那么dnum就不是原数的一种组合 
			break;
		}
	}
	if(i==10) printf("Yes\n");          //如果上面的循环走完了才出来，就说明dnum是原数的一种组合 
	if(dnum[0]) printf("%d", dnum[0]);  //如果原数最高位有进位，要打印出来 
	for(i=1; i<=len; i++){
		printf("%d", dnum[i]); 
	}
	return 0;
}
