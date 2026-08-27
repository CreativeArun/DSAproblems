class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=2;
        for(int i=2;i<n;i++)
        {
            if(nums[j-2]!=nums[i])
            {
                nums[j]=nums[i];
                j++;
            }
            
        }
        return j;
    }
};