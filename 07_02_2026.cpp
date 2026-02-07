//https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int size = arr.size();
        int total_sum = 0, curr_val = 0;
        for(int i=0;i<size;i++) {
            total_sum += arr[i];
            curr_val += i*arr[i];
        }
        int max_sum = curr_val;
        for(int i=1;i<size;i++){
            curr_val = curr_val + total_sum - (size*arr[size-i]);
            max_sum = max(max_sum,curr_val);
        }
        return max_sum;
    }
};
