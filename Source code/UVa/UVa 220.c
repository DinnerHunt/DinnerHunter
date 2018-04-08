#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char mp[10][10];//储存棋局
int f[2][10][10];//标记黑白子可执行合法操作的点
int dx[] = {-1,-1,-1, 1,1,1,0, 0};//八个方向
int dy[] = {-1, 0, 1,-1,0,1,1,-1};

void is(int a, char b, int x, int y)//判断是否可以落子
{
    for(int k=0;k<8;k++)                    //8个方向以此枚举
    {
        int tx = x+dx[k];                   
        int ty = y+dy[k];
        int num = 0;          //能夹子的数量
        while(tx>=0 && ty>=0                //如果在棋盘范围内并且是对方子
              && tx<8 && ty<8
              && mp[tx][ty] == b)
        {
            tx += dx[k];
            ty += dy[k];
            ++num;
        }
        if(num>=1 && mp[tx][ty] == '-')     //如果能夹子，并且最后有位置落子，则可以落子，并保存方向
            f[a][tx][ty] |= 1<<k;
            //利用位运算同时保存k即方向，便于后面落子时直接定向翻转。
    }
}

void init()//获得黑白子可执行操作的点
{
    for(int i=0;i<8;i++)                            //枚举整个棋盘
        for(int j=0;j<8;j++)
            if(mp[i][j] == 'W')                     //如果有该点有子，则枚举该子能否有落子点与其夹对方子
                is(0, 'B', i, j);                   
            else if(mp[i][j] == 'B')
                is(1, 'W', i, j);
}

bool print(bool isprint, int p)
//p为当前操作者，isprint表示是否输出，便于将此函数输出查询两用
{
    bool flag = false;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(f[p][i][j])              //判断是否可以落子
            {
                if(flag && isprint)     //判断是否需要输出，
                    cout<<" ";
                flag = true;    
                if(isprint)
                    cout<<'('<<i+1<<','<<j+1<<")";
                else                    //如果不需要输出，则直接返回可以落子
                    return flag;
            }
    if(isprint)                 
    {
        if(flag)
            cout<<endl;
        else
            cout<<"No legal move."<<endl;   //如果无子可落，则返回
    }
    return flag;
}

void move(int x, int y, int p)
{
    char ch;
    if(p == 0)
        ch = 'W';
    else
        ch = 'B';
    mp[x][y] = ch;          //落子点
    for(int i=0;i<8;i++)
    {
        if(f[p][x][y] & 1<<i)
        {
            int tx = x-dx[i];   //朝方向的逆向回去，
            int ty = y-dy[i];
            while(tx>=0 && ty>=0
                  && tx<8 && ty<8
                  && mp[tx][ty] != ch)      //如果在棋盘范围内，并且不碰到自己
            {               
                mp[tx][ty] = ch;        //将对方的字转为自己的子
                tx -= dx[i];
                ty -= dy[i];
            }
        }
    }
}

int main()
{
    int n;                  //几轮数据
    cin>>n;
    while(n--)
    {
        memset(mp, 0, sizeof(mp));              //格式化棋盘，新的一轮
        for(int i=0;i<8;i++)                    //每行读取数组mp
            cin>>mp[i];
        char ch[5];int p;  
        cin>>ch;                                //读取颜色，并用int p来存储
        if(ch[0] == 'W')
            p = 0;
        else
            p = 1;
        while(ch[0] != 'Q')
        {
            memset(f, 0, sizeof(f));            //格式化操作合法落子点
            init();                             //执行判断落子点
            cin>>ch;
            if(ch[0] == 'L')            //如果是查询，
                print(true, p);         //则输出P方的可落子点  
            else if(ch[0] == 'M')           //如果是落子
            {
                if(!print(false, p))        //判断当前方有无子可落 ，诺没有则交换玩家
                    p ^= 1;
                move(ch[1]-'0'-1, ch[2]-'0'-1, p);  //落子
                p ^= 1; //交换玩家
                int wnum = 0;
                int bnum = 0;
                for(int i=0;i<8;i++)            //输出各个方的子的数量
                    for(int j=0;j<8;j++)
                    {
                        if(mp[i][j] == 'W')
                            ++wnum;
                        if(mp[i][j] == 'B')
                            ++bnum;
                    }
                printf("Black - %2d White - %2d\n", bnum, wnum);
            }
        }
        for(int i=0;i<8;i++)        //输出棋盘
            cout<<mp[i]<<endl;
        if(n != 0)
            cout<<endl;
    }
    return 0;
}