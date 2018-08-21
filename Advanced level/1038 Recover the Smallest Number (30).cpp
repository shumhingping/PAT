1038 Recover the Smallest Number (30)（30 分）
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of combinations of these segments, and the smallest number is 0229-321-3214-32-87.

Input Specification:
Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the smallest number in one line. Do not output leading zeros.

Sample Input:
5 32 321 3214 0229 87

Sample Output:
22932132143287

作者: CHEN, Yue
单位: PAT联盟
时间限制: 400 ms
内存限制: 64 MB
代码长度限制: 16 KB

#include<iostream> 
#include<algorithm>
#include<string>
using namespace std;
bool cmp(string a, string b){//string函数中“+”是将两个string直接拼起来
	return a+b < b+a;        //将两string拼起来后比较哪一个字典序更小
}
int main( ){
	int n;
	cin>>n;
	string num[n];
	for(int i=0; i<n; i++) 
    cin>>num[i];        //读入、输出整个字符串都只能用cin和cout 
	sort(num, num+n, cmp);
	string ans;
	for(int i=0; i<n; i++) 
    ans += num[i];     //将排好序的字符串全部拼起来 
	while(ans[0] == '0') 
    ans.erase(ans.begin());   //如果首位是0就不停地将首位删掉 
	if(ans.length()==0) printf("0");   //如果把在首位的0全部删掉后字符串长度为0，说明这个字符串只有0，输出0 
	else cout<<ans;                    //不然将剩下的字符串输出 
	return 0;
}
