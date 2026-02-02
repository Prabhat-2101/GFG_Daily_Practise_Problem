class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int max_pos = INT_MIN;
        int curr = 0, total_sum = 0;
        for(int it: arr) {
            curr += it;
            max_pos = max(curr,max_pos);
            if(curr<0) {
                curr = 0;
            }
            total_sum += it;
        }
        curr = 0;
        int min_neg = INT_MAX;
        for(int it: arr) {
            curr += it;
            min_neg = min(curr,min_neg);
            if(curr>0){
                curr = 0;
            }
        }
        if(min_neg==total_sum) {
            return max_pos;
        }
        return max(total_sum - min_neg,max_pos);
    }
};
