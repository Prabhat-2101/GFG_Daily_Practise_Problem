// https://www.geeksforgeeks.org/problems/buy-stock-2/1
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int mp = 0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>=buy) {
                mp = max(mp,prices[i]-buy);
            }else{
                buy = prices[i];
            }
        }
        return mp;
    }
};
