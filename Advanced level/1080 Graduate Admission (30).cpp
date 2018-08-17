1080 Graduate Admission (30)（30 分）
It is said that in 2013, there were about 100 graduate schools ready to proceed over 40,000 applications in Zhejiang Province. It would help a lot if you could write a program to automate the admission procedure.
Each applicant will have to provide two grades: the national entrance exam grade G~E~, and the interview grade G~I~. The final grade of an applicant is (G~E~ + G~I~) / 2. The admission rules are:
The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade G~E~. If still tied, their ranks must be the same.
Each applicant may have K choices and the admission will be done according to his/her choices: if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.

Input Specification:
Each input file contains one test case. Each case starts with a line containing three positive integers: N (<=40,000), the total number of applicants; M (<=100), the total number of graduate schools; and K (<=5), the number of choices an applicant may have.
In the next line, separated by a space, there are M positive integers. The i-th integer is the quota of the i-th graduate school respectively.
Then N lines follow, each contains 2+K integers separated by a space. The first 2 integers are the applicant's G~E~ and G~I~, respectively. The next K integers represent the preferred schools. For the sake of simplicity, we assume that the schools are numbered from 0 to M-1, and the applicants are numbered from 0 to N-1.

Output Specification:
For each test case you should output the admission results for all the graduate schools. The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.

Sample Input:
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4

Sample Output:
0 10
3
5 6 7
2 8

1 4
作者: CHEN, Yue
单位: PAT联盟
时间限制: 200ms
内存限制: 64MB
代码长度限制: 16KB

注意点：
1.最后输出时，要按照学生的id大小输出，而前面排学生rank的时候把学生id打乱了，因此要再排一次序

//AC代码
#include<cstdio> 
#include<algorithm>
using namespace std;
struct student{
	int stuid;          //学生id 
	int ge, gi, sum;    //学生初试成绩、面试成绩、成绩总和 
	int rank;           //学生排名
	int choice[6] ;     //K个选择的编号 
}stu[40010];
struct school{
	int quota;          //录取总人数
	int stunum;         //已招收人数 
	int last;           //最后一个考生的编号
	int id[40010];      //已招收学生编号 
}sch[110];
bool cmp1(student a, student b){    //用于学生rank排序 
	if(a.sum!=b.sum) return a.sum>b.sum;
	else return a.ge>b.ge;
}
bool cmp2(int a, int b) {
	return a<b;   //最后输出要按照学生id顺序 
}
int main( ) {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<m; i++){
		scanf("%d", &sch[i].quota);
		sch[i].stunum = 0;    //初始化已录取人数为0
		sch[i].last = -1;     //初始化最后一个学生id为-1
	}
	for(int i=0; i<n; i++) {
		scanf("%d %d", &stu[i].ge, &stu[i].gi); //读入学生初试成绩面试成绩
		stu[i].sum = stu[i].ge + stu[i].gi;     //计算学生总分
		stu[i].stuid = i;
		for(int j=0; j<k; j++) {
			scanf("%d", &stu[i].choice[j]);     //读入学生选择的志愿学校 
		}
	}	
	
	sort(stu, stu+n, cmp1) ;
	stu[0].rank = 0;           //排好学生的rank 
	for(int i=1; i<n; i++){
		if(stu[i].sum==stu[i-1].sum && stu[i].ge==stu[i-1].ge){
			stu[i].rank = stu[i-1].rank;
		}
		else stu[i].rank = i;
	}

	for(int i=0; i<n; i++){   //每个学生判断其录取学校 
		for(int j=0; j<k; j++){
			int choice = stu[i].choice[j]; //学生志愿学校 
			int num = sch[choice].stunum;  //已录取学生人数 
			int last = sch[choice].last;   //该学校录取最后一名学生id 
			if(num < sch[choice].quota || (stu[i].rank==stu[last].rank && last!=-1) ){
			//如果该学生志愿学校没招满，或者该学生rank与志愿学校的最后一名相同，录取 
				sch[choice].id[num] = stu[i].stuid; 
				sch[choice].stunum++;
				sch[choice].last = i;  //last是现在排序的下标，不是stu[i].stuid 
				break;  //一旦被某个学校录取，马上break，不然后面的学校也可能会录到该学生 
			}
		} 
	}
	for(int i=0; i<m; i++) {  
		int flag=0;  //用于整理格式，输出空格 
		if(sch[i].stunum>0){  //如果有录取到学生 
			sort(sch[i].id, sch[i].id+sch[i].stunum, cmp2);  //按照学生id大小排序 
			for(int j=0; j<sch[i].stunum; j++){
				if(flag==0) {
					flag=1;
				}
				else{
					printf(" ");
				}
				printf("%d", sch[i].id[j]); 
			}	
		}
		printf("\n"); //没有录取到学生也要空一行 
	}
	return 0;
}
