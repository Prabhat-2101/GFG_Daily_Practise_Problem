// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, max_ = INT_MIN, zero = 0;
        int size = arr.size();
        for(int right=0;right<size;right++){
            if(arr[right] == 0) {
                zero += 1;
            }
            while(zero > k) {
                if(arr[left] == 0) 
                    zero -= 1;
                left += 1;
            }
            max_ = max(max_, right - left + 1);
        }
        return max_;
    }
};
