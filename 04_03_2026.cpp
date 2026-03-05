//https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1
class Solution {
  public:
    int maxSubarrayXOR(vector<int>& a, int k) {
        int start = 0, max_sum = INT_MIN;
        int n = a.size();
        int sum = 0;
        for(int end=0;end<n;end++){
            sum ^= a[end];
            if(end-start+1==k){
                max_sum = max(max_sum,sum);
                sum ^= a[start];
                start += 1;
            }
        }
        return max_sum;
    }
};
