class Solution {
public:

    int solve(vector<int>&nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        //include
        int includeAns=nums[index]+solve(nums,index+2);
        //exclude
        int excludeAns=0+solve(nums,index+1);
        int finalAns=max(includeAns,excludeAns);
        return finalAns;
    }

    int solveMem(vector<int>&nums,int index,vector<int>&dp)
    {
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        //include
        int includeAns=nums[index]+solveMem(nums,index+2,dp);
        //exclude
        int excludeAns=0+solveMem(nums,index+1,dp);
        dp[index]=max(includeAns,excludeAns);
        return dp[index];
    }

    int solveTab(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n+2,-1);
        dp[n]=0;
        dp[n+1]=0;
        for(int i=n-1;i>=0;i--)
        {
            int include=nums[i]+dp[i+2];
            int exclude=0+dp[i+1];
            dp[i]=max(include,exclude);
        }
        return dp[0];
    }

    int solveTabSO(vector<int>nums)
    {
        int n=nums.size();
        int next1=0;
        int next2=0;
        for(int i=n-1;i>=0;i--)
        {
            int include=nums[i]+next2;
            int exclude=0+next1;
            int curr=max(include,exclude);
            next2=next1;
            next1=curr;
        }
        return next1;
    }

    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
        //int ans=solve(nums,index);
        //return ans;
        //vector<int>dp(n+1,-1);
        //return solveMem(nums,index,dp);
        //return solveTab(nums);
        return solveTabSO(nums);
    }
};