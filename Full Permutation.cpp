/*ȫ�������⣬�ӵݹ�ĽǶ�ȥ���ǣ������������ɡ����1~n��������ȫ���С����Ϳ��Ա���Ϊ���ɸ������⣺�������1��ͷ��ȫ���С����������2��ͷ��ȫ���С�...�������n��ͷ��ȫ���С�
  �����趨һ������P���Դ�ŵ�ǰ���У����趨һ��ɢ�к���hashTable�Լ�¼��ǰ����������x�Ƿ��Ѿ��������ˡ�
*/

# include<cstdio>
# include<vector>
using namespace std;

//ȫ�ֱ���
int n;
vector<bool> hashTable; //���Ȳ�֪�������vector
vector<int> P;
	
void generateP(int index)//��indexλ�ô����ݽ�������
{
	if(index == n+1) //�ݹ�߽�
	{
		for(int i=1;i<=n;i++)
			printf("%d",P[i]);
		printf(" ");
	}
	for(int i=1;i<=n;i++)//ö��1~n����ͼ��i����P[index]
	{
		if(hashTable[i] == false)
		{
			P[index] = i;
			hashTable[i] = true;
			generateP(index + 1);
			hashTable[i] = false; //������������ָ�ԭ״̬
		}
	}
}

int main()
{
	printf("������������:\n");
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		hashTable.push_back(false);
		P.push_back(0);
	}
	generateP(1);
}