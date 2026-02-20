class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int res = INT_MAX;
        int n = a.size();
        for(int i=0;i<=n-m;i++){
            res = min(res,a[i+m-1]-a[i]);
        }
        return res;
    }
};
