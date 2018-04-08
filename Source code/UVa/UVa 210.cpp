//UVa 210 并行程序模拟 Concurrency Simulator
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1024
#define MAXM 32
#define MAXVAR 26
struct Memory {         //程序命令
    char s[MAXM][MAXM];
    int counter;		
    void read(){		//读取命令函数
        int n = 0;
        while (gets(s[n])) {
            if (s[n][0] == 'e' && s[n][1] == 'n' && s[n][2] == 'd')		//如果读到end则退出读取
                return;
            n++;
        }
    }
} mem[MAXN];
int N, unitTime[5], quantum, locked, var[MAXVAR];//程序数量，运行时间 配额	
deque<int> readyQ, blockQ;					//双向队列
vector<string> decode(string s) {
    vector<string> ret;
    stringstream sin(s);
    while (sin >> s)
        ret.push_back(s);
    return ret;
}
int toInt(string s) {
    int ret;
    stringstream sin(s);
    sin >> ret;
    return ret;
}
void execute(int pid) {
    int q = quantum;				//配额
    while (q > 0) {					//当配额不为0时
        vector<string> args = decode(mem[pid].s[mem[pid].counter]);	
        if (args[0].length() == 1) {			//如果时赋值语句
            var[args[0][0] - 'a'] = toInt(args[2]);		//************将字母用数字的形式存储到var数组中
            q -= unitTime[0];					
        } else if (args[0] == "print") {
            printf("%d: %d\n", pid+1, var[args[1][0] - 'a']);	//输出变量值
            q -= unitTime[1];
        } else if (args[0] == "lock") {
            if (locked) {								//locked不为0，则将程序放入阻止队列
                blockQ.push_back(pid);
                return;
            }
            locked = 1;									//
            q -= unitTime[2];
        } else if (args[0] == "unlock") {				
            locked = 0;						
            if (!blockQ.empty()) {						//如果阻止队列不为空
                readyQ.push_front(blockQ.front());		//则将阻止队列的队首加入到等待队列中
                blockQ.pop_front();						//阻止队列中删除队首
            }
            q -= unitTime[3];
        } else if (args[0] == "end") {					
            return ;								//直接return counter不会增加
        }
        mem[pid].counter++;	
    }
    readyQ.push_back(pid);							//尾部加回程序
}
void run(int N) {							
    for (int i = 0; i < N; i++)						//将程序编号存入readyQ,并将程序counter值设置为0；
        readyQ.push_back(i), mem[i].counter = 0;
    for (int i = 0; i < MAXVAR; i++)				
        var[i] = 0;
    locked = 0;
    int pid;
    while (!readyQ.empty()) {						//当程序队列不为空时
        pid = readyQ.front(), readyQ.pop_front();	//pid读取队列首程序，并移除首程序
        execute(pid);
    }
}
int main() {
    int testcase;   //几组测试
    scanf("%d", &testcase);
    while (testcase--) {
        scanf("%d", &N);    //程序数量
        for (int i = 0; i < 5; i++)
            scanf("%d", &unitTime[i]);  //每种命令的耗时
        scanf("%d", &quantum);      	//配额
        while (getchar() != '\n');  	//读取换行
        for (int i = 0; i < N; i++)     //读取N个程序的命令
            mem[i].read();				//读取每个程序的命令
        
        run(N);						//运行程序 N个程序
        
        if (testcase)				//如果不是最后一行，则输出换行
            puts("");
    }
    return 0;
}
/*

 */
