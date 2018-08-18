1039 到底买不买（20）（20 分）
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。
为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

输入格式：
每个输入包含1个测试用例。每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。

输出格式：
如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。

输入样例1：
ppRYYGrrYBR2258
YrR8RrY

输出样例1：
Yes 8

输入样例2：
ppRYYGrrYB225
YrR8RrY

输出样例2：
No 2

作者: CHEN, Yue
单位: PAT联盟
时间限制: 100ms
内存限制: 64MB
代码长度限制: 16KB

#include<iostream>
#include<string> 
using namespace std;
int main( ){
	string shop, eva;   //商店和Eva的string 
	getline(cin, shop); 
	getline(cin, eva);
	int bead[128] = {0};  //用ASCⅡ码做数组下标 
	int len1 = shop.length();
	int len2 = eva.length();
	int i, less=0;       //less是缺少的数目 
	for(i=0; i<len1; i++){
		char temp = shop[i];
		bead[temp]++;     //计算每个颜色有多少个 
	}
	for(i=0; i<len2; i++){
		char temp = eva[i];
		if(bead[temp]>0){
			bead[temp]--;   //跟Eva的相同，减一
		}
		else less++;    //如果Eva的在shop中找不到，less加一 
	}
	//根据是否缺少，打印不同的结果 
	if(less>0){     
		printf("No %d\n", less);
	}
	else printf("Yes %d\n", len1-len2);
	return 0;
}
