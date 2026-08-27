class Solution {
public:
    bool isValidCharacter(char ch)
    {
        if(ch>='0'&& ch<='9')
        {
            return true;
        }
        if(ch>='a'&& ch<='z')
        {
            return true;
        }
        if(ch>='A'&& ch<='Z')
        {
            return true;
        }
        return false;
    }
    string normaliseString(string &s)
    {
        string newStr="";
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(isValidCharacter(ch))
            {
                if(ch>='A'&& ch<='Z')
                {
                    ch=ch-'A'+'a';
                }
                newStr.push_back(ch);
            }
        }
        return newStr;
    }
    bool isPalindrome(string s) {
        string newStr=normaliseString(s);
        int n=newStr.length();
        for(int i=0;i<n/2;i++)
        {
            if(newStr[i]!=newStr[n-i-1])
            return false;
        }
        return true;
    }
};
