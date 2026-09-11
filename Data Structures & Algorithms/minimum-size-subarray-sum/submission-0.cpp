class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        long long sum=0;
        int ans=INT_MAX;
        for(int end=0;end<nums.size();end++)
        {
            sum+=nums[end];
            while(sum>=target)
            {
                ans=min(ans,end-start+1);
                sum-=nums[start];
                start++;
            }
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return ans;

    }
};