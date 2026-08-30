class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxArea=0;
        while(left<right)
        {
            int currentArea=min(heights[left],heights[right])*(right-left);
            maxArea=max(maxArea,currentArea);
            if(heights[left]<heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};
