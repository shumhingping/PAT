1043 输出PATest（20 分）
给定一个长度不超过 10的4次方的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：
输入在一行中给出一个长度不超过 10的4次方的、仅由英文字母构成的非空字符串。

输出格式：
在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT

输出样例：
PATestPATestPTetPTePePee

作者: CHEN, Yue
单位: 浙江大学
时间限制: 400ms
内存限制: 64MB
代码长度限制: 16KB

#include<iostream> 
int main( ){
	int map[128]={0}, c;   //因为输入是纯字母，用ASCⅡ码做下标记录每个字母的频率
	while((c = getchar()) != EOF){
		map[c]++;
	}
	while(map['P']>0 || map['A']>0 || map['T']>0 || map['e']>0 || map['s']>0 || map['t']>0){
		if(map['P']-- > 0)	printf("%c", 'P');
		if(map['A']-- > 0)  printf("%c", 'A');
    if(map['T']-- > 0)	printf("%c", 'T');
		if(map['e']-- > 0)	printf("%c", 'e');
		if(map['s']-- > 0)	printf("%c", 's');
		if(map['t']-- > 0)	printf("%c", 't');
	}
	return 0;
}

ps.自己原来写的好长，写完之后看了柳婼大神的，瞬间自惭形秽(╯‵□′)╯︵┻━┻
