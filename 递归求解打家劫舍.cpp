# include<cstdio>
# include<vector>
using namespace std;

int _max = 0;
int money = 0;
void Rob(vector<int>& nums,int cur){
    money+=nums[cur];
    if(money>_max)_max = money;
    if(cur+2>nums.size())return;//ÖÕÖ¹Ìõ¼þ
    for(int i = 2; i < 4; i++){
        if(cur+i<nums.size()){
            Rob(nums,cur+i);
            money-=nums[cur+i];
        }
    }
}
int rob(vector<int>& nums) {
    if(nums.size()==1)
        return nums[0];
    Rob(nums,0);
    money = 0;
    Rob(nums,1);
    return _max;
}


int main(){
	vector<int> nums;
	int temp;
	while(scanf("%d",&temp)!=EOF)nums.push_back(temp);
	temp = rob(nums);
	printf("%d",temp);
}