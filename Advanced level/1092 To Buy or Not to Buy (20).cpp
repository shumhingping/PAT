1092 To Buy or Not to Buy (20)（20 分）
Eva would like to make a string of beads with her favorite colors so she went to a small shop to buy some beads. There were many colorful strings of beads. However the owner of the shop would only sell the strings in whole pieces. Hence Eva must check whether a string in the shop contains all the beads she needs. She now comes to you for help: if the answer is "Yes", please tell her the number of extra beads she has to buy; or if the answer is "No", please tell her the number of beads missing from the string.
For the sake of simplicity, let's use the characters in the ranges [0-9], [a-z], and [A-Z] to represent the colors. For example, the 3rd string in Figure 1 is the one that Eva would like to make. Then the 1st string is okay since it contains all the necessary beads with 8 extra ones; yet the 2nd one is not since there is no black bead and one less red bead.

Input Specification:
Each input file contains one test case. Each case gives in two lines the strings of no more than 1000 beads which belong to the shop owner and Eva, respectively.

Output Specification:
For each test case, print your answer in one line. If the answer is "Yes", then also output the number of extra beads Eva has to buy; or if the answer is "No", then also output the number of beads missing from the string. There must be exactly 1 space between the answer and the number.

Sample Input 1:
ppRYYGrrYBR2258
YrR8RrY

Sample Output 1:
Yes 8

Sample Input 2:
ppRYYGrrYB225
YrR8RrY

Sample Output 2:
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
