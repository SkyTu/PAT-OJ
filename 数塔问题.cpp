# include<cstdio>
# include<algorithm>
using namespace std;
const int maxn= 1000;

int f[maxn][maxn], dp[maxn][maxn];
int n;
int getMax(int row, int col){
	if(row==n)//到最后一层了
	{
		dp[row][col] = f[row][col];
		return dp[row][col];
	}
	else if(dp[row+1][col*2-1]!=-1&&dp[row+1][col*2]!=-1)
		dp[row][col] = max(dp[row+1][col*2-1],dp[row+1][col*2])+f[row][col];
	else
		dp[row][col] = max(getMax(row+1,col*2-1),getMax(row+1,col*2))+f[row][col];
	return dp[row][col];
}
int main(){	
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){ // 赋值
		for(int j = 1; j <= i; j++)
		{
			scanf("%d",&f[i][j]);
			dp[i][j] = -1;
		}
	}
	int max = getMax(1,1);
	printf("%d",max);
}
