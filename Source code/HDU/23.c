#include<stdio.h>  
#include<string.h>  
double student[55],subject[9];  
double score[55][9];//二维数组，每行存的每个学生的分数，每列为每门课的分数   
int main()  
{  
    int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
            for(int j=0;j<m;j++)  
                scanf("%lf",&score[i][j]);  
        double sumstu,sumsub;  
        for(int i=0;i<n;i++)  
        {  
            sumstu=sumsub=0;  
            for(int j=0;j<m;j++)  
            {  
                sumstu+=score[i][j];//每个学生的总分   
//              sumsub+=score[j][i];  
            }  
            student[i]=sumstu/m;//每个学生的平均分   
//          subject[i]=sumsub/(n*1.0);  
        }  
        for(int i=0;i<m;i++)  
        {  
            sumsub=0;  
            for(int j=0;j<n;j++)  
                sumsub+=score[j][i];//每门课总分   
            subject[i]=sumsub/n;//每门课平均分   
        }  
        int sum=0,flag;  
        for(int i=0;i<n;i++)  
        {  
            flag=0;  
            for(int j=0;j<m;j++)  
            {                 
                if(score[i][j]<subject[j])//若有一门分数小于该科目平均分，则不满足   
                {  
                    flag=1;  
                    break;  
                }  
            }  
            if(flag==0)  
                sum++;  
        }  
        for(int i=0;i<n-1;i++)  
            printf("%.2lf ",student[i]);  
        printf("%.2lf\n",student[n-1]);  
        for(int i=0;i<m-1;i++)  
            printf("%.2lf ",subject[i]);  
        printf("%.2lf\n",subject[m-1]);  
        printf("%d\n\n",sum);  
    }  
    return 0;  
}  