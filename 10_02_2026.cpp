//https://www.geeksforgeeks.org/problems/koko-eating-bananas/1
class Solution {
  public:
    bool can_finish(int limit, vector<int>& arr, int k){
        for(int it: arr){
            k -= ceil(it/(limit*1.0));
        }
        return k >= 0;
    }
    int kokoEat(vector<int>& arr, int k) {
        int size = arr.size();
        int min_ = 1, max_ = *max_element(arr.begin(),arr.end());
        int limit = 0;
        while(min_ <= max_){
            int mid = min_ + (max_ - min_)/2;
            if(can_finish(mid,arr,k)) {
                max_ = mid - 1;
                limit = mid;
            }else{
                min_ = mid + 1;
            }
        }
        return limit;
    }
};
