class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int> res;
        sort(arr.begin(),arr.end());
        for(int i=low;i<=high;i++){
            if(binary_search(arr.begin(),arr.end(),i)) 
                continue;
            res.push_back(i);
        }
        return res;
    }
};
