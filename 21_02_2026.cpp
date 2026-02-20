//https://www.geeksforgeeks.org/problems/find-h-index--165609/1
class Solution {
  public:
    int hIndex(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int size = arr.size();
        auto find_count = [&](int mid){
            int idx = 0;
            while(arr[idx]<mid) idx += 1;
            return size - idx;
        };
        int low = 0, high = arr[size-1];
        int res = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            int count = find_count(mid);
            if(count>=mid){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return res;
    }
};
