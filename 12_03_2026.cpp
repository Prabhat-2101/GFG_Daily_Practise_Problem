//https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1
class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int currFlip = 0, res = 0;
        int size = arr.size();
        vector<int> flip(size,0);
        for(int i=0;i<size;i++){
            if(i>=k) currFlip ^= flip[i-k];
            if(arr[i]^currFlip == 0) {
                if(i+k>size) return -1;
                currFlip ^= 1;
                res += 1;
                flip[i] = 1;
            }
        }
        return res;
    }
};
