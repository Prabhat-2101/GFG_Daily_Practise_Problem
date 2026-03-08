//https://www.geeksforgeeks.org/problems/dice-throw5349/1
class Solution {
  public:
    vector<vector<int>> dp;
    int helper(int m,int n,int x){
        if(n==0 and x==0) return 1;
        if(n<=0 or x<=0) return 0;
        if(dp[n][x] != -1) return dp[n][x];
        int count = 0;
        for(int i=1;i<=m;i++){
            count += helper(m,n-1,x-i);
        }
        return dp[n][x] = count;
    }
    int noOfWays(int m, int n, int x) {
        dp.resize(n+1,vector<int>(x+1,-1));
        return helper(m,n,x);
    }
};
