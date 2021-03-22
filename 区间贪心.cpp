# include<cstdio>
# include<algorithm>
# include<vector>
using namespace std;

struct section
{
	int begin,end;
	section(int _begin, int _end):begin(_begin),end(_end){}
};

bool cmp(section a, section b){
	if(a.begin!=b.begin)
		return a.begin<b.begin;
	else
		return a.end>b.end;
}
int main()
{
	int i=0,num,temp_b,temp_e,last_end;
	vector<section> aSet;
	vector<section> result;
	scanf("%d",&num);
	while(i++<num){
		scanf("%d %d",&temp_b,&temp_e);
		section temp_s = section(temp_b,temp_e);
		aSet.push_back(temp_s);
	}
	sort(aSet.begin(),aSet.end(),cmp); //从小到大排序
	for(int i=0;i<aSet.size()-1;i++){
		if(aSet[i].end>aSet[i+1].end)
			aSet.erase(aSet.begin()+i);
	}
	result.push_back(aSet[0]);
	last_end = aSet[0].end;
	for(int i=1;i<aSet.size();i++){
		if(aSet[i].begin>=last_end){
			result.push_back(aSet[i]);
			last_end = aSet[i].end;
		}
	}
	for(vector<section>::iterator it = result.begin();it!=result.end();it++)
		printf("(%d,%d) ",(*it).begin,(*it).end);
}
