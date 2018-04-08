//象棋 UVa1589
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[12][11];
char s1[12][11];

void Car(int x,int y){
    int i,j;
    
    for(i=x-1;i>0;i--){
        s[i][y]=0;
        if(isalpha(s1[i][y]))
            break;
    }
    
    for(i=x+1;i<11;i++){
        s[i][y]=0;
        if(isalpha(s1[i][y]))
            break;
    }
    
    for(i=y-1;i>0;i--){
        s[x][i]=0;
        if(isalpha(s1[x][i]))
            break;
    }
    for(i=y+1;i<10;i++){
        s[x][i]=0;
        if(isalpha(s1[x][i]))
            break;
    }
}

void Horse(int x,int y){
    
    if(!isalpha(s1[x-1][y])){
        if(x-2>=0&&y-1>=0&&y+1<=10){
            s[x-2][y-1]=0;
            s[x-2][y+1]=0;
        }

    }
    if(!isalpha(s1[x+1][y])){
        if(x+2<=10&&y-1>=0&&y+1<=10){
            s[x+2][y-1]=0;
            s[x+2][y+1]=0;
        }
    }
    if(!isalpha(s1[x][y+1])){
        if(y+2<=10&&x-1>=0&&x+1<=10){
            s[x+1][y+2]=0;
            s[x-1][y+2]=0;
        }
    }
    if(!isalpha(s1[x][y-1])){
        if(x-2>=0&&y-1>=0&&y-1<=10){
            s[x+1][y-2]=0;
            s[x-1][y-2]=0;
        }
    }
}




void Cannon(int x,int y){
    int i,j,n=0;
    for(i=x-1;i>0;i--){
        
        if(n==1)
            s[i][y]=0;
        if(isalpha(s1[i][y])){
            n++;
            if(n==1)
                i--;
        }
        if(n==2)
            break;
    }
    for(i=x+1;i<11;i++){
        
        if(n==1)
            s[i][y]=0;
        if(isalpha(s1[i][y])){
            n++;
            if(n==1)
                i++;
        }
        if(n==2)
            break;
    }
    for(i=y-1;i>0;i--){
        
        if(n==1)
            s[x][i]=0;
        if(isalpha(s1[x][i])){
            n++;
            if(n==1)
                i--;
        }
        if(n==2)
            break;
    }
    for(i=y+1;i<11;i++){
        
        if(n==1)
            s[x][i]=0;
        if(isalpha(s1[x][i])){
            n++;
            if(n==1)
                i++;
        }
        if(n==2)
            break;
    }
}


int main(){
    int n,x,y,cs=0;
    
    while(scanf("%d%d%d",&n,&x,&y)==3&&n){
        getchar();
        memset(s,0,sizeof(s));
        memset(s1,'0',sizeof(s1));
        for(int i=1;i<4;i++)
            for(int j=4;j<7;j++)
                s[i][j]=1;
        

        while(n--){
            char a;
            int i,j;
            scanf("%c%d%d",&a,&i,&j);
            s1[i][j]=a;
            getchar();
            //printf("%c%d%d ",a,i,j);
        }
        //printf("\n");
        for(int i=0;i<11;i++){
            for(int j=0;j<10;j++)
                printf("%c ",s1[i][j]);
            printf("\n");
        }
        //printf("\n");
        for(int i=1;i<11;i++)
            for(int j=1;j<10;j++)
            {
                if(isalpha(s1[i][j]))
                //printf("%d %d\n",i,j);
                switch(s1[i][j]){
                    case 'G':
                    case 'R':
                        Car(i,j);
                 //       printf("1 ");
                 //       cs++;
                        break;
                    case 'H':
                        Horse(i,j);
                 //       printf("1 ");
                 //       cs++;
                        break;
                    case 'C':
                        Cannon(i,j);
                        //printf("1 ");
                        //cs++;
                        break;
                }
                //if(cs==7)
                 //   printf("\n");
            }
        printf("\n");
         for(int i=1;i<11;i++){
            for(int j=1;j<10;j++)
                printf("%d ",s[i][j]);
            printf("\n");
        }
        
        if(s[x-1][y]==1||s[x+1][y]==1||s[x][y-1]==1||s[x][y+1]==1)
            printf("NO\n");
        else 
            printf("YES\n");
    }
    return 0;
}