//https://www.geeksforgeeks.org/problems/rotation4723/1
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int size = arr.size();
        int idx = 0;
        while(idx < size-1){
            if(arr[idx] > arr[idx+1]){
                return idx+1;
            }
            idx += 1;
        } 
        return 0;
    }
};
