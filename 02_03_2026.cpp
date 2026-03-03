// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int size = arr.size();
        vector<int> left(size,0), right(size,0);
        for(int i=0;i<size;i++){
            if(i==0) 
                left[i] = arr[i];
            else
                left[i] = max(left[i-1],arr[i]);
        }
        for(int i=size-1;i>=0;i--) {
            if(i==size-1)
                right[i] = arr[i];
            else
                right[i] = max(right[i+1],arr[i]);
        }
        int water = 0;
        for(int i=0;i<size;i++) {
            water += min(left[i],right[i]) - arr[i];
        }
        return water;
    }
};
