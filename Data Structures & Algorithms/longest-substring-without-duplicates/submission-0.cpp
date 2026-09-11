class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int start=0;
        int ans=0;
        for(int end=0;end<s.length();end++)
        {
            while(st.find(s[end])!= st.end())
            {
                st.erase(s[start]);
                start++;
            }
            st.insert(s[end]);
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};