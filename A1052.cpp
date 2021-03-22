/*
# include<cstdio>
# include<algorithm>
using namespace std;

const int maxn = 100010;
struct Node{
	int cur;
    int key;
    int next;
    bool flag; // 判断是否在给定的链表上
}node[maxn];

bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
        return a.key < b.key;
}

int main(){
    int num,begin,cur,next,data,i=0;
    scanf("%d%d",&num,&begin);
    for(int j=0;j<maxn;j++){ //初始化
        node[j].key = maxn;
        node[j].flag = false;
    }
    for(int j=0;j<num;j++)
    {
        scanf("%d %d %d",&cur,&data,&next);
        node[cur].cur = cur;
		node[cur].key = data;
        node[cur].next = next;
    }
    if(num==0||begin == -1)
        printf("0 -1");
    else
    {
        for(cur = begin; cur != -1;cur = node[cur].next)
        {   
            node[cur].flag = true;
            i++;//记录有几个在链表上的结点
        }
        sort(node,node+maxn,cmp);
        printf("%d %05d\n",i,node[0].cur);
        for(int j=0;j<i-1;j++)
            printf("%05d %d %05d\n",node[j].cur,node[j].key,node[j+1].cur);
        printf("%05d %d -1",node[i-1].cur,node[i-1].key);
    }
    return 0;
}

*/


# include<cstdio>
# include<algorithm>
using namespace std;
const int maxn = 100005;
struct Node{
	int address, data, next;
	bool flag;
}node[maxn];
bool cmp(Node a, Node b){
    if(a.flag == false || b.flag == false)
        return a.flag > b.flag;
    else
        return a.data < b.data;
}
int main()
{
	for(int i = 0; i < maxn; i++)
		node[i].flag = false;
	int n,begin,address;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address = address;
	}
	int count=0, p=begin;
	while(p!=-1){
		node[p].flag = true;
		count++;
		p = node[p].next;
	}
	if(count == 0||begin==-1)
		printf("0 -1");
	else{
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",count,node[0].address);
		for(int j=0;j<count-1;j++)
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j+1].address);
        printf("%05d %d -1",node[count-1].address,node[count-1].data);
	}
}