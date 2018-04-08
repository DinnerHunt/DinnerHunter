#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;


int main()
{
    freopen("rand.in", "w", stdout);
    srand(unsigned(time(0)));
    int maxn = 6, count = 0;
    int dir[11][10];
    const char s0[] = "RRCCHH";
    for (int s = (1<<maxn) - 1; s >= 1; s--)
        for (int num = 1000; num; num--)
        {
            memset(dir, 0, sizeof(dir));
            int n = 0, is = 0;
            int r0 = 1 + rand() % 3, c0 = 4 + rand() % 3;
            dir[r0][c0] = 1;
            int r1 = 8 + rand() % 3, c1 = 4 + rand() % 3;
            while (c0 == c1)
                c1 = 4 + rand() % 3;
            dir[r1][c1] = 1;
            for (int i = 0; i < maxn; i++)
                if (s & (1<<i))
                    n++;
            printf("\n%d %d %d\nG %d %d\n",n + 1, r0, c0, r1, c1);
            count++;
            for (int i = 0; i < maxn; i++)
            if (s & (1<<i))
            {
                int r = 1 + rand() % 10, c = 1 + rand() % 9; 
                if (is == 0 && s0[i] != 'C')
                {
                    if (s0[i] != 'H')
                    {
                        r = r0 + 1;
                        c = c0;
                        
                    }
                    else
                    {
                        r = r0 + 2;
                        c = c0 + 1;
                        
                    }
                    is = 1;
            }
            else
            {
                while (dir[r][c])
                {
                    r = 1 + rand() % 10;
                    c = 1 + rand() % 9;
                }
                
            }
            dir[r][c] = 1;
            printf("%c %d %d\n", s0[i], r, c);
        }
    }
    printf("0 0 0\n");
    return 0;
}