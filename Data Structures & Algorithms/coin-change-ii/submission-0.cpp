class Solution {
public:
    int solveRec(vector<int>&coins ,int n,int sum)
    {
        if(sum==0) return 1;
        if(sum<0) return 0;
        if(n==0) return 0;

        int exclude=solveRec(coins,n-1,sum);
        int include=solveRec(coins,n,sum-coins[n-1]);
        return exclude + include;
    }
    int solveMem(vector<int>&coins,int n,int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return 1;
        if(sum<0) return 0;
        if(n==0) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];


        int exclude=solveMem(coins,n-1,sum,dp);
        int include=solveMem(coins,n,sum-coins[n-1],dp);
        dp[n][sum] = exclude + include;
        return dp[n][sum];

    }

    int solveTab(vector<int>&coins,int n,int sum)
    {
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                //exclude 
                long long int exclude=dp[i-1][j];
                long long int include=0;
                //include only if coin value<=current sum
                if(coins[i-1]<=j)
                {
                    include=dp[i][j-coins[i-1]];
                }
                dp[i][j]=exclude+include;
            }
        }
        return dp[n][sum];

    }


    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //return solveRec(coins,n,amount);
        //vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        //return solveMem(coins,n,amount,dp);
        return solveTab(coins,n,amount);

    }
};