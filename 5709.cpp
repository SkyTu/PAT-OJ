#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int maxAscendingSum(vector<int>& nums) {
    vector<int> sum;
    int temp_sum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i]>nums[i-1])temp_sum+=nums[i];
        else{
            sum.push_back(temp_sum);
            temp_sum = nums[i];
        }
    }
	sum.push_back(temp_sum);
    sort(sum.begin(),sum.end());
    return(sum[sum.size()-1]);
}

int main()
{
	vector<int> nums;
	int temp;
	while(cin>>temp)nums.push_back(temp);
	int max = maxAscendingSum(nums);
	cout<<max;
}