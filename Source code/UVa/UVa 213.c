//信息解码 UVa213 
#include <stdio.h>
#include <string.h>

int readchar(){										//读取字符，排除换行符
	for(;;){
		int ch=getchar();
		if(ch!='\n'&&ch!='\r')return ch;
	}
}
int readint(int c){
		int v=0;
		while(c--)
			v=v*2+readchar()-'0';					//读取c位二进制，转化为整型
		return v;
	
}
int code[8][1<<8];
int readcodes(){
	memset(code,0,sizeof(code));
	code[1][0]=readchar();							//从下一行开始读取，如果输入已经结束，会读到EOF
	for(int len=2;len<=7;len++){					//从两位数开始读取
		for(int i=0;i<(1<<len)-1;i++){				//从0开始，到2进制的最大len位-1 ，因为没有全部为1的二进制
			int ch=getchar();						//读取当前字符，
			if(ch=EOF)return 0;						//如果字符为空，则返回0，退出当前循环，后面没有数据了
			if(ch == '\n'||ch == '\r')return 1;		//如果字符为换行，则返回1，退出当前循环，说明后面还有数据
			code[len][i]=ch;						//储存当前字符到指定位置
		}
	}
	return 1;
}

void printcodes(){
	for(int len=1;len<=7;len++)
		for(int i=0;i<(i<<len)-1;i++){
			if(code[len][i]==0)return 0;			//因为memset 所以遇到0时，则结束循环
			printf("code[%d][%d]=%c\n",len,i,code[len][i]);
		}
}

int main(){
		while(readcodes()){
		printcodes();						//调试函数
			for(;;){
				int len=readint(3);
				if(len==0)break;
				
				for(;;){
					int v=readint(len);
					if(v == (1<<len)-1)break;		//如果V的值全部为1的话，则退出循环
					putchar(code[len][v]);						//输出当前编码的字符
					
				}
			}
			printf("\n");
		}
	return 0;
}