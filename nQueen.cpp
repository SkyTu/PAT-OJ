# include<cstdio>
# include<vector>
# include<cmath>
using namespace std;

int n,solution=0;
vector<bool> hashTable;
vector<int> P;


void generateP(int index){
	if(index==n+1){
		bool flag = true;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(j-i==abs(P[j]-P[i])) //如果在对角线上
					flag = false;
			}
		}
		if(flag){
			solution++;
			for(int i=1;i<=n;i++){ //可视化solution
				for(int j=1; j<P[i];j++)
					printf("0");
				printf("1");
				for(int j=0; j<n-P[i];j++)
					printf("0");
				printf("\n");
			}
			printf("\n");
		}
	}
	for(int i=1;i<=n;i++){
		if(!hashTable[i])
		{
			P[index]=i;
			hashTable[i]=true;
			generateP(index+1);
			hashTable[i]=false;
		}
	}
	return;
}

int main(){
	printf("请输入n皇后中的n：\n");
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		hashTable.push_back(false);
		P.push_back(0);
	}
	generateP(1);
	printf("共有解法%d种",solution);
}