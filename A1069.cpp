# include<cstdio>
# include<algorithm>
using namespace std;

void to_array(int n,int num[]){
	for(int i=0;i<4;i++){
		num[i] = n%10;
		n/=10;
	}
}

int to_int(int num[]){
    int sum = 0;
    for(int i=0;i<4;i++)
		sum = sum*10+num[i];
	return sum;
}

bool cmp(char a, char b)//降序
{
	return a>b;
}

void main()
{
    int MAX,MIN,num;
    int temp_num[4];
    scanf("%d",&num);
    while(num!=6174&&num!=0){
        to_array(num,temp_num);
        sort(temp_num,temp_num+4);//默认升序，获得最小值
		MIN = to_int(temp_num);
		sort(temp_num,temp_num+4, cmp);//降序，获得最大值
		MAX = to_int(temp_num);
		num = MAX - MIN;
		printf("%04d - %04d = %04d",MAX,MIN,num);
		if(num!=6174&&num!=0)
			printf("\n");
    }
}