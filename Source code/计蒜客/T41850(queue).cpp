#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
char dyna[100010];
int dqueue[100010], pl[100010], head, tail;
int w[110], s[110], n, m;       //面值 数量 
int main ()
{
    int i, j, k, l, maxi, ans;
        scanf("%d %d", &n, &m);
        for (i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for (i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        memset(dyna, 0, sizeof(dyna));
        dyna[0] = 1;
        for (i = 1; i <= n; i++)
        {
            maxi = w[i] * s[i];     //种类最大值
            if (s[i] == 1)          //数量只有一种的情况
            {
                for (j = m; j >= w[i]; j--)
                    dyna[j] = max(dyna[j], dyna[j - w[i]]);
            }
            else if (maxi < m)      //如果金额小
            {
                for (j = 0; j < w[i]; j++)  //枚举b ，组数
                {
                    head = tail = 0;           //队列归零
                    for (k = j; k <= m; k += w[i]) //枚举x
                    {
                        if (tail != head) { if (k - pl[head] > maxi) head++; }
                        if (dyna[k])
                        {
                            dqueue[tail] = dyna[k];
                            pl[tail] = k; tail++;
                        }
                        else if (tail != head) dyna[k] = 1;
                    }
                }
            }
            else
            {
                for (j = w[i]; j <= m; j++)
                    dyna[j] = max(dyna[j], dyna[j - w[i]]);
            }
        }
        ans = 0;
        for (i = 1; i <= m; i++)
            if (dyna[i]) ans++;
        printf("%d\n", ans);
    return 0;
}