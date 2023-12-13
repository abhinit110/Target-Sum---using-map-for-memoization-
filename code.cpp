class Solution {
public:
    int solve(vector<int>& nums, int target,int i,map<pair<int,int>,int>&dp)
    {
        if(i==0)
        {
            if(target==0 && nums[i]==0)return 2;
            if((target==-1*nums[i]||target==nums[i]))
            return 1;
            else
            return 0;
        }
        if(dp[{i,target}])
        return dp[{i,target}];
        return dp[{i,target}]=solve(nums,target-nums[i],i-1,dp)
        +solve(nums,target+nums[i],i-1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>dp;
        int n=nums.size();
        int res=solve(nums,target,n-1,dp);
        return res;
    }
};
