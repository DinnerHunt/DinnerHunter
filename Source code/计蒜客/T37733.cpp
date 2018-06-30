#include <cstdio>
using namespace std;
struct mat{
	double a[100][100];
};
mat matrix_mul(mat A,mat B)
{
	mat C;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			C.a[i][j] = 0;
			for(int k=0;k<n;++k)
				C.a[i][j] += A.a[i][k]*B.a[k][j];
		}
}
mat unit()
{
	mat res;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++i)
			if(i == j)
				res.a[i][j] = 1;
			else 
				res.a[i][j] = 0;
}
int main(){
	
	return 0;
}