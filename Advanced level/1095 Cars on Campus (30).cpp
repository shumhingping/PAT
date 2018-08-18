1095 Cars on Campus (30)（30 分）
Zhejiang University has 6 campuses and a lot of gates. From each gate we can collect the in/out times and the plate numbers of the cars crossing the gate. Now with all the information available, you are supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that have parked for the longest time period.

Input Specification:
Each input file contains one test case. Each case starts with two positive integers N (<= 10000), the number of records, and K (<= 80000) the number of queries. Then N lines follow, each gives a record in the format
plate_number hh:mm:ss status
where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.
Note that all times will be within a single day. Each "in" record is paired with the chronologically next record for the same car provided it is an "out" record. Any "in" records that are not paired with an "out" record are ignored, as are "out" records not paired with an "in" record. It is guaranteed that at least one car is well paired in the input, and no car is both "in" and "out" at the same moment. Times are recorded using a 24-hour clock.
Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are given in ascending order of the times.

Output Specification:
For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.

Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00

Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09

作者: CHEN, Yue
单位: PAT联盟
时间限制: 220ms
内存限制: 64MB
代码长度限制: 16KB

//AC代码
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define max 10010   //最大记录数 
struct car{
	char plate[10];  //车牌号 
	int time;        //时间，转换成秒 
	char status[4];  //出、入状态 
}all[max], valid[max];
//将时间转换成秒的函数 
int timetrans(int hh, int mm, int ss){  
	int time = hh*3600 + mm*60 + ss;
	return time;
}
//按车牌的字典序将车辆排序，如果是同一辆车的按时间顺序排序  
bool cmp1(car a, car b) {
	if(strcmp(a.plate, b.plate)!=0) return strcmp(a.plate, b.plate)<0;     
	else return a.time<b.time;       
}
//按时间从小到大排序 
bool cmp2(car a, car b) {
	return a.time<b.time;   
}
int main( ) {
	int n, k;   //记录数，查询数
	scanf("%d%d", &n, &k) ;
	int hh, mm, ss;
	//读入记录数据，将时间转换成秒 
	for(int i=0; i<n; i++){   
		scanf("%s %d:%d:%d %s", all[i].plate, &hh, &mm, &ss, all[i].status);
		all[i].time = timetrans(hh, mm, ss);
	}
	sort(all, all+n, cmp1) ;  //按车牌和时间排序 
	int validnum = 0;         //有效数据个数 
	map<string, int>staytime; //车牌号->总停留时间 
	for(int i=0; i<n; i++){
		staytime[all[i].plate] = 0;  //初始化总停留时间为0 
	}
	int parktime;             //本次停留时间 
	int maxtime = 0;         //最大总停留时间 
	//将有效数据记入valid数组并计算总停留时间 
	for(int i=0; i<n; i++) {  
		if(strcmp(all[i].plate, all[i+1].plate)==0 && strcmp(all[i].status, "in")==0 && strcmp(all[i+1].status, "out")==0){
			//如果两相邻数据车牌号相同，且in、out匹配，则该组数据有效
			valid[validnum++] = all[i];       
			valid[validnum++] = all[i+1];
			parktime = all[i+1].time - all[i].time;   //此次停留时间 
			staytime[all[i].plate] += parktime;         //总停留时间 
			if(staytime[all[i].plate]>=maxtime) {
				maxtime = staytime[all[i].plate];       //更新最大停留时间 
			}
		}
	}
	sort(valid, valid+validnum, cmp2);   //按时间顺序排序
	int cnt = 0;  //该时间车辆数量 
	int j=0;    
	//输出每个query时间的车辆数           
	for(int i=0; i<k; i++) {
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int query = timetrans(hh, mm, ss);
		for( ; j<validnum && valid[j].time<=query; j++){   //遍历query时间前的valid数组 
			if(!strcmp(valid[j].status, "in")) {          //因为query时间是有顺序的，所以不要从j=0开始遍历，从上一次的j开始遍历，累加到上一次的cnt上即可 
			    cnt++;              				      //如果又从j=0开始，会有几个测试点超时 
			}          
			else cnt--;                 //如果有车进来，cnt+1，如果有车出去，cnt-1 
		}
		printf("%d\n", cnt);
	}
	//输出所有最长总停留时间的车牌号 
	for(map<string, int>::iterator it = staytime.begin(); it!=staytime.end(); it++){
		if(it->second == maxtime){
			printf("%s ", it->first.c_str());
		}
	}
	//输出总停留时间 
	printf("%02d:%02d:%02d\n", maxtime/3600, maxtime%3600/60, maxtime%60);
	return 0;
}
