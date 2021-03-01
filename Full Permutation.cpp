/*全排列问题，从递归的角度去考虑，把问题描述成“输出1~n个整数的全排列”，就可以被分为若干个子问题：“输出以1开头的全排列”，“输出以2开头的全排列”...“输出以n开头的全排列”
  不妨设定一个数组P用以存放当前排列；再设定一个散列函数hashTable以记录当前数组中整数x是否已经在其中了。
*/

# include<cstdio>
# include<vector>
using namespace std;

//全局变量
int n;
vector<bool> hashTable; //长度不知，因此用vector
vector<int> P;
	
void generateP(int index)//对index位置处数据进行排列
{
	if(index == n+1) //递归边界
	{
		for(int i=1;i<=n;i++)
			printf("%d",P[i]);
		printf(" ");
	}
	for(int i=1;i<=n;i++)//枚举1~n，试图将i填入P[index]
	{
		if(hashTable[i] == false)
		{
			P[index] = i;
			hashTable[i] = true;
			generateP(index + 1);
			hashTable[i] = false; //处理完子问题恢复原状态
		}
	}
}

int main()
{
	printf("请输入排列数:\n");
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		hashTable.push_back(false);
		P.push_back(0);
	}
	generateP(1);
}